#=================== NAME ===================#

NAME = philosophers

#================ COMPILATOR ================#
CC = clang

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -I. -g
LDFLAGS = -lpthread

#============= MANDATORY SOURCES =============#

SRCS = error.c \
		initialization.c \
		parsing_number.c \
		philo_is_dead.c \
		routine.c \
		time.c \
		manage_thread.c \
		print.c \
		main.c \
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