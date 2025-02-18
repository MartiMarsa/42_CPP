# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 15:58:02 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/02/18 15:58:04 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
RESET   := \033[0m

NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98
RM = rm -f

SRC = megaphone.cpp
F_OBJ = obj/
OBJS = $(addprefix $(F_OBJ), $(SRC:.cpp=.o))
DEPS = $(addprefix $(F_OBJ), $(SRC:.cpp=.o))

$(F_OBJ)%.o: %.cpp Makefile
	@$(CC) $(FLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p $(F_OBJ)

$(NAME): $(OBJS) $(DEPS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Te miro y te compilo.$(RESET)"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) -r obj

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)Te miro y te elimino.$(RESET)"

re: fclean all

.PHONY: all dir clean fclean re