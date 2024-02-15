#include "../Includes/main.h"

// TODO chercher des assets libre de droit
// TODO faire charger toutes les ressources du jeu avec un écran de chargement
// TODO découper des tiles
// TODO savoir quel type de vu 2D (Top-Down ou Vue isométrique)
// TODO faire la 2D, système de caméra (Zoom/dézoom/rotation ?)
// TODO Faire les TODO dans sound/sound.c
// TODO Faire une map temporaire afin de mettre un joueur, une map, un HUD, des items, etc..
// TODO faire déplacer le joueur
// TODO faire des animations (idle/walk/jump ?)

// Fonction de rendu de la carte
void renderMap(SDL_Renderer *renderer)
{
    // Analyser le fichier TMX en utilisant la bibliothèque expat
    // Pendant l'analyse, la fonction startElement() sera appelée pour chaque élément
}

void    init_map(s_master *master)
{

}

void	gameLoop(s_master *master)
{
	SDL_Event   event;

	master->running = true;
    while (master->running && !master->error)
    {
        while (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                master->running = false;

        //handleKeyboardEvent(event); // TODO Clavier

        SDL_SetRenderDrawColor(master->renderer, 0, 0, 0, 255);
        SDL_RenderClear(master->renderer);

		// TODO mise à jour de l'état du jeu
        renderMap(master->renderer);

        SDL_RenderPresent(master->renderer); // rendu final
        SDL_Delay(16); //* ~60 FPS
    }
    if (master->error)
        printf("master error\n");
}

void    exit_game(s_master *master)
{
    //TODO libérer les mémoires et les threads lors de l'exit du jeu
    SDL_DestroyRenderer(master->renderer);
    SDL_DestroyWindow(master->win);
    SDL_Quit();
}

int main()
{
    s_master	*master;

    master = calloc(sizeof(master), 1);
    master->error = 0;
    master->son.error_m = &master->error;
    if (!master)
        return (1);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    master->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, SDL_WINDOW_RESIZABLE);
    if (!master->win)
        return (1);
    master->renderer = SDL_CreateRenderer(master->win, 1, SDL_RENDERER_ACCELERATED);
    if (!master->renderer)
    {
        SDL_DestroyWindow(master->win);
        SDL_Quit();
        return (1);
    }

    sound_init(&master->son);
    init_ttf(&master->font);
    play_sound(&master->son, ROLL_SOUND);

    init_map(master);

	gameLoop(master);
    exit_game(master);
    return 0;
}




