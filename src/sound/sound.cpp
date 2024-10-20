#include <sound_list.hpp>
#include <algorithm>

namespace SOUND_LIST{

// Utilizando la librería estándar de filesystem

    SoundList_t::SoundList_t()
    {
        sound_list();
    }

    int SoundList_t::sound_list() {
        std::string folderPath = "assets/sounds"; // Cambia esto por la ruta a tu carpeta
        std::vector<std::string> mp3Files;
    
        try {
            // Iterar sobre los archivos en la carpeta
            for (const auto& entry : fs::directory_iterator(folderPath)) {
                // Verificar si la extensión es .mp3 (case insensitive)
                if (entry.path().extension() == ".mp3") {
                    mp3Files.push_back(entry.path().string());
                    mp3_list.push_back(entry.path().string());
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error al leer la carpeta: " << e.what() << std::endl;
            return -1;
        }
    
        // Mostrar la lista de archivos MP3 encontrados
        std::cout << "MP3 encontrados en la carpeta:\n";
        for (const auto& file : mp3Files) {
            std::cout << file << std::endl;
        }
    
        return 0;
    }

    const std::vector <std::string>& SoundList_t::convertToMayuscule(std::vector<std::string>& display_text ){
	for (auto& str : display_text) 
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });  // Convertir cada cadena a mayúsculas
    return display_text;    
    }

}