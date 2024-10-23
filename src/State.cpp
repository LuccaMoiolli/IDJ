#define INCLUDE_SDL
#include <SDL_include.h>
#include <State.h>

class State{
    public:
        State(){
            quitRequested = false;
            bg = Sprite("Recursos/img/Background.png");
            music = Music("Recursos/audio/BGM.wav");
        }

        bool QuitRequested (){
            return quitRequested;
        }

        void LoadAssets (){
            return;
        }

        void Update (float dt){
            quitRequested = SDL_QuitRequested();
        }

        void Render (){
            bg.Render(0,0);
        }


    private:
        Sprite bg;
        Music music;
        bool quitRequested;
};