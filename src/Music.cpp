#include <Music.h>
#define INCLUDE_SDL
#include <SDL_include.h>

// Mix_Music* music;
Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    music = nullptr;
    this->Open(file);
}

Music::~Music(){
    Stop(0);
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    if(music == nullptr) return; // Talvez comunicar que aconteceu?
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str()); 
    if(music == nullptr){
        SDL_Log(SDL_GetError());
        SDL_Log("Musica nao BRIU");
        throw SDL_GetError();
    }
}

bool Music::IsOpen(){ return music == nullptr;}