/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 15:37:48 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:40:09 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (s && f)
	{
		res = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
		if (!res)
			return (NULL);
		while (i < ft_strlen((char *)s))
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}
