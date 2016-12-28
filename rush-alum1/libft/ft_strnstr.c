/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 15:19:18 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:43:51 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (n < ft_strlen((char *)s2))
		return (NULL);
	while (i < n && s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i - j]);
	return (NULL);
}
