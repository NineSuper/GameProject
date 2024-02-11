#include "../Includes/main.h"

/*
? ce fichier sound.c devrait contenir les fonctions nécessaires pour gérer
? la lecture de musique de fond, la lecture des effets sonores,
? ainsi que l'initialisation et la libération des ressources audio.

* Chaque musique jouée auront leur thread
* Pthread_join = le thread principal attend la fin des threads
*/

s_sound	*sound_next(s_sound *lst)
{
	int	i;

	i = 1;
    if (!lst)
        return (NULL);
    s_sound	*new = malloc(sizeof(s_sound));
    if (!new)
	{
        printf("Erreur d'allocation de mémoire\n");
        return (NULL);
    }
	s_sound	*temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	new->next = NULL;
	new->id = i;
	new->status = 0;
	new->play = false;
	new->error_m = lst->error_m;
	temp->next = new;
    return (new);
}

void	*soundThread(void *data)
{
    s_sound	*sound = (s_sound*)data;
    Mix_PlayMusic(sound->music, 1);
	if (!sound->music) // TODO gérer l'erreur
	{
		printf("error\n");
		*sound->error_m = 1;
		sound->status = -1;
		return (NULL);
	}
	sound->play = true;
	//sound->status = 1; // TODO gérer les status
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

void	play_sound(s_sound *sound, char *file)
{
	// TODO gérer la mise en pause du son
	// TODO gérer le volume d'un son
	sound->music = Mix_LoadMUS(file);
	if (!sound->music) // TODO gérer l'erreur si la musique n'est pas chargée
	{
		printf("error\n");
		*sound->error_m = 1;
	}
	sound->file = SDL_strdup(file);
	printf("%d\n", sound->id);
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
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
}
