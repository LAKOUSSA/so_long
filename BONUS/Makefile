NAME		=	so_long_bonus

LIB			=	libft/libft.a
PRINT		=	ft_printf/libftprintf.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror

SRC_LIB		=	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
				libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c \
				libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c \
				libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c \
				libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
				libft/ft_atoi.c libft/ft_strdup.c libft/ft_substr.c \
				libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
				libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
				libft/ft_putendl_fd.c libft/ft_putnbr_fd.c


SRC_PRINT	=	ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr_add.c \
				ft_printf/ft_putnbr.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putnbr_hlow.c \
				ft_printf/ft_putnbr_hupp.c ft_printf/ft_printf.c


SRC_GNL		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC			=	BONUS/check_base_map.c BONUS/help_check.c BONUS/check_path.c \
				BONUS/main_check.c BONUS/display_loop.c BONUS/help_mlx.c BONUS/moves.c \
				BONUS/main.c BONUS/moves_help.c BONUS/help_animation.c \
				$(SRC_GNL)

OBJ_LIB		=	$(SRC_LIB:.c=.o)
OBJ_PRINT	=	$(SRC_PRINT:.c=.o)
OBJ			=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	: $(OBJ) $(LIB) $(PRINT)
	@printf "\e[38;5;236m \n ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎ BONUS COMPILING ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎\n\e[0m\n"
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) $(LIB) $(PRINT) -o $(NAME)
	@printf "\e[38;5;216m→	Bonus successfully build	✔︎\e[0m\n"

$(LIB)	:	$(SRC_LIB)
	@make -C libft
	@make -C libft bonus
	@make -C libft clean

$(PRINT):	$(SRC_PRINT)
	@make -C ft_printf
	@make -C ft_printf clean

clean	:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@make -C libft clean
	@printf "\e[38;5;206m→	Objects files deleted 🗑\e[0m\n"

fclean	: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -C libft fclean
	@printf "\e[38;5;206m→	All files was deleted 🗑\e[0m\n"

re		: fclean all
