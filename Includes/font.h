#ifndef FONT_H
# define  FONT_H

/*	Fonts	*/
# define ARIAL "assets/fonts/arial.ttf"
# define CARNIVAL "assets/fonts/Carnival.ttf"
# define FRANCHISE "assets/fonts/Franchise.ttf"
# define MAGIC_RETRO "assets/fonts/Magic_retro.ttf"
# define NAMECAT "assets/fonts/namecat.ttf"
# define SUPER_RETRO "assets/fonts/super_retro.ttf"
/*	Includes	*/
# include <SDL2/SDL_ttf.h>
# include "main.h"


typedef	struct  t_text
{
	SDL_Color		color;
	SDL_Surface		*textSurface;
	SDL_Texture		*textTexture;
	SDL_Rect		textRect;
}	s_text;

typedef struct t_font
{
	int				id;
	char			*name;
	TTF_Font		*font;
	struct t_font	*next;
}	s_font;


/*	Fonctions	*/
void    font_create(s_font *font, char *file);
void    font_lib(s_font *font);
void	init_ttf(s_font *font);
s_font	*font_next(s_font *lst);
s_font  *get_font(s_font *font, char *name);


#endif
