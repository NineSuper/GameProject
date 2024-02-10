#include "../Includes/main.h"

/*
? ce fichier sound.c devrait contenir les fonctions nécessaires pour gérer
? la lecture de musique de fond, la lecture des effets sonores,
? ainsi que l'initialisation et la libération des ressources audio.
*/

// Thread sonore
void	*soundThread(void* data)
{
    SoundThreadData	*soundData = (SoundThreadData*)data;
    Mix_PlayMusic(soundData->music, 1);
	printf("ok\n");
    return (NULL);
}

/*
	Initialiser le thread qui va permettre au son de s'executer
*/
void	sound_init(s_sound *sound, int *error)
{
	pthread_t	soundThreadId;

	sound->error_m = error;
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(MIX_DEFAULT_FORMAT, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	sound->music = Mix_LoadMUS(ROLL_SOUND);
	Mix_PlayMusic(sound->music, -1);
	if (!sound->music)
		*sound->error_m = 1;
	SoundThreadData soundData = {.music = sound->music};
	pthread_create(&sound->soundThreadId, NULL, soundThread, &soundData);
	pthread_join(sound->soundThreadId, NULL);
	//Mix_FreeMusic(sound->music);
	//Mix_CloseAudio();
}
