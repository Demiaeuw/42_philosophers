# Nom de l'executable
NAME = philosopher

# Fichiers source
SRCS =	main.c\
		srcs/00_init.c\
		srcs/01_free.c\
		srcs/02_error.c\
		srcs/10_ft_printf.c\
		srcs/11_checkint.c


# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Règle par défaut
all: printhader printactionobj $(NAME) printactionobjok printend
rapide: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS) $(OBJSUTILS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

# Règle pour nettoyer les fichiers objets
exe: all clean

clean:
	@$(RM) $(OBJS)

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
	@sleep 0.1# Nom de l'executable
NAME = philosopher

# Fichiers source
SRCS =	main.c\
	srcs/00_base/error00.c\
	srcs/00_base/error01.c\
	srcs/00_base/free00.c\
	srcs/00_base/init00.c\
	srcs/01_argument/argument00.c\
	srcs/01_argument/argument01.c\
	srcs/02_thread/initthread00.c\
	srcs/03_routine/routine00.c

UTILS = srcs/utils/ft_atoi.c\
	srcs/utils/checkint.c\
	srcs/utils/ft_memset.c\
	srcs/utils/print_struct.c


# Fichiers objets
OBJS = $(SRCS:.c=.o)
OBJSUTILS = $(UTILS:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Règle par défaut
all: printhader printactionobj $(NAME) printactionobjok printend
rapide: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS) $(OBJSUTILS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJSUTILS) -lpthread

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
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   Utilitaire : \033[94m./philosopher\033[0m est utilisable."
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1

printendclean:
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@echo " "
	@sleep 0.1
	@echo "   Tous les fichiers sont supprimé 🚮"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   \033[32mMerci d'avoir utilisé\033[0m \033[94mphilosopher\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1

	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   Utilitaire : \033[94m./philosopher\033[0m est utilisable."
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1

printendclean:
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@echo " "
	@sleep 0.1
	@echo "   Tous les fichiers sont supprimé 🚮"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "   \033[32mMerci d'avoir utilisé\033[0m \033[94mphilosopher\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
	@echo "\033[94m ________________________________________ \033[0m"
	@sleep 0.1
	@echo "\033[94m|________________________________________|\033[0m"
	@sleep 0.1
	@echo " "
	@sleep 0.1
