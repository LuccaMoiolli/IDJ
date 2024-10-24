#define INCLUDE_SDL_IMAGE
// #include <SDL_include.h>
#include <Game.h>
#include <Sprite.h>

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file){
    texture = nullptr;
    this->Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    if(texture != nullptr)
        SDL_DestroyTexture(texture);
    
    try{
        IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    }catch(...){
        SDL_Log(SDL_GetError());
        SDL_Log("Falha ao carregar imagem");
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height); // 0s?
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect tmp(clipRect);
    tmp.x = x; tmp.y = y;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &tmp);
}

int Sprite::GetWidth(){ return width;}
int Sprite::GetHeight(){ return height;}
bool Sprite::IsOpen(){ return texture != nullptr;}
