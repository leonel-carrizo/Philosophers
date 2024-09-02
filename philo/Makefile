# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 15:36:45 by lcarrizo          #+#    #+#              #
#    Updated: 2024/09/02 13:36:45 by lcarrizo         ###    ###london.com     #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################
NAME			= philo
INCLUDE			= includes/
UTILS_DIR		= utils/
SRC_DIR			= src/
BONUS_DIR		= bonus/
OBJ_DIR			= .obj/

SRCS_UTILS		= $(wildcard $(UTILS_DIR)*.c)
OBJ_UTILS		= $(addprefix $(OBJ_DIR)utils/, $(notdir $(SRCS_UTILS:.c=.o)))

SRCS			= $(shell find $(SRC_DIR) -name "*.c")
OBJ				= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

BONUS_SRCS		= $(shell find $(BONUS_DIR) -name "*.c")

#############################    COMMANDS   ##################################
CC				= cc
RM 				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)

################################    RULES    ###################################
.SILENT:

$(NAME):		$(OBJ) $(OBJ_UTILS)
				$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) -o $(NAME) -g
				@echo "so_long executable created!"

all:			$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o:		$(UTILS_DIR)%.c
				@mkdir -p $(OBJ_DIR)/utils
				$(CC) $(CFLAGS) -c $< -o $@

# create executables which can be debugged with gdb.
debug:
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -g
				@echo "Debugables Created!"

bonus:
				$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(NAME) -g
				@echo "so_long bonus created!"

clean:
				$(RM) $(OBJ_DIR)
				@echo "** clean so_long done!**"

fclean:			clean
				$(RM) $(NAME)
				@echo "** full clean done!**"

re:				fclean all

.PHONY:			all clean fclean re debug bonus
