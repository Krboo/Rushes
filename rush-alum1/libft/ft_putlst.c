/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 12:10:42 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:23:18 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list **alst)
{
	t_list	*temp;

	temp = *alst;
	while (temp != NULL)
	{
		if (temp->content)
			ft_putendl((char *)temp->content);
		temp = temp->next;
	}
}
