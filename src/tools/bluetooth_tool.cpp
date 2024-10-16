#include <bluetooth_tool.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <cstring>


namespace BLUETOOTH{

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
   // str2ba(mac_address.c_str(), &addr.rc_bdaddr);  // Convertir dirección MAC

    // Intentar conectar al dispositivo
    status = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (status == -1) {
        perror("Error al conectar");
        return -1;
    }

    std::cout << "Conectado al dispositivo Bluetooth: " << mac_address << std::endl;
    
    return sock;
    
   //return 0;
}

    void BluetoothTool::reproducirMP3(const std::string& archivo) {
        std::string comando = "mpg123 " + archivo;
        std::cout << "Reproduciendo archivo: " << archivo << std::endl;
        system(comando.c_str());
    }


}
