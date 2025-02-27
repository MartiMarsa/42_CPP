# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 19:28:29 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/02/20 19:28:30 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
RESET   := \033[0m

NAME = Account
CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98
RM = rm -f

SRC = 	Account.cpp \
		tests.cpp
D_OBJ = obj/
OBJS = $(addprefix $(D_OBJ), $(SRC:.cpp=.o))
DEPS = $(addprefix $(D_OBJ), $(SRC:.cpp=.d))

$(D_OBJ)%.o: %.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p $(D_OBJ)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Te miro y te compilo.$(RESET)"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) -r $(D_OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Te miro y te elimino.$(RESET)"

re: fclean all

.PHONY: all dir clean fclean re

