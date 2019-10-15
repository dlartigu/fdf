# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:53:03 by jcharrou          #+#    #+#              #
#    Updated: 2019/08/08 18:45:31 by dlartigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################
_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

NAME = fdf
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror
SRCS_PATH = SRCS/
MLX = -lmlx -framework OpenGL -framework AppKit
SRCS_NAME = ft_main_display.c\
			get_next_line.c\
			main.c\
			ft_valide_file.c\
			ft_fil_content.c\
			ft_int_tab.c\
			mlx.c\
			ft_ui.c\
			ft_filstruct.c\
			ft_freetab.c\
			ft_fdf_fil.c\
			ft_pixel_put.c\
			ft_altcolor.c\
			ft_ctrl.c\
			ft_colorcmd.c\
			ft_menu.c\
			ft_res.c\

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))
OBJ = $(SRCSLIB:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):		$(LIB) $(SRCS) $(OBJ) INCLUDES/fdf.h
				@gcc -o $(NAME) $(FLAG) $(SRCS) $(MLX) -L./libft -lft
				@echo "$(_GREEN)[OK]$(_BLUE) FDF generated"
				clear
				@echo "$(_RED)                                                     ▄████████ ████████▄     ▄████████"
				@echo "$(_RED)                                                    ███    ███ ███   ▀███   ███    ███"
				@echo "$(_RED)                                                    ███    █▀  ███    ███   ███    █▀ "
				@echo "$(_RED)                                                   ▄███▄▄▄     ███    ███  ▄███▄▄▄  "
				@echo "$(_RED)                                                  ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀  "
				@echo "$(_RED)                                                    ███        ███    ███   ███     "
				@echo "$(_RED)                                                    ███        ███   ▄███   ███     "
				@echo "$(_RED)                                                    ███        ████████▀    ███     "
				@echo "$(_RED)                                                                                    "
				@echo "$(_RED)    ███        ▄████████    ▄████████   ▄▄▄▄███▄▄▄▄           ▄████████  ▄██████▄     ▄████████    ▄████████  ▄█  ███▄▄▄▄      ▄████████ "
				@echo "$(_RED)▀█████████▄   ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄        ███    ███ ███    ███   ███    ███   ███    ███ ███  ███▀▀▀██▄   ███    ███ "
				@echo "$(_RED)   ▀███▀▀██   ███    █▀    ███    ███ ███   ███   ███        ███    █▀  ███    ███   ███    ███   ███    ███ ███▌ ███   ███   ███    █▀  "
				@echo "$(_RED)    ███   ▀  ▄███▄▄▄       ███    ███ ███   ███   ███       ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀   ███    ███ ███▌ ███   ███   ███        "
				@echo "$(_RED)    ███     ▀▀███▀▀▀     ▀███████████ ███   ███   ███      ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ▀███████████ ███▌ ███   ███ ▀███████████ "
				@echo "$(_RED)    ███       ███    █▄    ███    ███ ███   ███   ███        ███        ███    ███ ▀███████████   ███    ███ ███  ███   ███          ███ "
				@echo "$(_RED)    ███       ███    ███   ███    ███ ███   ███   ███        ███        ███    ███   ███    ███   ███    ███ ███  ███   ███    ▄█    ███ "
				@echo "$(_RED)   ▄████▀     ██████████   ███    █▀   ▀█   ███   █▀         ███         ▀██████▀    ███    ███   ███    █▀  █▀    ▀█   █▀   ▄████████▀  "
				@echo "$(_RED)                                                                                     ███    ███                                          "
$(LIB):
			@make -C libft

clean:
			@make -C libft clean

fclean: clean
			@rm -rf $(NAME)
			@make -C libft fclean
			@echo "$(_GREEN)[OK]$(_WHITE) All Objects deleted"

re: fclean all
