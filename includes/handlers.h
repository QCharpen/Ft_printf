/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handlers.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 06:55:06 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 10:04:29 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H
# include "ft_printf.h"

typedef struct s_list	t_list;
typedef struct s_flags	t_flags;
typedef struct			s_handlers {
	char				conv;
	t_list				*(*fct_handle)(t_flags*, va_list);
}						t_handlers;

t_list					*handle(char **str, va_list args, int i);
t_list					*select_conv(t_flags *spec, va_list args);
t_list					*handle_percent(t_flags *spec, va_list args);
t_list					*handle_char(t_flags *spec, va_list args);
t_list					*handle_str(t_flags *spec, va_list args);
t_list					*handle_p(t_flags *spec, va_list args);
t_list					*handle_signed_int(t_flags *spec, va_list args);
t_list					*handle_unsigned_int(t_flags *spec, va_list args);
t_list					*handle_hex(t_flags *spec, va_list args);
t_list					*handle_oct(t_flags *spec, va_list args);
t_list					*zeroprec(t_flags *spec);

#endif
