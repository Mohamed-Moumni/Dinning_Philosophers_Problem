NAME = philo_bonus

SRC = ft_atoi_bonus.c philo_action_bonus.c philos_utils_bonus.c error_bonus.c main_bonus.c philos_utils2_bonus.c

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