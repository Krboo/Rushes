/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 16:48:22 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:43:33 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
