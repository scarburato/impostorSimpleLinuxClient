# Custom `regionInfo.dat` generator for Among Us
**This is an ugly C/C++ program held together with tape!**

This program generates a regionInfo.dat file to allow Among Us to connect to custom servers like [Impostor](https://github.com/AeonLucid/Impostor/).

## Building on Android
1. Install Termux, run `termux-setup-storage` and allow for disk access.
2. Install via CLI clang and make (and git if you want to clone this repo with it)
3. cd into the repo and run `make all`
4. ???
5. Profit!

## How to run
run `./generator` with the following options

- `-s [server address]` to specify on which server you want the game to connect
- `-p [port]` to specify the port, it defaults to the default port
- `-o [file]` to specify on which file you want to write, it defaults to `/sdcard/Android/data/com.innersloth.spacemafia/files/regionInfo.dat`


## F.A.Q.

### Why not a Java Android app?
I'm not really handy with Android development. Also this program is meant as a quick and dirty utility with no time nor the desire to mess around GUI toolkits
