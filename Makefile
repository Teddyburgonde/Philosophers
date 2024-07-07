#=================== NAME ===================#

NAME = philo

#================ COMPILATOR ================#
CC = clang

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -I. -g
LDFLAGS = -lpthread

#============= MANDATORY SOURCES =============#

SRCS =	src/initialization.c \
		src/parsing_numbers.c \
		src/philo_is_dead.c \
		src/routine.c \
		src/time.c \
		src/manage_thread.c \
		src/print.c \
		src/main.c \
		utils/manage_philosophers_utils.c \
		utils/routine_utils.c \
		utils/memory_utils.c \
		utils/parsing_utils.c \


#============ TRANSFORM .c TO .o ============#

OBJS=$(SRCS:.c=.o)

#================ UTILS PART ================#

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 