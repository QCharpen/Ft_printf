#include "includes/ft_printf.h"

int		main()
{
	int		i;
	char	*str;

	str = NULL;
//	str = ft_strdup("Bonjour");
	ft_sprintf(&str, "Bonsoir %s", "LES AMIS");
	ft_printf("%s du soir%s\n", str, " Au revoir");
	ft_fprintf("lol", str);
	free(str);
}
