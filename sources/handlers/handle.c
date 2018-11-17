/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 06:53:41 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 07:24:36 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/handlers.h"

t_list				*handle(char **str, va_list args, int a)
{
	t_flags		*spec;
	int			i;

	*str = &((*str)[a]);
	i = 0;
	while ((*str)[i] && is_valid((*str)[i]) && !is_conv((*str)[i]))
		i++;
	if (!(*str)[i] || !is_conv((*str)[i]))
	{
		*str = &((*str)[i]);
		return (ft_lstnew(NULL, -1));
	}
	i++;
	spec = parse(*str);
	*str = &((*str)[i]);
	return (select_conv(spec, args));
}

static t_handlers	tabinit(char conv, t_list *(*fct)(t_flags*, va_list))
{
	t_handlers	ptr;

	ptr.conv = conv;
	ptr.fct_handle = fct;
	return (ptr);
}

t_list				*select_conv(t_flags *spec, va_list args)
{
	t_handlers	tab_handlers[14];
	int			i;

	tab_handlers[0] = tabinit('%', &handle_percent);
	tab_handlers[1] = tabinit('c', &handle_char);
	tab_handlers[2] = tabinit('s', &handle_str);
	tab_handlers[3] = tabinit('d', &handle_signed_int);
	tab_handlers[4] = tabinit('D', &handle_signed_int);
	tab_handlers[5] = tabinit('i', &handle_signed_int);
	tab_handlers[6] = tabinit('u', &handle_unsigned_int);
	tab_handlers[7] = tabinit('U', &handle_unsigned_int);
	tab_handlers[8] = tabinit('o', &handle_oct);
	tab_handlers[9] = tabinit('O', &handle_oct);
	tab_handlers[10] = tabinit('x', &handle_hex);
	tab_handlers[11] = tabinit('X', &handle_hex);
	tab_handlers[12] = tabinit('p', &handle_p);
	i = -1;
	while (++i < 13)
	{
		if (tab_handlers[i].conv == spec->conv)
			return (tab_handlers[i].fct_handle(spec, args));
	}
	return (NULL);
}