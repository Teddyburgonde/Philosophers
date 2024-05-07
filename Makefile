#=================== NAME ===================#

NAME = philosophers

#================ COMPILATOR ================#
CC = clang

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -I. -g 
LDFLAGS = -lpthread

#============= MANDATORY SOURCES =============#

SRCS = error.c \
		utils_for_parsing.c \
		parsing_number.c \
		philo_is_dead.c \
		routine.c \
		time.c \
		main.c 


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