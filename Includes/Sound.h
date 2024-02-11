#ifndef SOUND_H
# define  SOUND_H

/*	Includes	*/
# include "main.h"
# include <pthread.h>
# include <stdbool.h>
/*	Sounds files	*/
# define LOFI_SOUND "assets/sounds/music/lofi.mp3"
# define DANCE_SOUND "assets/sounds/music/dance-away.mp3"
# define SPACE_SOUND "assets/sounds/music/space.mp3"
# define ROLL_SOUND "assets/sounds/music/we-own-the-night-roll-out.mp3"

/*	Structure	*/
typedef struct	t_sound
{
	unsigned int	id;
	pthread_t		soundThreadId; // Id thread son
	Mix_Music		*music;
	char			*file;
	bool			play;
	int				status;
	int				*error_m; // error master
	struct t_sound		*next;
}	s_sound;


/*	Fonctions	*/
s_sound	*sound_next(s_sound *lst);
void	sound_init(s_sound *sound);
void	play_sound(s_sound *sound, char *file);
void	close_sound(s_sound *sound, char *file);
void	*soundThread(void *data);

#endif
