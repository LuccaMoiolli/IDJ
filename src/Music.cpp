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
            if(music == nullptr) return; // Talvez comunicar que aconteceu?
            Mix_PlayMusic(music, times);
        }

        void Stop(int msToStop = 1500){
            Mix_FadeOutMusic(msToStop);
        }

        void Open(std::string file);{
            music = Mix_LoadMUS(file.c_str()); 
            if(music == nullptr){
                SDL_Log(SDL_GetError());
                SDL_Log("Musica nao BRIU");
                throw SDL_GetError();
            }
        }
        
        bool IsOpen(){ return music == nullptr;}
};