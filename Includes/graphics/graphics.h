#ifndef GRAPHICS_H
# define GRAPHICS_H

/*	Includes	*/

# include "../SDL2.h"
# include <stdlib.h>

/*	STRING	*/
# define WIN_INIT_ERROR "Erreur lors de la création de la fenêtre : "
# define RENDU_ERROR "Erreur lors de la création du rendu : "

# define TITLE "GameInC"

typedef struct	windows
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
}	s_windows;

#endif
