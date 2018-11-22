/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/29 21:35:10 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:57:49 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

void	ft_lstfprint(void **str, t_list *lst)
{
//	if (access((char*)str))
}

void	ft_lstsprint(void **str, t_list *lst)
{
	t_list		*tmp;
	int			i;
	char		*ret;

	i = 0;
	tmp = lst;
	ret = NULL;
	while (tmp)
	{
		ret = ft_strjoin_free(ret, tmp->str);
		tmp = tmp->next;
	}
	*str = ret;
}

void	ft_lstprint(int fd, t_list *lst)
{
	t_list		*tmp;
	char		*print;

	tmp = lst;
	print = NULL;
	while (tmp)
	{
		print = ft_strjoin_free(print, tmp->str);
		tmp = tmp->next;
	}
	print ? write(fd, print, ft_strlen(print)) : 0;
}
