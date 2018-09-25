/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ignorecomments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <pmotala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:39:49 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 09:51:56 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_ignorecomments(t_list *lst, char *start_comment,
								char *end_comment)
{
	int	lst_pos;

	lst_pos = -1;
	ft_rm_char(lst->content, '\n');
	if (ft_strequ(lst->content, start_comment) == 1)
	{
		while (lst)
		{
			ft_rm_char(lst->content, '\n');
			if (ft_strequ(lst->content, end_comment) == 1)
			{
				ft_rm_char(lst->content, '\n');
				if (lst->next != NULL)
					lst = lst->next;
				break ;
			}
			if (lst->next == NULL)
				break ;
			lst = lst->next;
		}
	}
	return (lst);
}
