#include "../Includes/graphics/graphics.h"

/*
? Ce fichier contient les fonctions principales nécessaires au fonctionnement du jeu.
? Il gère l'initialisation du jeu, la boucle principale, la gestion des événements,
? la mise à jour de l'état du jeu et le rendu graphique.
? Il sert de point d'entrée de l'application.
? Ferme le jeu lors de l'exit
*/

int main()
{
    s_windows	*master;

    master = calloc(sizeof(master), 1);
    if (!master)
        return (1);
    SDL_Init(SDL_INIT_VIDEO);
    master->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, SDL_WINDOW_RESIZABLE);
    if (!master->win)
        return (1);
    master->renderer = SDL_CreateRenderer(master->win, 1, SDL_RENDERER_ACCELERATED);
    if (master->renderer == NULL)
    {
        SDL_DestroyWindow(master->win);
        SDL_Quit();
        return (1);
    }

    SDL_SetRenderDrawColor(master->renderer, 255, 0, 0, 255); // Rouge
    SDL_RenderClear(master->renderer);
    SDL_RenderPresent(master->renderer);
    SDL_Event event;

    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                running = 0;
    }
    SDL_DestroyRenderer(master->renderer);
    SDL_DestroyWindow(master->win);
    SDL_Quit();
    //free(master);
    return 0;
}
