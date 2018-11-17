/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:57:52 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 20:07:44 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, int i, char const *s2)
{
	char	*str;
	int		i2;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		str = ft_strdup(s1);
		return (str);
	}
	if (!(str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	i2 = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[i])
		str[i++] = s2[i2++];
	str[i] = '\0';
	return (str);
}
