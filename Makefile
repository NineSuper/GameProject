# @Makefile by NineSuper (http://github.com/NineSuper)

NAME = Game

CC = gcc
CFLAGS = -std=c11
#CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SRC = srcs/main.c srcs/sound/sound.c
OBJ = $(SRC:.c=.o)

# ------------------------------ Couleurs ------------------------------

BOLD_RED        =       \033[1;31m

BOLD_PURPLE     =       \033[1;34m

BOLD_CYAN       =       \033[1;36m

BOLD_YELLOW     =       \033[1;33m

BOLD_GREEN 		=		\033[1;32m

BOLD            =       \033[1m

NO_COLOR        =       \033[0m

# ------------------------------ Messages ------------------------------

HEADER_NAME     =       $(HEADER_TOP) $(HEADER_TOP_MID) $(HEADER_MID)$(HEADER_BOT)

HEADER_COMP     =       echo "\n📢 $(BOLD_PURPLE)$(NAME) $(NO_COLOR)$(BOLD)by $(BOLD_RED)NineSuper\n\n"

COMP_START      =       printf "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Debut de compilation... $(BOLD_YELLOW)\r$(NO_COLOR)"

EXE_READY       =       echo "\n\n🎮 $(BOLD)Compilation de $(BOLD_PURPLE)$(NAME)$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

CLEANED         =       echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

FCLEANED        =       echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

NORM            =       echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme de tous les fichiers en .c !\n$(BOLD_PURPLE)"

NORM_LIB        =       echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du dossier $(BOLD_CYAN)/libft $(BOLD_YELLOW)!\n$(BOLD_YELLOW)"

NORM_H          =       echo "\n📣 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du .h\n$(BOLD_PURPLE)"

# ------------------------------ Règles ------------------------------

MAKEFLAGS += --silent

TOTAL_FILES := $(words $(SRC))
COMPILED_FILES := 0

$(NAME): comp_start $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\n"
	@$(EXE_READY)


all: $(NAME)

comp_start:
	@$(HEADER_COMP)
	@$(COMP_START)

clean:
	$(CLEANED)
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)
	$(FCLEANED)

re: fclean all

%.o: %.c
		@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s$(BOLD_YELLOW)[%d/%d] $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(COMPILED_FILES) $(TOTAL_FILES) $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))
		@$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@
		@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
		@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Compilation des fichiers :$(BOLD_CYAN) %-33.33s$(BOLD_YELLOW)[%d/%d] $(BOLD_YELLOW)[%3d%%] \r$(NO_COLOR)" $? $(COMPILED_FILES) $(TOTAL_FILES) $(shell expr \( $(COMPILED_FILES) \) \* 100 / $(TOTAL_FILES))
