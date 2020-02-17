/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:02:58 by audumont          #+#    #+#             */
/*   Updated: 2019/10/25 15:35:39 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_miniRT.h"

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
