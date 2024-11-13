#include "export.h"

int	is_alpha_under(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}

int	is_alpha_num_under(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

int	is_valid_key(char *key)
{
	if (!is_alpha_under(*key))
		return (0);
	key++;
	if (!is_alpha_num_under(*key) && *key != '\0')
		return (0);
	key++;
	while (*key)
	{
		if (!is_alpha_num_under(*key))
			return (0);
		key++;
	}
	return (1);
}

void	malloc_error_exit(void)
{
	write(2, "Error: malloc\n", 14);
	exit(1);
}
