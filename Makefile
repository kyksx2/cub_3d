NAME = cub_3d

PURPLE_BLINK=\033[5;35m

RESET=\033[0m

CFLAGS = -Wall -Wextra -Werror -g -D_GNU_SOURCE

SRC = 	src/main.c \
		src/parsing/check_walls.c \
		src/parsing/parse_map.c \
		src/parsing/create_map.c \
		src/parsing/open_map.c \
		src/parsing/check_open.c \
		src/parsing/outils.c \
		src/execution/action.c \
		src/parsing/errors.c \
		src/execution/render.c \

MLX = include/mlx_linux/libmlx.a

LIBFT = include/libft/libft.a

HEAD = -I include/libft -I include/mlx_linux

OBJ = $(SRC:.c=.o)

all : ${NAME}

${NAME}: ${OBJ} ${MLX} ${LIBFT}
	@cc ${CFLAGS} ${OBJ} -L include/libft -lft -L include/mlx_linux -lmlx -lXext -lX11 -lm -lz -o ${NAME}
	@echo ""
	@echo ""
	@echo "${PURPLE_BLINK}                                               WELCOME TO                                             ${RESET}"
	@echo "${PURPLE_BLINK}=======================================================================================================${RESET}"
	@echo "${PURPLE_BLINK}=======================================================================================================${RESET}"
	@echo "${PURPLE_BLINK}==                                                                                                   ==${RESET}"
	@echo "${PURPLE_BLINK}==       #############   ####     ####   ##########                 ############   #########         ==${RESET}"
	@echo "${PURPLE_BLINK}==       #############   ####     ####   ###########                ############   ##########        ==${RESET}"
	@echo "${PURPLE_BLINK}==       ####            ####     ####   ###      ###                        ###   ###     ###       ==${RESET}"
	@echo "${PURPLE_BLINK}==       ####            ####     ####   ###########                  ##########   ###     ###       ==${RESET}"
	@echo "${PURPLE_BLINK}==       ####            ####     ####   ###########                  ##########   ###     ###       ==${RESET}"
	@echo "${PURPLE_BLINK}==       ####            ####     ####   ###      ###                        ###   ###     ###       ==${RESET}"
	@echo "${PURPLE_BLINK}==       #############   #############   ###########   ###########  ############   ##########        ==${RESET}"
	@echo "${PURPLE_BLINK}==       #############   #############   ##########    ###########  ############   #########         ==${RESET}"
	@echo "${PURPLE_BLINK}==                                                                                                   ==${RESET}"
	@echo "${PURPLE_BLINK}=======================================================================================================${RESET}"
	@echo "${PURPLE_BLINK}=======================================================================================================${RESET}"
	@echo ""
	@echo ""

%.o: %.c
	@cc ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< ${HEAD} -o $@

${MLX} :
	@make -C include/mlx_linux --silent > /dev/null 2>&1


${LIBFT} :
	@make -C include/libft --silent

clean :
	@rm -f ${OBJ}
	@make --silent -C include/mlx_linux clean > /dev/null 2>&1

	@make --silent -C include/libft clean

fclean : clean
	@rm -f ${NAME}
	@make --silent -C include/libft fclean

re : fclean all

.PHONY : all clean fclean re