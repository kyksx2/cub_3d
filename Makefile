NAME = cub_3d

GREEN=\033[1;32m

YELLOW=\033[1;33m

RESET=\033[0m

CFLAGS = -Wall -Wextra -Werror -g

SRC = 	main.c \
		src/parsing/parse_map.c \
		src/parsing/create_map.c \
        src/parsing/check_walls.c \
        src/parsing/open_map.c \

MLX = ./mlx_linux/libmlx.a

LIBFT = include/libft/libft.a

HEAD = -I include/libft -I include/mlx_linux

OBJ = $(SRC:.c=.o)

all : ${NAME}

${NAME}: ${OBJ} ${MLX} ${LIBFT}
	cc ${CFLAGS} ${OBJ} -L include/libft -lft -L include/mlx_linux -lmlx -lXext -lX11 -lm -lz -o ${NAME}
	@echo ""
	@echo ""
	@echo "${YELLOW}                                               WELCOME TO                                             ${RESET}"
	@echo "${GREEN}=======================================================================================================${RESET}"
	@echo "${GREEN}=======================================================================================================${RESET}"
	@echo "${GREEN}==                                                                                                   ==${RESET}"
	@echo "${GREEN}==       #############   ####     ####   ##########                 ############   #########         ==${RESET}"
	@echo "${GREEN}==       #############   ####     ####   ###########                ############   ##########        ==${RESET}"
	@echo "${GREEN}==       ####            ####     ####   ###      ###                        ###   ###     ###       ==${RESET}"
	@echo "${GREEN}==       ####            ####     ####   ###########                  ##########   ###     ###       ==${RESET}"
	@echo "${GREEN}==       ####            ####     ####   ###########                  ##########   ###     ###       ==${RESET}"
	@echo "${GREEN}==       ####            ####     ####   ###      ###                        ###   ###     ###       ==${RESET}"
	@echo "${GREEN}==       #############   #############   ###########   ###########  ############   ##########        ==${RESET}"
	@echo "${GREEN}==       #############   #############   ##########    ###########  ############   #########         ==${RESET}"
	@echo "${GREEN}==                                                                                                   ==${RESET}"
	@echo "${GREEN}=======================================================================================================${RESET}"
	@echo "${GREEN}=======================================================================================================${RESET}"
	@echo ""
	@echo ""

%.o: %.c
	cc ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< ${HEAD} -o $@

${MLX} :
	@make -C include/mlx_linux --silent

${LIBFT} :
	@make -C include/libft --silent

clean :
	@rm -f ${OBJ}
	@make --silent -C include/mlx_linux clean
	@make --silent -C include/libft clean

fclean : clean
	@rm -f ${NAME}
	@make --silent -C include/libft fclean

re : fclean all

.PHONY : all clean fclean re