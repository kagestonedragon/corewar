/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:51:50 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:53:28 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "options.h"

static t_players    *init_player(int id)
{
    t_players       *player;

    if (!(player = (t_players *)ft_memalloc(sizeof(t_players))))
        printf("Ошибочка во время инита игрока");
    player->id = id;
    player->name = NULL;
    player->comment = NULL;
    player->code_size = 0;
    player->code = NULL;
    player->current_lives_num = 0;
    player->previous_lives_num = 0;
    player->next = NULL;

    return (player);
}

static int32_t      bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
    int32_t	        result;
	t_bool	        sign;
	int		        i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

static int32_t      parse_corewar_magic(int fd)
{
    size_t          size;
    uint8_t         buffer[4];

    size = read(fd, &buffer, 4);
    if (size == -1)
        printf('Read error');
    if (size < 4)
        printf('Invalid file error');
    return (bytecode_to_int32(buffer, 4));
}

static char		*read_player_name(int fd, size_t len)
{
	ssize_t	     size;
	char	    *buffer;

	if (!(buffer = ft_strnew(len)))
		prinf('Error');
	size = read(fd, buffer, len);
	if (size == -1)
		prinf('Read error');
	if (size < (ssize_t)len)
		printf('Error invalid file');
	return (buffer);
}

static uint8_t	*parse_player_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	if (!(buffer = malloc(len)))
		printf('Error init');
	size = read(fd, buffer, len);
	if (size == -1)
		printf('Read error');
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		printf('Error invalide file');
	return (buffer);
}

t_players           *parse_champion(const char *filename, int id)
{
    t_players       *player;
    int             fd;

    player = init_player(id);
    if ((fd = open(filename, O_RDONLY)) < 0)
        printf('Read error');
    if (parse_corewar_magic(fd) != COREWAR_EXEC_MAGIC)
        printf('Read error');
    player->name = read_player_name(fd, CHAMP_NAME_LENGTH);
    if (parse_corewar_magic(fd) != 0)
        printf('No NULL error');
    if ((player->code_size = parse_int32(fd)) < 0 ||
		player->code_size > CHAMP_CODE_MAX_SIZE)
		printf('Error invalide code size');
	player->comment = read_player_name(fd, COMMENT_LENGTH);
	if (parse_corewar_magic(fd) != 0)
		printf('No NULL error');
	player->code = parse_player_code(fd, (size_t)player->code_size);
	return (player);
}