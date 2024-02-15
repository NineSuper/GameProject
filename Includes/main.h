#ifndef MAIN_H
# define MAIN_H

/*	Includes	*/
// * graphics
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>
# include <libxml2/libxml/hash.h>

// * files
# include "input.h"
# include "sound.h"
# include "font.h"

// * others
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <expat.h>

/*	STRING	*/
# define TITLE "GameInC"

typedef struct	t_master
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	s_input			input; // input.h
	s_sound			son; // sound.h
	s_font			font; // font.h
	bool			running; // Game Status
	int				error;
}	s_master;



#endif
