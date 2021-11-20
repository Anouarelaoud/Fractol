/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:38:25 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 14:45:26 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft1(char **str1, char **aux, char str2[5], int nbr_oct)
{
	str2[nbr_oct] = '\0';
	*aux = *str1;
	*str1 = NULL;
	*str1 = ft_strjoin(*aux, str2);
	free(*aux);
}

void	ft2(char **line, char **str1, char **aux, int i)
{
	*line = ft_strsub(*str1, 0, i);
	*aux = *str1;
	*str1 = NULL;
	*str1 = ft_strdup(*aux + i + 1);
	free(*aux);
}

int		get_next_line(int fd, char **line)
{
	static char		*str1[4864];
	char			str2[5];
	int				nbr_oct;
	int				i;
	char			*aux;

	i = 0;
	if (fd == -1 || !line || read(fd, str2, 0) < 0)
		return (-1);
	if (str1[fd] == NULL)
		str1[fd] = ft_strnew(0);
	while ((nbr_oct = read(fd, str2, 4)) > 0)
	{
		ft1(&str1[fd], &aux, str2, nbr_oct);
		if (ft_strchr(str2, '\n'))
			break ;
	}
	if (ft_strlen(str1[fd]) == 0)
		return (0);
	while (str1[fd][i] != '\0' && str1[fd][i] != '\n')
		i++;
	ft2(line, &str1[fd], &aux, i);
	return (1);
}
