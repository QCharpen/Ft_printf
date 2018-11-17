/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 16:09:48 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 18:20:35 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	ret = ft_inner_printf(args, format);
	va_end(args);
	return (ret);
}

int	ft_inner_printf(va_list args, const char *format)
{
	char		*str;
	int			i;
	t_list		*list;

	str = (char*)format;
	i = 0;
	list = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_lstaddend(&list, handle(&str, args, i + 1));
			i = -1;
		}
		i++;
	}
	if (i > 0)
		ft_lstaddend(&list, ft_lstnew(ft_strcut(str, i), i));
	ft_lstprint(list);
	return (ft_lstlen(list));
}
