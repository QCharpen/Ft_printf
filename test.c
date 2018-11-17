#include "includes/ft_printf.h"

int		main()
{
	ft_printf("|aa %c, bb %c, cc %c, dd %c|", '\0', '\n', (char)564, 0);
}
