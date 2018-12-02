/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/29 21:35:10 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 16:40:58 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

static	t_list	*lstjoin(t_list *lst1, t_list *lst2)
{
	t_list	*rst;
	int		i;
	int		j;

	rst = ft_memalloc(sizeof(*rst));
	rst->str = ft_memalloc(sizeof(rst->str) * (lst1->size + lst2->size + 1));
	i = 0;
	j = 0;
	while (i < lst1->size)
	{
		rst->str[i] = lst1->str[i];
		i++;
	}
	while (j < lst2->size)
		rst->str[i++] = lst2->str[j++];
	rst->str[i] = '\0';
	rst->size = lst1->size + lst2->size;
	return (rst);
}

static t_list	*lstjoin_free(t_list *lst)
{
	t_list	*rst;
	t_list	*tmp;

	rst = lst;
	if (lst->next)
	{
		rst = lstjoin(lst, lst->next);
		lst = lst->next;
	}
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		rst = lstjoin(rst, lst);
	}
	return (rst);
}

int			ft_lstfprint(void **str, t_list *lst)
{
	t_list		*tmp;
	int			fd;

	if (access((char*)*str, W_OK))
	{
		if ((fd = open((char*)*str,
						O_CREAT | O_APPEND | O_WRONLY, 0770)))
		{
			tmp = lstjoin_free(lst);
			write(fd, tmp->str, tmp->size);
		}
		else
			lst->size = 0;
	}
	else
		lst->size = 0;
	return (tmp->size);
}

int			ft_lstsprint(void **str, t_list *lst)
{
	t_list		*tmp;
	char		*ret;

	tmp = lst;
	ret = NULL;
	while (tmp)
	{
		tmp = lstjoin_free(lst);
	}
	*str = tmp->str;
	return (tmp->size);
}

int		ft_lstprint(void **fd, t_list *lst)
{
	t_list		*tmp;

	tmp = lst;
	tmp = lstjoin_free(lst);
	write(*((int*)fd[0]), tmp->str, tmp->size);
	return (tmp->size);
}
