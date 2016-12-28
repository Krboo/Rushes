/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/03 16:43:58 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/23 11:29:29 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (ft_strlen((char *)s1) != ft_strlen((char *)s2))
		return (ft_strlen((char *)s1) - ft_strlen((char *)s2));
	else
	{
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			else
				i++;
		}
		return (0);
	}
}
