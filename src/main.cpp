//////////////////////////////////////////////////////////////////
//
//                      main.cpp
//
//////////////////////////////////////////////////////////////////

#include <bluetooth_tool.hpp>
#include <iostream>

#define BLUETOOTH_DIR "00:13:7B:DC:2C:E0"

int main() {
    BLUETOOTH::BluetoothTool bluetoothTool;
    const std::string dispositivo_mac = BLUETOOTH_DIR;  // Dirección MAC del dispositivo

    // Conectar a dispositivo Bluetooth
    int sock = bluetoothTool.conectar(dispositivo_mac);
    if (sock == -1) {
        std::cerr << "Error al conectar con el dispositivo." << std::endl;
        return -1;
    }

    // Reproducir archivo MP3
    bluetoothTool.reproducirMP3("musica.mp3");

    return 0;
}
