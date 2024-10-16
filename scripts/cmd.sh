#!/bin/bash

#dir 
#INC="/home/pi/src/mp3/include/assets/"

INC="/home/pi/src/extern_bluetooth_mp3/include/assets/"

#dependencies 
#sudo apt-get install libmpg123-dev libao-dev -y


LIBS="-lmpg123 -lao -lpthread -lbluetooth"

g++ -std=c++17 -o bin/playerBluetoothApp src/main.cpp $LIBS -I$INC
#g++ -std=c++17 -o playerBluetoothApp src/main.cpp $LIBS -I$INC


#g++ -std=c++17 -o playerBluetoothApp src/main.cpp  -lmpg123 -lao -lpthread -lbluetooth