NAME = philo_bonus

SRC = main.c ft_atoi.c error.c

OBJ = main.o ft_atoi.o error.o

CC_FLAGS = -Wall -Wextra -Werror -pthread

CC = cc

HEADER = philo_bonus.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all