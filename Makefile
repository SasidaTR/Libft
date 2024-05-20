# Nom de la bibliothèque
NAME = libft.a

# Options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Liste des fichiers sources
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c

# Générer les noms des fichiers objets correspondants
OBJS = $(SRCS:.c=.o)

# Règle par défaut (all)
all: $(NAME)

# Règle pour créer la bibliothèque
$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		rm -f $(OBJS)

# Règle pour compiler les fichiers objets
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
		rm -f $(OBJS)

# Règle pour nettoyer les fichiers objets et la bibliothèque
fclean: clean
		rm -f $(NAME)

# Règle pour recompiler tout depuis zéro
re: fclean all

# Indiquer que ces règles ne sont pas des fichiers réels
.PHONY: all clean fclean re
