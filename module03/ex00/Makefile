# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 19:25:16 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/03/05 19:25:18 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
RESET   := \033[0m

NAME = ClapTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -std=c++98
RM = rm -f

SRC =	main.cpp \
		ClapTrap.cpp
D_OBJ = obj/
OBJS = $(addprefix $(D_OBJ), $(SRC:.cpp=.o))
DEPS = $(addprefix $(D_OBJ), $(SRC:.cpp=.d))

$(D_OBJ)%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p obj/

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dir clean fclean re