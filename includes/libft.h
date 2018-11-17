/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 18:29:11 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 08:35:14 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf.h"

char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_strcut(const char *s, size_t i);
size_t			ft_strlen(const char *s);

char			*ft_itoa(long long int n);
char			*ft_itoa_base_unsigned(uintmax_t n, int base, int maj);
int				ft_isdigit(int c);
int				ft_isinstr(char *str, char c);

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_tabset(size_t len);
void			ft_memdel(void **ap);

#endif