#include <Music.h>

class Music{
    private:
        Mix_Music* music;
    public:
        Music(){
            music = nullptr;
        }

        Music(std::string file){
            music = nullptr;
            this->Open(file);
        }
        
        ~Music(){
            Stop(0);
            Mix_FreeMusic(music);
        }

        void Play(int times = -1){
            Mix_PlayMusic(music, times); // tratatr nullptr
        }

        void Stop(int msToStop = 1500){
            Mix_FadeOutMusic(msToStop);
        }

        void Open(std::string file);{
            Mix_Music* Mix_LoadMUS(file.c_str()); // tratatr nullptr
        }
        
        bool IsOpen(){ return music == nullptr;}
};