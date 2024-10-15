#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#define BLUETOOTH_DIR "00:13:7B:DC:2C:E0"

// Función para conectar a un dispositivo Bluetooth por RFCOMM (para conexión simple)
int conectarBluetooth(const char* mac_address) {
    struct sockaddr_rc addr = { 0 };
    int sock, status;

    // Crear socket Bluetooth
    sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (sock == -1) {
        perror("Error al crear el socket");
        return -1;
    }

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1; // Canal RFCOMM del dispositivo (1 es común para A2DP)
    str2ba(mac_address, &addr.rc_bdaddr); // Dirección MAC del dispositivo

    // Intentar conectar al dispositivo
    status = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (status == -1) {
        perror("Error al conectar");
        return -1;
    }

    std::cout << "Conectado al dispositivo Bluetooth: " << mac_address << std::endl;
    return sock;
}

// Función para reproducir un archivo MP3
void reproducirMP3(const char* archivo) {
    std::string comando = "mpg123 " + std::string(archivo);
    std::cout << "Reproduciendo archivo: " << archivo << std::endl;
    system(comando.c_str());
}

int main() {
    const char* dispositivo_mac = BLUETOOTH_DIR ; // Reemplaza con la dirección MAC del estéreo

    // Conectar a dispositivo Bluetooth
    int sock = conectarBluetooth(dispositivo_mac);
    if (sock == -1) {
        std::cerr << "Error al conectar con el dispositivo." << std::endl;
        return -1;
    }

    // Reproducir archivo MP3
    reproducirMP3("musica.mp3");

    // Cerrar el socket de la conexión
    close(sock);

    return 0;
}
