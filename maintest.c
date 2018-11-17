
#include "includes/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_strdiff(char *str1, char *str2)
{
	int		i = 0;

	while (str1[i] && str2[i])
	{
		printf("%d\n", str1[i] - str2[i]);
		i++;
	}
	if (!str1[i])
		printf("str1 end ");
	if(!str2[i])
		printf("str2 end");
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		exit(1);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	tmp = ft_strnew(strlen(s1) + strlen(s2));
	strcat(strcpy(tmp, s1), s2);
	return (tmp);
}

void	ft_connect_stdout(int *pfd, int *save)
{
	*save = dup(1);
	if (pipe(pfd) == -1)
		exit(1);
	if (dup2(pfd[1], 1) == -1)
		exit(1);
}

#define READ_SIZE 64

char	*ft_get_stdout(int *pfd, int *save)
{
	char	*rslt;
	char	*tmp;
	char	buff[READ_SIZE + 1];

	fflush(stdout);
	rslt = ft_strnew(0);
	close(pfd[1]);
	close(1);
	bzero(buff, READ_SIZE + 1);
	while (read(pfd[0], buff, READ_SIZE) > 0)
	{
		tmp = rslt;
		rslt = ft_strjoin(tmp, buff);
		free(tmp);
		bzero(buff, READ_SIZE + 1);
	}
	close(pfd[0]);
	dup2(*save, 1);
	close(*save);
	return (rslt);
}


int		main(int ac, char **av)
{
/*
	wchar_t		warg[4];
	s[0] = 'a';
	s[1] = 0xdc00;
	s[2] = 0x81000;
	s[3] = '\0';
*/

	int		pfd[2];
	int		save;
	char	*test1;
	char	*test2;
	int		len1;
	int		len2;

	char	*str = av[1];
	int		arg;

//	setlocale(LC_ALL, "");

	ft_connect_stdout(pfd, &save);
	len1 = ft_printf(str, arg);
	test1 = ft_get_stdout(pfd, &save);

	ft_connect_stdout(pfd, &save);
	len2 = printf(str, arg);
	test2 = ft_get_stdout(pfd, &save);

	printf("strlen1 %lu, strlen2 %lu\n", strlen(test1), strlen(test2));
	printf("strdiff:");
	ft_strdiff(test1, test2);

	printf("\n|%d|, |%d|\n", len1 != len2, strcmp(test1, test2));
	printf("|%d|, |%d|\n", len1, len2);
	printf("|%s|, |%s|\n", test1, test2);

	return 0;
}


