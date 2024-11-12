#include "minishell.h"

int	operation_error(char *str)
{
	write(2, "Error: ", strlen("Error: "));
	write(2, str, strlen(str));
	write(2, ": ", strlen(": "));
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", strlen("\n"));;
	return (1);
}