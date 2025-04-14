# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 18:56:45 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/04/11 18:56:50 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -std=c++98
RM = rm -f

SRC = main.cpp
D_OBJS = obj/
OBJS = $(addprefix $(D_OBJS), $(SRC:.cpp=.o))
DEPS = $(addprefix $(D_OBJS), $(SRC:.cpp=.d))

$(D_OBJS)%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p obj/

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dir clean fclean re