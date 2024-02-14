#include "../../Includes/main.h"

/*
? ce fichier sound.c devrait contenir les fonctions nécessaires pour gérer
? la lecture de musique de fond, la lecture des effets sonores,
? ainsi que l'initialisation et la libération des ressources audio.

! Mix_Chunk = audio court et répétitif
! Mix_Music = audio long

* Info sur le canal audio

2 = Général
3 = Musique
4 à 8 = Effets Sonore
9 = Cinématique
*/

//* play/stop/close son
void sound_stop()
{
	// TODO
}

void	close_sound(s_sound *sound, char *file)
{
	// TODO faire la fermeture d'un son lorsqu'il n'est plus joué
	//Mix_FreeMusic(sound->music);
	//Mix_CloseAudio();
}

void	play_sound(s_sound *sound, char *file)
{
	// * Parcours toutes les struct Sound depuis la base et cherche le son qui correspond à 'file'
	// TODO gérer la mise en pause du son

	if (!sound)
	{
		printf("error\n");
		return;
	}
	s_sound	*temp = sound->next;
	while (temp)
	{
		if (!strcmp(temp->file, file))
			break ;
		temp = temp->next;
	}
	//TODO faire les autres canaux
	if (temp->channel == 3)
		Mix_PlayMusic(temp->music, 1);
	//if (temp->channel >= 4 && temp->channel <= 8)
}
//* play/stop/close son

//* Init sound
//	* Permet de charger un sound et de les mettres à la suite de s_sound *sound
void	sound_create(s_sound *sound, char *file, int channel)
{
	s_sound	*temp = sound_next(sound);

	if (!file)
	{
		printf("ERROR sound : NULL\n");
		return ;
	}
	temp->file = SDL_strdup(file);
	temp->channel = channel;
	if (channel == 3) // TODO faire les autres channel
		temp->music = Mix_LoadMUS(temp->file);
	else if (channel >= 4 && channel <= 8)
		temp->effect = Mix_LoadWAV(temp->file);
	else // TODO Gérer les erreurs
	{
		printf("ERROR sound : channel invalid [%d] ❌\n", channel);
		return ;
	}
	if (!temp->music) // TODO Gérer les erreurs
	{
		printf("ERROR sound : \'%s\' can\'t load ❌\n", file);
		return ;
	}
	printf("Sound loaded successfully: %s ✅\n", temp->file);
}

//* Librarie sonore
void	sound_lib(s_sound *sound)
{
	printf("\t[Loading sound 🎵]\n\n");
	//! Musique
	sound_create(sound, LOFI_SOUND, 3);
    sound_create(sound, DANCE_SOUND, 3);
    sound_create(sound, SPACE_SOUND, 3);
    sound_create(sound, "TEST_ERROR", 3);
    sound_create(sound, ROLL_SOUND, 3);
	printf("\n");
	//! Other
}

void	sound_init(s_sound *sound)
{
	sound->next = NULL;
	sound->file = "NULL";
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
	sound_lib(sound);
}
//* Init sound

//* Volume
void	volume_music(int volumeChange)
{
	static int	volume = 32;

	volume += volumeChange;
	if (volume < 0)
		volume = 0;
	else if (volume > 128)
		volume = 128;
	Mix_VolumeMusic(volume);
}

void	volume_master(int volumeChange)
{
	static int	volume = 32;

	volume += volumeChange;
	if (volume < 0)
		volume = 0;
	else if (volume > 128)
		volume = 128;
	Mix_Volume(2, volume);
}

void	volume_effect(int volumeChange)
{
	static int	volume = 32;

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
//* Volume

//*	Fonction ajoute un son en fin de liste (struct sound->next)
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
	new->file = NULL;
	new->play = false;
	new->error_m = lst->error_m;
	temp->next = new;
    return (new);
}
