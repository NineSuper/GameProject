#include "../../../Includes/main.h"

void    font_create(s_font *font, char *file)
{
    s_font  *temp = font_next(font);

    if (!file)
    {
        printf("ERROR font: 'NULL'\n");
        return ;
    }
    if (!temp)
        printf("error\n");
    temp->name = SDL_strdup(file);
    temp->font = TTF_OpenFont(file, 24);
    if (!temp->font)
    {
        printf("ERROR font : %s can\'t load ❌\n", file);
        return ;
    }
    printf("Font loaded successfully: %s ✅\n", temp->name);
}

s_font  *get_font(s_font *font, char *name)
{
    s_font  *temp = font->next;

    while (temp)
    {
        if (!strcmp(temp->name, name))
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

void    font_lib(s_font *font)
{
    printf("\t[Loading font 🖍️ ]\n\n");
    font_create(font, ARIAL);
    font_create(font, CARNIVAL);
    font_create(font, FRANCHISE);
    font_create(font, MAGIC_RETRO);
    font_create(font, NAMECAT);
    font_create(font, SUPER_RETRO);
    font_create(font, "TEST_ERROR");
    font_create(font, NULL);
}

void	init_ttf(s_font *font)
{
	TTF_Init();
    font->next = NULL;
    font->id = 0;
    font_lib(font);
}

//*	Fonction ajoute un font en fin de liste (struct font->next)
s_font	*font_next(s_font *lst)
{
	int	i;

	i = 1;
    if (!lst)
        return (NULL);
    s_font	*new = malloc(sizeof(s_font));
    if (!new)
        return (NULL);
	s_font	*temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
    new->name = NULL;
    new->font = NULL;
    new->id = i;
    temp->next = new;
    return (new);
}
