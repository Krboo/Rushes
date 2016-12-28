/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/03 15:52:38 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:39:50 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	end = i;
	while (src[i - end] && i < size - 1)
	{
		dst[i] = src[i - end];
		i++;
	}
	if (end < size)
		dst[i] = '\0';
	return (end + ft_strlen((char *)src));
}
