/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:50:49 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 19:55:17 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/**
 * Game rules
 */
# define MAX_PLAYERS                    4
# define MEM_SIZE                       (MAX_PLAYERS * 1024)

/**
 * Champion file requirements
 */
# define COR_FILE_EXTENSION             ".cor"
# define COR_CHAMPION_NAME_LENGTH       128
# define COR_CHAMPION_COMMENTARY_LENGTH 2048
# define COR_BINARY_MAGIC_HEADER        0xea83f3
# define COR_CHAMPION_CODE_MAX_SIZE     (MEM_SIZE / 6)

/**
 * Error defines
 */
# define ERROR_OPEN_FILE_CODE           400
# define ERROR_READ_FILE_CODE           401
# define ERROR_MEMORY_ALLOCATE_CODE     402
# define ERROR_INPUT_OPTIONS_CODE       403

# define ERROR_OPEN_FILE                "Error opening file."
# define ERROR_READ_FILE                "Error reading file."
# define ERROR_MEMORY_ALLOCATE          "Error memory allocate."
# define ERROR_INPUT_OPTIONS            "Wrong input options."

/**
 * Dependencies headers
 */
# include "../dependencies/libft/includes/libft.h"

/**
 * Other headers
 */
# include "types.h"
# include "options.h"
# include <stdio.h> // отключить потом
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct                          s_champions {
    int8_t                              id;
    char                                *name;
    char                                *comment;
    int32_t                             code_size;
    uint8_t                             *code;
    int                                 last_live;
    int                                 current_lives_num;
    int                                 previous_lives_num;
    struct s_champions                  *next;
}                                       t_champions;

typedef struct                          s_corewar {
    t_options                           *options;
    t_champions                         *champions;
}                                       t_corewar;

/**
 * Identification 
 */
t_bool                                  is_cor_file(const char *filename);
t_bool                                  is_integer(const char *str);

/**
 * Converting
 */
int32_t                                 bytecode_to_int32(const uint8_t *bytecode, size_t size);

/**
 * Error management
 */
void                                    print_help();
void                                    terminate(const int error_code, const char *error, const char *explanation);


/**
 * Options parsing
 */
t_options                               *parse_options(int argc, char **argv);

/**
 * Champion parsing
 */
int32_t                                 read_champion_bytecode(int fd);
char                                    *read_champion_info(int fd, size_t len);
uint8_t                                 *read_champion_code(int fd, size_t len);


/**
 * Debug functions
 */
void                                    debug_champions(t_corewar *corewar);
void                                    debug_options(t_corewar *corewar);

#endif