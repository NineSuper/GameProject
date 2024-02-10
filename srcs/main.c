#include "../Includes/main.h"

/*
? Ce fichier contient les fonctions principales nécessaires au fonctionnement du jeu.
? Il gère l'initialisation du jeu, la boucle principale, la gestion des événements,
? la mise à jour de l'état du jeu et le rendu graphique.
? Il sert de point d'entrée de l'application.
? Ferme le jeu lors de l'exit

TODO Utiliser les threads pour faire des calculs lourds tels que les collisions/
    TODO (suite->) Les sons/musique/animations
*/

void displayMainMenu(SDL_Renderer* renderer)
{
    // Afficher le menu principal (titre, options, etc.)
    // Utiliser SDL_RenderPresent(renderer) pour mettre à jour l'affichage
}

void handleMainMenuInput(SDL_Event event, bool* running, bool* startGame)
{
    // Gérer les entrées utilisateur dans le menu principal
    // Modifier les variables running et startGame en conséquence
}

void	gameLoop(s_windows *master)
{
	SDL_Event   event;

	master->running = true;
    while (master->running)
    {
        while (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                master->running = false;
        SDL_SetRenderDrawColor(master->renderer, 0, 0, 0, 255);
        SDL_RenderClear(master->renderer); // clear l'écran

        SDL_SetRenderDrawColor(master->renderer, 255, 255, 255, 255);

		// TODO mise à jour de l'état du jeu

        SDL_RenderPresent(master->renderer); // rendu final
        //SDL_Delay(10);
    }
    SDL_DestroyRenderer(master->renderer);
    SDL_DestroyWindow(master->win);
    SDL_Quit();
}

void    exit_game(s_windows *master)
{
    // TODO libérer les mémoire et les threads lors de l'exit du jeu
    //pthread_join(master->son.soundThreadId, NULL);
    //free(master);
}

int main()
{
    s_windows	*master;

    master = calloc(sizeof(master), 1);
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
	gameLoop(master);
    //exit_game(master);
    return 0;
}
