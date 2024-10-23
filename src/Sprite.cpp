#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include <SDL_include.h>
#include <Game.h>
#include <string>

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
                IMG_LoadTexture(game.GetRenderer(), file.c_str()); // como usa game aqui?
            }
        }
        
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
};