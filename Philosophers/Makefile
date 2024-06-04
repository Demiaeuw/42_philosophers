# Nom de l'executable
NAME = philosopher

# Fichiers source
SRCS =	main.c\
	srcs/00_base/00_error.c\
	srcs/00_base/00_free.c\
	srcs/00_base/00_init.c\
	srcs/01_argument/00_argument.c\
	srcs/01_argument/01_checkint.c

UTILS = srcs/utils/ft_atoi.c


# Fichiers objets
OBJS = $(SRCS:.c=.o)
OBJSUTILS = $(UTILS:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Règle par défaut
all: printhader printactionobj $(NAME) printactionobjok printend
rapide: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS) $(OBJSUTILS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJSUTILS) 

# Règle pour nettoyer les fichiers objets
exe: all clean

clean:
	@$(RM) $(OBJS) $(OBJSUTILS) 

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) printendclean

re: fclean all

#----------------------------------------------------------------------------

# Règle d'affichage
printhader: 
	@sleep 0.1
	@echo "                                                   "
	@sleep 0.1
	@echo "\033[94m ___________________________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|___________________________________________________________|\033[0m"
	@sleep 0.1
	@echo "                                                   "
	@sleep 0.1
	@echo "  _____  _     _ _                       _               "
	@sleep 0.1
	@echo " |  __ \| |   (_) |                     | |              "
	@sleep 0.1
	@echo " | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ "
	@sleep 0.1
	@echo " |  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__|"
	@sleep 0.1
	@echo " | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |   "
	@sleep 0.1
	@echo " |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|   "
	@sleep 0.1
	@echo "                                  | |                    "
	@sleep 0.1
	@echo "                                  |_|                    "
	@sleep 0.1
	@echo "                                                   "
	@sleep 0.1
	@echo "\033[94m ___________________________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|___________________________________________________________|\033[0m"
	@sleep 0.1
	@echo "\033[97m                                                   \033[0m"
	@sleep 1

printactionobj:
	@echo " "
	@echo " "
	@sleep 0.5
	@echo "\033[97m   Compilation des\033[0m \033[38;5;208mfichiers OBJET\033[0m --> 💻"
	@echo " "
	@echo " "
	@sleep 0.5

printactionobjok:
	@echo " "
	@echo " "
	@sleep 0.5
	@echo "   Compilation des \033[32mfichiers OBJET\033[0m --> ✅"
	@echo " "
	@echo " "
	@sleep 0.5

printend:
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m _______________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|_______________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   Utilitaire : \033[94m./philosopher\033[0m est utilisable."
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m _______________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|_______________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1

printendclean:
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@sleep 0.1
	@echo "\033[94m _______________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|_______________________________|\033[0m"
	@echo " "
	@sleep 0.1
	@echo "   Tous les fichiers sont supprimé 🚮"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m _______________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|_______________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   \033[32mMerci d'avoir utilisé\033[0m \033[94mphilosopher\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m _______________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|_______________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
