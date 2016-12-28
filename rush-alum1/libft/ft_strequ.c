/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 16:01:11 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/23 13:45:12 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (ft_strlen((char *)s1) != ft_strlen((char *)s2))
		return (0);
	else
	{
		i = 0;
		while (i < ft_strlen((char *)s1))
		{
			if (s1[i] != s2[i])
				return (0);
			else
				i++;
		}
		return (1);
	}
}
