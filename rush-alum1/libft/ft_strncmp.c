/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/03 16:43:58 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/24 17:32:47 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && i < (n - 1))
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < 0 || s1[i] > 127)
				return (s2[i] - s1[i]);
			else
				return (s1[i] - s2[i]);
		}
		else
			i++;
	}
	if (s1[i] < 0 || s1[i] > 127)
		return (s2[i] - s1[i]);
	else
		return (s1[i] - s2[i]);
}
