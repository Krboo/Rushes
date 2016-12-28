/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 18:55:54 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/23 10:55:05 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned char	x;

	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	x = (unsigned char)c;
	while (i < n && ptr2[i] != x)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	if (ptr2[i] == x)
		return (&dst[i + 1]);
	else
		return (NULL);
}
