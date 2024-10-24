#define INCLUDE_SDL
#include <SDL_include.h>
#include <State.h>

State::State(){
    quitRequested = false;
    bg = Sprite("Recursos/img/Background.png");
    music = Music("Recursos/audio/BGM.wav");
}

bool State::QuitRequested (){
    return quitRequested;
}

void State::LoadAssets (){
    music.Play();
}

void State::Update (float dt){
    quitRequested = SDL_QuitRequested();
}

void State::Render (){
    bg.Render(0,0);
}