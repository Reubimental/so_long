#include "../../so_long.h"

int	error_msg(char *message)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	*nullptr_error(char *message)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	warning(char *message)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", message);
}