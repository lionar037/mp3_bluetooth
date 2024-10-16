//////////////////////
//
//          bluetooth_tool.cpp
//
//////////////////////


#include <bluetooth_tool.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/bluetooth.h>  // Incluir para bdaddr_t
#include <bluetooth/rfcomm.h>
#include <sstream>
#include <iomanip>

namespace BLUETOOTH {

// Función para convertir una cadena MAC a bdaddr_t manualmente
    void stringToBdAddr(const std::string& mac_str, bdaddr_t* bdaddr) {
        int values[6];
        if (sscanf(mac_str.c_str(), "%x:%x:%x:%x:%x:%x", 
            &values[0], &values[1], &values[2], 
            &values[3], &values[4], &values[5]) != 6) {
            std::cerr << "Error: Dirección MAC inválida." << std::endl;
            return;
        }

        for (int i = 0; i < 6; ++i) {
            bdaddr->b[i] = static_cast<uint8_t>(values[5 - i]);  // Llenado en orden inverso
        }
    }

    BluetoothTool::BluetoothTool() : sock(-1) {}

    BluetoothTool::~BluetoothTool() {
        if (sock != -1) {
            close(sock);  // Cerrar el socket si está abierto
        }
    }

    int BluetoothTool::conectar(const std::string& mac_address) {
        struct sockaddr_rc addr = { 0 };
        int status;

        // Crear socket Bluetooth
        sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
        if (sock == -1) {
            perror("Error al crear el socket");
            return -1;
        }

        addr.rc_family = AF_BLUETOOTH;
        addr.rc_channel = (uint8_t)1;  // Canal RFCOMM del dispositivo

        // Convertir manualmente la dirección MAC
        stringToBdAddr(mac_address, &addr.rc_bdaddr);

        // Intentar conectar al dispositivo
        status = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        if (status == -1) {
            perror("Error al conectar");
            return -1;
        }

        std::cout << "Conectado al dispositivo Bluetooth: " << mac_address << std::endl;
        return sock;
    }

    void BluetoothTool::reproducirMP3(const std::string& archivo) {
        std::string comando = "mpg123 " + archivo;
        std::cout << "Reproduciendo archivo: " << archivo << std::endl;
        system(comando.c_str());
    }

}  // namespace BLUETOOTH

