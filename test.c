#include "includes/ft_printf.h"

int		main()
{
	int		i;
	char	*str;

	str = NULL;
//	str = ft_strdup("Bonjour");
//	ft_sprintf(&str, "Bonsoir %s", "LES AMIS");
//	ft_printf("%s du soir%s |%c", str, " Au revoir", NULL);
//	ft_fprintf("lol", str);
//	free(str);
//

	printf("|%d|\n", ft_printf("%s %s %s\n", "this", "is", "sparta"));
	printf("|%d|", printf("%s %s %s\n", "this", "is", "sparta"));
}
