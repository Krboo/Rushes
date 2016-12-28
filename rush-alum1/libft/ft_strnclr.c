/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 18:29:00 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:42:37 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnclr(char *s, size_t n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) - n + 1);
	if (res == NULL || s == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		res[i] = s[n];
		i++;
		n++;
	}
	return (res);
}
