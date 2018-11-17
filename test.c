#include "includes/ft_printf.h"

int		main()
{
	int		i;

	ft_printf("%d, %i, %s, %x, %d, %o, %p, %d, %i, %s, %x, %d, %o, %p", 15, 20, "adf", 12, 54, 125, &i, 15, 20, "adf", 12, 54, 125, &i);
}
