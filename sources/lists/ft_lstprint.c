/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/29 21:35:10 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 01:45:40 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

void	ft_lstfprint(void **str, t_list *lst)
{
	t_list		*tmp;
	char		*ret;
	int			fd;

	if (access((char*)*str, W_OK))
	{
		if ((fd = open((char*)*str,
						O_CREAT | O_APPEND | O_WRONLY, 0770)))
		{
			tmp = lst;
			ret = NULL;
			while (tmp)
			{
				ret = ft_strjoin_free(ret, tmp->str);
				tmp = tmp->next;
			}
			write(fd, ret, ft_strlen(ret));
			ret ? free(ret) : 0;
		}
		else
			lst->size = 0;
	}
	else
		lst->size = 0;
}

void	ft_lstsprint(void **str, t_list *lst)
{
	t_list		*tmp;
	char		*ret;

	tmp = lst;
	ret = NULL;
	while (tmp)
	{
		ret = ft_strjoin_free(ret, tmp->str);
		tmp = tmp->next;
	}
	*str = ret;
}

void	ft_lstprint(void **fd, t_list *lst)
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
	print ? write(*((int*)fd[0]), print, ft_strlen(print)) : 0;
	print ? free(print) : 0;
}
