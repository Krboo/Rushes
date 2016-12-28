/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/26 16:29:36 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:17:43 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUF 12

static int	ft_ifneg(char *res, int *n, int i)
{
	if (*n < 0 && *n > -2147483648)
	{
		res[0] = '-';
		*n *= -1;
		i = 1;
	}
	return (i);
}

static int	ft_sizeofnbr(char *res, int *n, int i)
{
	int		temp;

	temp = *n;
	if (*n == -2147483648)
	{
		res[0] = '-';
		res[10] = '8';
		res[11] = '\0';
		*n = 214748364;
		return (9);
	}
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	res[i] = '\0';
	return (i - 1);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * BUF);
	if (res == NULL)
		return (NULL);
	i = ft_ifneg(res, &n, i);
	if (n >= 0 && n < 10)
	{
		res[i] = n + '0';
		res[i + 1] = '\0';
		return (res);
	}
	else
	{
		i = ft_sizeofnbr(res, &n, i);
		while (n > 0)
		{
			res[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
	return (res);
}
