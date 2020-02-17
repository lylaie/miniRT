/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:07:25 by audumont          #+#    #+#             */
/*   Updated: 2019/10/25 15:34:24 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_miniRT.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	size_t			index;

	dest = (unsigned char*)b;
	index = 0;
	while (index < len)
	{
		dest[index] = (unsigned char)c;
		index++;
	}
	return (void*)dest;
}
