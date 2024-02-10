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
# include "Sound.h"
// * others
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>

/*	STRING	*/
# define TITLE "GameInC"

typedef struct	t_windows
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	s_input			input; // Input.h
	s_sound			son; // Sound.h
	bool			running; // Game Status
	int				error;
}	s_windows;

#endif
