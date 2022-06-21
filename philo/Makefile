NAME = philo

SRC = main.c ft_atoi.c philo_action.c philos_utils.c error.c philos_utils2.c

OBJ = main.o ft_atoi.o philo_action.o philos_utils.o error.o philos_utils2.o

CC_FLAGS = -Wall -Wextra -Werror -pthread

CC = cc

HEADER = philo.h

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