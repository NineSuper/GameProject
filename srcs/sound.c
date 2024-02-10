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
    return (NULL);
}

/*
Initialiser le thread qui va permettre au son de s'executer
*/
void	sound_init(s_sound *sound)
{
	pthread_t	soundThreadId;

	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	sound->music = Mix_LoadMUS(LOFI_SOUND);
	Mix_PlayMusic(sound->music, -1);
	if (!sound->music)
	{
		printf("error\n");
		exit (0);
	}
	SoundThreadData soundData = {.music = sound->music};
	pthread_create(&sound->soundThreadId, NULL, soundThread, &soundData);
	pthread_join(sound->soundThreadId, NULL);
	//Mix_FreeMusic(sound->music);
	//Mix_CloseAudio();
}
