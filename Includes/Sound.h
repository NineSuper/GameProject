#ifndef SOUND_H
# define  SOUND_H

/*	Includes	*/
# include "main.h"
# include <pthread.h>
/*	Sounds files	*/
# define LOFI_SOUND "assets/sounds/music/lofi.mp3"
# define DANCE_SOUND "assets/sounds/music/dance-away.mp3"
# define SPACE_SOUND "assets/sounds/music/space.mp3"
# define ROLL_SOUND "assets/sounds/music/we-own-the-night-roll-out.mp3"

// Thread sonore
typedef struct
{
    Mix_Music *music;
}	SoundThreadData;

typedef struct	t_sound
{
	pthread_t	soundThreadId; // Id thread son
	Mix_Music	*music;
	int			*error_m; // error master
}	s_sound;

void	sound_init(s_sound *sound, int *error);

#endif
