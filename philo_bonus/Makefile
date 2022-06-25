NAME = philo_bonus

SRC = ft_atoi.c philo_action.c philos_utils.c error.c main.c philos_utils2.c

OBJ = $(SRC:.c=.o)

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