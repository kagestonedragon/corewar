/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_power.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:18:25 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 14:18:39 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		p_power(int value, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power % 2 == 0)
			return (value * value * p_power(value, power - 2));
		else
			return (value * p_power(value, power - 1));
	}
}
