#!/bin/bash

#dir 
INC="/home/pi/src/mp3/include/assets/"

DIR

LIBS=-lmpg123 -lao -lpthread

g++ -std=c++17 -o playerBluetoothApp src/main.cpp $LIBS -I$INC



EDGE 6C:97:6D:55:CE:99

bluetoothctl

scan on

scan off

#sudo hcitool scan

sudo hcitool scan

sudo systemctl enable bluetooth
sudo systemctl start bluetooth

show
power on

power off
discoverable on

#!/bin/bash

# Ajusta el volumen del canal Master al 80%
amixer set Master 80%

# Inicia alsamixer (opcional)
alsamixer

