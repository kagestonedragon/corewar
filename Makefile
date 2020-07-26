########################################################
#@@@-------------GENERATED BY AUTO_MAKE-------------@@@#
#@@                                                  @@#
#@  https://github.com/kagestonedragon/auto_make_php  @#
########################################################

NAME = corewar

GCC = gcc

GCC_FLAGS = 

OBJ_PATH = objects/

INCLUDE_INCLUDES = includes/

SOURCES_PATH = sources/
SOURCES_MISCELLANEOUS_PATH = sources/miscellaneous/
SOURCES_MISCELLANEOUS_PARSING_PATH = sources/miscellaneous/parsing/
SOURCES_FILES = \
			main.c
SOURCES_MISCELLANEOUS_FILES = \
			ft_is_cor_file.c\
			ft_is_integer.c
SOURCES_PARSING_FILES = \
			flags.c\
			champion.c\
			options.c

OBJ_SOURCES_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_FILES:.c=.o))
OBJ_SOURCES_MISCELLANEOUS_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_MISCELLANEOUS_FILES:.c=.o))
OBJ_SOURCES_MISCELLANEOUS_PARSING_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_MISCELLANEOUS_PARSING_FILES:.c=.o))

OBJECTS = $(OBJ_SOURCES_CORE) $(OBJ_SOURCES_MISCELLANEOUS_CORE) $(OBJ_SOURCES_MISCELLANEOUS_PARSING_CORE) 

all: $(NAME)

$(NAME): $(OBJECTS)
		make -C dependencies/libft
		@($(GCC) $(GCC_FLAGS) -o $(NAME) $(OBJECTS) -L dependencies/libft/ -lft)
		@(echo "^[[0;92m"$(NAME) "was created!^[[0;0m")

clean:
		make clean -C dependencies/libft
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "^[[0;91mAll object files have been deleted!^[[0;0m")

fclean: clean
		make fclean -C dependencies/libft
		@(/bin/rm -f $(NAME))
		@(echo "^[[0;91m"$(NAME) "has been deleted!^[[0;0m")

re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(SOURCES_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDE_INCLUDES) -c $< -o $@)
		(echo "^[[0;93m"$< "->" $@"^[[0;0m")

objects/%.o: $(SOURCES_MISCELLANEOUS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDE_INCLUDES) -c $< -o $@)
		(echo "^[[0;93m"$< "->" $@"^[[0;0m")

objects/%.o: $(SOURCES_MISCELLANEOUS_PARSING_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDE_INCLUDES) -c $< -o $@)
		(echo "^[[0;93m"$< "->" $@"^[[0;0m")

