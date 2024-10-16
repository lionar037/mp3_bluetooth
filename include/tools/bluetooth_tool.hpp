#pragma once
//#ifndef BLUETOOTH_TOOL_HPP
//#define BLUETOOTH_TOOL_HPP

#include <string>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

namespace BLUETOOTH{

class BluetoothTool {
public:
    BluetoothTool();
    ~BluetoothTool();

    // Conectar a un dispositivo Bluetooth por RFCOMM
    int conectar(const std::string& mac_address);

    // Reproducir un archivo MP3
    void reproducirMP3(const std::string& archivo);

private:
    int sock;  // Socket para la conexión Bluetooth
};

}

//#endif // BLUETOOTH_TOOL_HPP
