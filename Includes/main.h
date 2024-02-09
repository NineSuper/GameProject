#ifndef MAIN_H
# define MAIN_H

/*	Includes	*/
// * graphics
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>
// * files
# include "Input.h"
// * others
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

/*	STRING	*/
# define WIN_INIT_ERROR "Erreur lors de la création de la fenêtre : "
# define RENDU_ERROR "Erreur lors de la création du rendu : "

# define TITLE "GameInC"

typedef struct	t_windows
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	s_input			*input;
}	s_windows;

#endif
