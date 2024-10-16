//////////////////////////////////////////////////////////////////
//
//                  bluetooth_tool.hpp
// 
// Descripción: Este archivo define la clase `BluetoothTool`, que
//              proporciona métodos para conectarse a un dispositivo
//              Bluetooth mediante RFCOMM y para reproducir archivos
//              MP3 a través de una conexión Bluetooth. 
//
//              La clase maneja la creación y cierre del socket
//              Bluetooth, y encapsula la funcionalidad básica para 
//              establecer la comunicación y ejecutar comandos de 
//              reproducción de audio.
//
// Dependencias:
//              - bluetooth.h: Librería para el manejo de Bluetooth.
//              - rfcomm.h: Librería para la comunicación RFCOMM.
//
// Autor: lion
// Fecha: 2024 Octb
//
//////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

namespace BLUETOOTH {

    // Clase que encapsula la funcionalidad básica para conexión y
    // manejo de dispositivos Bluetooth usando RFCOMM.
    class BluetoothTool {
    public:
        // Constructor: Inicializa el socket a un estado no conectado (-1)
        BluetoothTool();

        // Destructor: Cierra el socket si está abierto
        ~BluetoothTool();

        // Conectar a un dispositivo Bluetooth por RFCOMM
        // Recibe la dirección MAC como un string y retorna el socket
        // o -1 en caso de error.
        int conectar(const std::string& mac_address);

        // Reproducir un archivo MP3 a través de la conexión Bluetooth
        // Toma el nombre del archivo y utiliza un comando del sistema
        // para reproducirlo.
        void reproducirMP3(const std::string& archivo);

    private:
        int sock;  // Socket para la conexión Bluetooth
    };

} // namespace BLUETOOTH
