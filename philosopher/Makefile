# Nom de l'exécutable
NAME = philo

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread

# Dossiers
INCLUDES_DIR = includes

# Fichiers sources
SRCS =	00_utils.c \
		01_check.c \
		02_initandfree.c \
		03_routine.c \
		main.c

# Convertir les fichiers .c en fichiers .o
OBJS = $(SRCS:%.c=%.o)

# Commandes pour compiler les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

# Règle principale pour créer l'exécutable
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Ne pas considérer ces noms comme des fichiers
.PHONY: all clean fclean re
