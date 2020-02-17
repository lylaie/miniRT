#include "../../include/ft_miniRT.h"

int		ft_intlen_base(unsigned int nb, char *base)
{
	size_t	len_str;
	int		len_nb;

	len_str = ft_strlen(base);
	len_nb = 0;
	//printf("nbr: %d\n", nb);
	while (nb >= (unsigned int)len_str)
	{
		nb = nb / (unsigned int)len_str;
		len_nb++;
	}
	len_nb++;
	return (len_nb);
}
