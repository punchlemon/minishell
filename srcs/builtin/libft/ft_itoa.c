/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:19:03 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 20:03:50 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse(char *temp)
{
	char	*ans;
	int		i;
	int		len;

	len = (int)ft_strlen((const char *)temp);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	if (ans == NULL)
		return (NULL);
	while (len-- > 0)
	{
		ans[i] = temp[len];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

void	minus(int *sign, int *n)
{
	if (*n < 0)
	{
		*sign *= -1;
		*n *= -1;
	}
	return ;
}

char	*check1_zero_intmin(int n)
{
	if (n == -2147483648)
	{
		return (reverse("8463847412-"));
	}
	else
	{
		return (reverse("0"));
	}
}

char	*ft_itoa(int n)
{
	char	temp[12];
	int		sign;
	int		i;

	if (n == 0 || n == -2147483648)
		return (check1_zero_intmin(n));
	sign = 1;
	if (n < 0)
		minus(&sign, &n);
	i = 0;
	while (i < 12)
	{
		temp[i] = '\0';
		i++;
	}
	i = 0;
	while (n)
	{
		temp[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign == -1)
		temp[i] = '-';
	return (reverse(temp));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }
