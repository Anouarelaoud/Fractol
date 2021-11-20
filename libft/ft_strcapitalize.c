/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:22:27 by aait-el-          #+#    #+#             */
/*   Updated: 2018/10/17 21:23:57 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] <= 122 && str[i] >= 97))
			str[i] -= 32;
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
				str[i] == '\t')
		{
			if (str[i + 1] < 123 && str[i + 1] > 96)
				str[i + 1] = str[i + 1] - 32;
		}
		i++;
	}
	return (str);
}