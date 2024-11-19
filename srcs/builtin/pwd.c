#include "minishell.h"
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
	ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}
