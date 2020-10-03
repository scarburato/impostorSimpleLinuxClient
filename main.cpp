#include <iostream>
#include <fstream>
#include <unistd.h>

#include<netdb.h>
#include<arpa/inet.h>

int main(int argc, char **argv)
{
	std::string fileName = "/sdcard/Android/data/com.innersloth.spacemafia/files/regionInfo.dat";
	std::string serverAddress = "localhost";
	uint16_t port = 22023;
	std::ofstream file;
	int option = -1;
	uint32_t zero32 = 0;
	uint32_t serverLen = 1;
	uint8_t strLen;
	
	hostent *he = nullptr;
	std::string ipAddress;
	
	do
	{
		option = getopt(argc, argv, "s:p:o:");
		
		switch(option)
		{
		case 's':
			serverAddress = optarg;
			break;
		case 'p':
			port = std::stoi(optarg);
			break;
		case 'o':
			fileName = optarg;
			break;
		}
	}
	while(option != -1);
	
	// Resolving hostname
	he = gethostbyname(serverAddress.c_str());
	
	if(!he || he->h_addr_list == nullptr)
	{
		std::cerr << "Error resolving the net address " << serverAddress << '\n';
		return -1;
	}
	
	ipAddress = inet_ntoa(**(in_addr **)he->h_addr_list);

	file = std::ofstream(fileName, std::ios::binary);
	if(!file)
	{
		std::cerr << "I/O error\n";
		return -1;
	}
	
	// Region info
	file.write((char*)&zero32, sizeof(uint32_t));
	file.write("\x08Impostor", 9);
	
	// Region address
	strLen = serverAddress.size();
	file.write((char*)&strLen, sizeof(uint8_t));
	file << serverAddress;
	
	// N of servers (always 1)
	file.write( (char*)&serverLen, sizeof(uint32_t));
	
	// First and only server name
	file << "\x11Impostor-Master-1";
	
	// First and only server address (numeric form not as string)
	file.write((char*)&(*(in_addr **)he->h_addr_list)->s_addr, sizeof(uint32_t));
	file.write((char*)&port, sizeof(uint16_t));
	
	file.write((char*)&zero32, sizeof(uint32_t));
	
	file.close();
	
	return 0;
}
