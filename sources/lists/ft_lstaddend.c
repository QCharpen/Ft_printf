/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:56:49 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/29 21:15:22 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

void	ft_lstaddend(t_list **alst, t_list *nxt)
{
	t_list	*curr;

	if (!(*alst))
		*alst = nxt;
	else
	{
		curr = *alst;
		while ((curr)->next)
			(curr) = (curr)->next;
		(curr)->next = nxt;
	}
}
