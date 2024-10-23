#define INCLUDE_SDL_IMAGE
// #include <SDL_include.h>
#include <Game.h>
#include <Sprite.h>

class Sprite{
    public:
        Sprite(){
            texture = nullptr;
        }

        Sprite(std::string file){
            texture = nullptr;
            this->Open(file);
        }

        ~Sprite(){
            SDL_DestroyTexture(texture);
        }
        
        void Open(std::string file){
            if(texture == nullptr)
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
        
        void SetClip(int x, int y, int w, int h){
            clipRect.x = x;
            clipRect.y = y;
            clipRect.w = w;
            clipRect.h = h;
        }

        void Render(int x, int y){
            SDL_Rect tmp(clipRect);
            tmp.x = x; tmp.y = y;
            SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &tmp);
        }

        int GetWidth(){ return width;}
        int GetHeight(){ return height;}
        bool IsOpen(){ return texture != nullptr;}

    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
};