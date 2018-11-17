/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lists.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 18:23:59 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 07:22:14 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "ft_printf.h"

typedef struct s_list	t_list;

struct			s_list
{
	char	*str;
	int		size;
	t_list	*next;
};

void			ft_lstaddend(t_list **alst, t_list *nxt);
void			ft_lstdel(t_list **alst);
t_list			*ft_lstnew(char *str, size_t len);
size_t			ft_lstlen(t_list *list);
void			ft_lstprint(t_list *lst);

#endif