# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 15:55:02 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/03/14 15:55:06 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainedAnimal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD #-fsanitize=address,undefined
RM = rm -f

SRCS =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
D_OBJS = obj/
OBJS = $(addprefix $(D_OBJS), $(SRCS:.cpp=.o))
DEPS = $(addprefix $(D_OBJS), $(SRCS:.cpp=.d))

$(D_OBJS)%.o : %.cpp Makefile
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
