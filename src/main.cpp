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


//pair D8:3A:DD:18:46:7F
#define RPI4    "D8:3A:DD:18:46:7F"            //example
#define RPI2W   "B8:27:EB:0B:70:57"           //example
#define SONY    "00:13:7B:DC:2C:E0" 
#define MOTO    "6C:97:6D:55:CE:99"
#define BLUETOOTH_DIR MOTO  // Dirección MAC del dispositivo Bluetooth

int main() {
    // Instancia del objeto BluetoothTool
    BLUETOOTH::BluetoothTool bluetoothTool;

    std::string tema = {"assets/sounds/Dua Lipa TrainingSeason.mp3" };

    //std::unique_ptr<OLED::Oled_t>
    auto  oled = std::make_unique<OLED::Oled_t>(128, 32, BCM2835_I2C_CLOCK_DIVIDER_626, 0x3C);

    if (!oled->begin()) {
        return -1;
    }

    oled->clearScreen();
    oled->displayText("Bluetooth mp3", 0, 0);
    bcm2835_delay(600);

    // Dirección MAC del dispositivo Bluetooth a conectar
    const std::string device_mac = BLUETOOTH_DIR;  
    
    //oled->clearScreen();
    oled->displayText(device_mac.c_str(), 0,10);
    bcm2835_delay(900); 
    // Conectar al dispositivo Bluetooth usando la dirección MAC
    int sock = bluetoothTool.conectar(device_mac);


    // Validar si la conexión fue exitosa
    if (sock == -1) {
        // Si falla la conexión, se imprime un mensaje de error y finaliza el programa
        std::cerr << "Error al conectar con el dispositivo." << std::endl;
        return -1;
    }

    // Reproducir el archivo MP3 "musica.mp3" a través del dispositivo Bluetooth conectado
    //oled->clearScreen();
    oled->displayText(tema.c_str(), 0, 20);

    bluetoothTool.reproducirMP3(tema.c_str());

    // Finalizar el programa exitosamente
    return 0;
}
