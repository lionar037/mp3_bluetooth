//////////////////////////////////////////////////////////////////
//
//                      main.cpp
// 
// Descripción: Este archivo implementa la funcionalidad principal
//              de una aplicación que se conecta a un dispositivo
//              Bluetooth y reproduce un archivo MP3 a través de
//              la clase `BluetoothTool`. La conexión se realiza
//              mediante la dirección MAC del dispositivo Bluetooth
//              y se utiliza una librería de manejo de Bluetooth
//              propia para gestionar la conexión y la reproducción.
//
// Dependencias:
//              - bluetooth_tool.hpp: Proporciona la clase
//                `BluetoothTool` para el manejo de conexiones y 
//                reproducción de archivos MP3.
//
// Autor: lion
// date: 2024 october 16
//
//////////////////////////////////////////////////////////////////

#include <bluetooth_tool.hpp>
#include <iostream>
#include <oled.hpp>
#include <memory>


#define BLUETOOTH_DIR "00:13:7B:DC:2C:E0" // Dirección MAC del dispositivo Bluetooth

int main() {
    // Instancia del objeto BluetoothTool
    BLUETOOTH::BluetoothTool bluetoothTool;



    std::unique_ptr<OLED::Oled_t> oled = std::make_unique<OLED::Oled_t>(128, 32, BCM2835_I2C_CLOCK_DIVIDER_626, 0x3C);

    if (!oled->begin()) {
        return -1;
    }

    oled->clearScreen();
    oled->displayText("bluetoothTool", 10, 10);
    bcm2835_delay(5000);



    
    // Dirección MAC del dispositivo Bluetooth a conectar
    const std::string dispositivo_mac = BLUETOOTH_DIR;  
    
    // Conectar al dispositivo Bluetooth usando la dirección MAC
    int sock = bluetoothTool.conectar(dispositivo_mac);
    
    // Validar si la conexión fue exitosa
    if (sock == -1) {
        // Si falla la conexión, se imprime un mensaje de error y finaliza el programa
        std::cerr << "Error al conectar con el dispositivo." << std::endl;
        return -1;
    }

    // Reproducir el archivo MP3 "musica.mp3" a través del dispositivo Bluetooth conectado
    bluetoothTool.reproducirMP3("musica.mp3");

    // Finalizar el programa exitosamente
    return 0;
}
