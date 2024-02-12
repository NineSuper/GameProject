#include "../Includes/main.h"

/*
? ce fichier sound.c devrait contenir les fonctions nécessaires pour gérer
? la lecture de musique de fond, la lecture des effets sonores,
? ainsi que l'initialisation et la libération des ressources audio.

* Chaque musique jouée auront leur thread
* Pthread_join = le thread principal attend la fin des threads

! Mix_Chunk = audio court et répétitif
! Mix_Music = audio long

* Info sur le canal audio

2 = Général
3 = Musique
4 à 8 = Effets Sonore
9 = Cinématique
*/

void	volume_music(int volumeChange)
{
	static int	volume = 16;

	volume += volumeChange;
	if (volume < 0)
		volume = 0;
	else if (volume > 128)
		volume = 128;
	Mix_VolumeMusic(volume);
}

void	volume_master(int volumeChange)
{
	static int	volume = 16;

	volume += volumeChange;
	if (volume < 0)
		volume = 0;
	else if (volume > 128)
		volume = 128;
	Mix_Volume(2, volume);
}

void	volume_effect(int volumeChange)
{
	static int	volume = 16;

	volume += volumeChange;
	if (volume < 0)
		volume = 0;
	else if (volume > 128)
		volume = 128;
	Mix_Volume(4, volume);
	Mix_Volume(5, volume);
	Mix_Volume(6, volume);
	Mix_Volume(7, volume);
	Mix_Volume(8, volume);
}

void	*soundThread(void *data)
{
    s_sound	*sound = (s_sound*)data;
	sound->music = Mix_LoadMUS(sound->file);
	if (!sound->music) // TODO gérer l'erreur si la musique n'est pas chargée
		*sound->error_m = 1;
    Mix_PlayMusic(sound->music, 1);
	if (!sound->music) // TODO gérer l'erreur
		return (NULL);
	sound->play = true;
    return (NULL);
}

void sound_stop()
{
	// TODO
}

void	close_sound(s_sound *sound, char *file)
{
	// TODO faire la fermeture d'un son lorsqu'il n'est plus joué
	//pthread_join(sound->soundThreadId, NULL);
	//Mix_FreeMusic(sound->music);
	//Mix_CloseAudio();
}

void	play_sound(s_sound *sound, char *file, int channel)
{
	// TODO gérer la mise en pause du son
	// TODO gérer le volume d'un son
	sound->file = SDL_strdup(file);
	sound->channel = channel;
	pthread_create(&sound->soundThreadId, NULL, soundThread, sound);
}

void	sound_init(s_sound *sound)
{
	sound->next = NULL;
	sound->file = NULL;
	sound->id = 0;
	sound->status = 0;
	sound->play = false;
	sound->music = NULL;
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(10);
	volume_master(0);
	volume_music(0);
	volume_effect(0);
}

/*	Fonction struct sound->next */
s_sound	*sound_next(s_sound *lst)
{
	int	i;

	i = 1;
    if (!lst)
        return (NULL);
    s_sound	*new = malloc(sizeof(s_sound));
    if (!new)
        return (NULL);
	s_sound	*temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	new->channel = 0;
	new->next = NULL;
	new->id = i;
	new->status = 0;
	new->play = false;
	new->error_m = lst->error_m;
	temp->next = new;
    return (new);
}
