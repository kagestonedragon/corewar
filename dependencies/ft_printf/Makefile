NAME = libftprintf.a

GCC = gcc

GCC_FLAGS = -Wall -Wextra -Werror

AR = ar
AR_FLAGS = rcs

SRC_PATH = sources
OBJ_PATH = objects/
INC_PATH = includes

GCC_INCLUDE = -I $(INC_PATH)

SRC_PATH = sources/
SRC_CALCULATING_PATH = sources/calculating/
SRC_COLLECTING_PATH = sources/collecting/
SRC_MISCELLANEOUS_PATH = sources/miscellaneous/
SRC_PARSING_PATH = sources/parsing/

SRC_FILES = ft_dprintf.c ft_printf.c 
SRC_CALCULATING_FILES = calculating.c get_pieces.c 
SRC_COLLECTING_FILES = address_collecting.c character_collecting.c collecting.c decimal_collecting.c float_collecting.c hexadecimal_collecting.c octadecimal_collecting.c percent_collecting.c rainbow_collecting.c string_collecting.c unsigned_collecting.c 
SRC_MISCELLANEOUS_FILES = new_string.c p_atoi.c p_bzero.c p_itoa_base.c p_power.c p_strcat.c p_strlen.c to_lower.c 
SRC_PARSING_FILES = flag_parsing.c length_parsing.c parsing.c precision_parsing.c type_parsing.c width_parsing.c 

OBJ__CORE = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))
OBJ_CALCULATING_CORE = $(addprefix $(OBJ_PATH), $(SRC_CALCULATING_FILES:.c=.o))
OBJ_COLLECTING_CORE = $(addprefix $(OBJ_PATH), $(SRC_COLLECTING_FILES:.c=.o))
OBJ_MISCELLANEOUS_CORE = $(addprefix $(OBJ_PATH), $(SRC_MISCELLANEOUS_FILES:.c=.o))
OBJ_PARSING_CORE = $(addprefix $(OBJ_PATH), $(SRC_PARSING_FILES:.c=.o))

OBJECTS = $(OBJ__CORE) $(OBJ_CALCULATING_CORE) $(OBJ_COLLECTING_CORE) $(OBJ_MISCELLANEOUS_CORE) $(OBJ_PARSING_CORE) 

all: $(NAME)

$(NAME): $(OBJECTS)
		@($(AR) $(AR_FLAGS) $(NAME) $(OBJECTS))
		@(ranlib $(NAME))
		@(echo $(NAME) "was created!")

clean:
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "All objects files have been deleted!")

fclean: clean
		@(/bin/rm -f $(NAME))
		@(echo $(NAME) "has been deleted!")

re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(SRC_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_CALCULATING_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_COLLECTING_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_MISCELLANEOUS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_PARSING_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

