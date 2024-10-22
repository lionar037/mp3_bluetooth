//////////////////////////////////////////////////////////////////
//
//                  bluetooth_tool.cpp
// 
// Descripción: Este archivo implementa las funciones de la clase
//              `BluetoothTool` que permiten la conexión a un 
//              dispositivo Bluetooth utilizando RFCOMM y la 
//              reproducción de archivos MP3 a través de un 
//              comando del sistema. También se incluye una 
//              función auxiliar para convertir direcciones MAC 
//              en formato de cadena a la estructura `bdaddr_t`.
//
// Dependencias:
//              - bluetooth_tool.hpp: Definición de la clase 
//                `BluetoothTool`.
//              - Librerías de Bluetooth de Linux: hci.h, hci_lib.h, 
//                bluetooth.h y rfcomm.h.
//
// Autor: lion
// Fecha: 2024 Octb
//
//////////////////////////////////////////////////////////////////

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
    // La función toma una dirección MAC en formato de cadena y la convierte
    // en una estructura `bdaddr_t`, que es requerida para operaciones Bluetooth.
    void BluetoothTool::stringToBdAddr(const std::string& mac_str, bdaddr_t* bdaddr) {
        int values[6];
        // Separar la dirección MAC en seis valores hexadecimales


        std::cout<<"device mac_str : "<<mac_str.c_str()<<"\n";
        if (sscanf(mac_str.c_str(), "%x:%x:%x:%x:%x:%x", 
            &values[0], &values[1], &values[2], 
            &values[3], &values[4], &values[5]) != 6) {
            std::cerr << "Error: Dirección MAC inválida." << std::endl;
            return;
        }

        // Llenar la estructura bdaddr_t en orden inverso
        for (int i = 0; i < 6; ++i) {
            bdaddr->b[i] = static_cast<uint8_t>(values[5 - i]);  // Llenado en orden inverso
        }
    }

    // Constructor de la clase BluetoothTool
    // Inicializa el socket a -1 indicando que no hay conexión activa
    BluetoothTool::BluetoothTool() : sock(-1) {}

    // Destructor de la clase BluetoothTool
    // Si el socket está abierto, lo cierra para liberar los recursos.
    BluetoothTool::~BluetoothTool() {
        if (sock != -1) {
            close(sock);  // Cerrar el socket si está abierto
        }
    }

    // Método para conectar al dispositivo Bluetooth
    // Toma la dirección MAC del dispositivo, crea un socket Bluetooth,
    // convierte la dirección a `bdaddr_t` y trata de conectarse al dispositivo.

int BluetoothTool::conectar(const std::string& mac_address) {
    struct sockaddr_rc addr;  // Estructura para la dirección RFCOMM
    memset(&addr, 0, sizeof(addr)); // Inicializa todos los campos de la estructura a 0
    int status;

    // Crear socket Bluetooth
    sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (sock == -1) {
        perror("Error al crear el socket");
        return -1;
    }

    addr.rc_family = AF_BLUETOOTH;  // Especificar la familia Bluetooth
    addr.rc_channel = (uint8_t)1;   // Asignar el canal RFCOMM (1 por defecto)

    // Convertir manualmente la dirección MAC a `bdaddr_t`
    stringToBdAddr(mac_address, &addr.rc_bdaddr);

    // Intentar conectar al dispositivo
    status = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (status == -1) {
        perror("Error al conectar");
        return -1;
    }

    // Si la conexión es exitosa, se imprime un mensaje
    std::cout << "Conectado al dispositivo Bluetooth: " << mac_address << std::endl;
    return sock;
}

/*
    int BluetoothTool::conectar(const std::string& mac_address) {
        struct sockaddr_rc addr = { 0 };  // Estructura para la dirección RFCOMM
        int status;

        // Crear socket Bluetooth
        sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
        if (sock == -1) {
            perror("Error al crear el socket");
            return -1;
        }

        addr.rc_family = AF_BLUETOOTH;  // Especificar la familia Bluetooth
        addr.rc_channel = (uint8_t)1;   // Asignar el canal RFCOMM (1 por defecto)

        // Convertir manualmente la dirección MAC a `bdaddr_t`
        stringToBdAddr(mac_address, &addr.rc_bdaddr);

        // Intentar conectar al dispositivo
        status = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        if (status == -1) {
            perror("Error al conectar");
            return -1;
        }

        // Si la conexión es exitosa, se imprime un mensaje
        std::cout << "Conectado al dispositivo Bluetooth: " << mac_address << std::endl;
        return sock;
    }

*/



    // Método para reproducir un archivo MP3 en el dispositivo Bluetooth conectado
    // Utiliza el comando del sistema `mpg123` para reproducir el archivo especificado.
    void BluetoothTool::reproducirMP3(const std::string& archivo) {
        // Construir el comando para ejecutar `mpg123`
        std::string comando = "mpg123 " + archivo;
        std::cout << "Reproduciendo archivo: " << archivo << std::endl;
        // Ejecutar el comando del sistema
        system(comando.c_str());
    }

}  // namespace BLUETOOTH
