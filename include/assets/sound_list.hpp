#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>


#define TRACK(x) "assets/sound" x

namespace fs = std::filesystem;

namespace SOUND_LIST{

    struct SoundList_t{

        public:
            SoundList_t();
            ~SoundList_t()=default;

            const std::vector <std::string>& get_list()const {
                //sound_list() ;
                return mp3_list;
            }

        protected:
            int sound_list() ;

        private:            
            std::vector <std::string>mp3_list;
    };
    
}