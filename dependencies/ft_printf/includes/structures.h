/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:59:56 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:47:18 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum{
	false,
	true
}	t_bool;

typedef struct			s_fl{
	int					sign;
	int					exponent;
	long long			integer_part;
	long double			fractional_part;
}						t_fl;

typedef struct			s_parts{
	unsigned long int	mantissa : 64;
	unsigned			exponent : 15;
	unsigned			sign : 1;
}						t_parts;

typedef union			u_fl_parts{
	long double			f;
	t_parts				bytes;
}						t_fl_parts;

typedef struct			s_sign{
	char				*value;
	int					length;
}						t_sign;

typedef struct			s_flag{
	t_bool				minus;
	t_bool				plus;
	t_bool				space;
	t_bool				zero;
	t_bool				hash;
}						t_flag;

typedef struct			s_arg{
	char				*value;
	int					length;
	int					base;
}						t_arg;

typedef struct			s_printf{
	int					fd;
	t_flag				flag;
	int					width;
	int					length;
	int					precision;
	int					type;
	t_sign				sign;
	t_arg				arg;
}						t_printf;

#endif
