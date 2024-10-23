#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include <string>
#include <SDL_include.h>
#include <State.h>

class Game{
    public:
        ~Game(){
            delete state;
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            Mix_CloseAudio(); 
            Mix_Quit();
            IMG_Quit();
            SDL_Quit();
        }

        void Run(){
            while(!state->QuitRequested()){
                state->Update(0);
                state->Render();
                SDL_RenderPresent(renderer);
                SDL_Delay(33);
            }
        }

        SDL_Renderer* GetRenderer(){
            return renderer;
        }
        
        State& GetState(){
            return *state;
        }
        
        static Game& GetInstance(){
            if(instance != nullptr){
                return *instance;
            }
            new Game("19011279", 1200, 720);
            return *instance;
        }

    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

        Game(std::string title, int width, int height){

            // criar instancia se n for um absurdo
            if(instance != nullptr)
                throw 1;
            instance = this;

            // inicializar a SDL
            // throws?
            if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
                SDL_Log(SDL_GetError());
                throw SDL_GetError();
            }
            int inits = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
            if(inits != IMG_Init(inits)){
                SDL_Log(SDL_GetError());
                SDL_Log("Falha ao iniciar SDL_IMG");
                throw SDL_GetError();
            }
            Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3); // talvez seja legal tratar o retorno disso
            if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
                SDL_Log(SDL_GetError());
                SDL_Log("Falha ao iniciar SDL_mixer");
                throw SDL_GetError();
            }
            Mix_AllocateChannels(8);    // se isso der problema troca a máquina plmr

            window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if(window == nullptr || renderer == nullptr){
                SDL_Log("Falha ao alocar/renderizar janela.\n");
                throw SDL_GetError();
            }
            state = new State;
        }
};