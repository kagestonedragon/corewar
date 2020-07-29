/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:51:50 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 20:09:55 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static t_champions    *init_champion(int id)
{
    t_champions       *champion;

    if (!(champion = (t_champions *)ft_memalloc(sizeof(t_champions))))
        terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Champion initialization failed.");
    champion->id = id;
    champion->name = NULL;
    champion->comment = NULL;
    champion->code_size = 0;
    champion->code = NULL;
    champion->current_lives_num = 0;
    champion->previous_lives_num = 0;
    champion->next = NULL;

    return (champion);
}

t_champions			*parse_champion(const char *filename, int id)
{
    t_champions		*champion;
    int             fd;

    champion = init_champion(id);
    if ((fd = open(filename, O_RDONLY)) < 0)
        terminate(ERROR_OPEN_FILE_CODE, ERROR_OPEN_FILE, "Error opening champion file.");
    if (read_bytecode(fd) != COR_BINARY_MAGIC_HEADER)
        terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is missing a magic header.");
    champion->name = read_champion_info(fd, COR_CHAMPION_NAME_LENGTH);
    if (read_bytecode(fd) != 0)
        terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is missing a check point.");
    if ((champion->code_size = read_bytecode(fd)) < 0 ||
		champion->code_size > COR_CHAMPION_CODE_MAX_SIZE)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file have invalid code size.");
	champion->comment = read_champion_info(fd, COR_CHAMPION_COMMENTARY_LENGTH);
	if (read_bytecode(fd) != 0)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is missing a check point.");
	champion->code = read_champion_code(fd, (size_t)champion->code_size);
	
	return (champion);
}

void				add_champion(t_champions **champions, t_champions *new, int id)
{
	t_champions		*current;

	if (champions && new)
	{
		if (*champions)
		{
			current = *champions;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*champions = new;
	}
}
*/