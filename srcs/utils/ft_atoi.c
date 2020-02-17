/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:52:11 by audumont          #+#    #+#             */
/*   Updated: 2019/10/25 16:17:13 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_miniRT.h"

static int			ft_sign(char c)
{
	if (c == '+')
		return (1);
	else
		return (-1);
}

static int			ft_long(unsigned int result, int sign)
{
	if (sign == 1)
		return (-1);
	else if (result != 2147483648)
		return (0);
	else
		return (-214783648);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = ft_sign(str[i++]);
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (result > 2147483647)
			return (ft_long(result, sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
