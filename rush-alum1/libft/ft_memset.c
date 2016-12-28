/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 18:21:51 by mnicolas          #+#    #+#             */
/*   Updated: 2015/10/05 18:51:47 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cur;

	i = 0;
	cur = (unsigned char *)b;
	while (i < len)
	{
		cur[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
