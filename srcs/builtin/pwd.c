#include "builtin.h"

int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}
