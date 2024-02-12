#include "../Includes/main.h"

/*
? Ce fichier contient les fonctions principales nécessaires au fonctionnement du jeu.
? Il gère l'initialisation du jeu, la boucle principale, la gestion des événements,
? la mise à jour de l'état du jeu et le rendu graphique.
? Il sert de point d'entrée de l'application.
? Ferme le jeu lors de l'exit
*/

void updatePlayer()
{
    // Mettre à jour la position du joueur, la vitesse, etc.
}

void updateMap()
{
    // Mettre à jour les éléments de la carte, comme les tuiles, les décors, etc.
}

void updateAnimations()
{
    // Mettre à jour les animations des personnages, des objets, etc.
}

void handleCollisions()
{
    // Vérifier les collisions entre le joueur et les objets/environnement
    // Si une collision est détectée, effectuer les actions appropriées (déplacement, dommages, etc.)
}

// Fonction de rendu graphique
void render()
{
    // Effacer l'écran ou effacer les images précédentes
    // Dessiner le joueur, la carte, les animations, etc.
    // Mettre à jour l'écran (si nécessaire)
}

void handleKeyboardEvent(SDL_Event event)
{
    // TODO gérer les touches de l'utilisateur
}


void	gameLoop(s_windows *master)
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

        SDL_SetRenderDrawColor(master->renderer, 255, 255, 255, 255);

		// TODO mise à jour de l'état du jeu

        SDL_RenderPresent(master->renderer); // rendu final
        SDL_Delay(16); //* ~60 FPS
    }
    if (master->error)
        printf("master error\n");
    SDL_DestroyRenderer(master->renderer);
    SDL_DestroyWindow(master->win);
    SDL_Quit();
}

void    exit_game(s_windows *master)
{
    //TODO libérer les mémoires et les threads lors de l'exit du jeu
    //while (&master->son.next)
    pthread_join(master->son.soundThreadId, NULL);
    free(master);
}

// TODO chercher des assets libre de droit
// TODO faire charger toutes les ressources du jeu avec un écran de chargement
// TODO découper des tiles
// TODO savoir quel type de vu 2D (Top-Down ou Vue isométrique)
// TODO faire la 2D, système de caméra (Zoom/dézoom/rotation ?)
// TODO Faire les TODO dans sound/sound.c
// TODO Faire une map temporaire afin de mettre un joueur, une map, un HUD, des items, etc..
// TODO faire déplacer le joueur
// TODO faire des animations (idle/walk/jump ?)

int main()
{
    s_windows	*master;

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
    play_sound(&master->son, ROLL_SOUND);

	gameLoop(master);
    //exit_game(master);
    return 0;
}



