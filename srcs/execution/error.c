/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:32 by hnakayam          #+#    #+#             */
/*   Updated: 2024/11/17 13:50:36 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operation_error(char *str)
{
	write(2, "Error: ", strlen("Error: "));
	write(2, str, strlen(str));
	write(2, ": ", strlen(": "));
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", strlen("\n"));
	return (1);
}
