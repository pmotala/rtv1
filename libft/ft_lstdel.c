/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:16:31 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 15:49:50 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *add;

	temp = *alst;
	while (temp)
	{
		add = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = add;
	}
	*alst = NULL;
}
