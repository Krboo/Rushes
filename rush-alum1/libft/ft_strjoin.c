/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 16:26:39 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:39:32 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		res = (char *)malloc(sizeof(char) * size + 1);
		if (!res)
			return (NULL);
		i = 0;
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, s2);
		return (res);
	}
	else
		return (NULL);
}
