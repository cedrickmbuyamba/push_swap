/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 08:46:13 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/06/22 13:20:39 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_verif(int fd, char **line, char **s)
{
	int		i;
	char	*tmperory;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmperory = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = tmperory;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[1];
	char			buff[BUFF_SIZE + 1];
	int				i;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if (i == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_verif(fd, line, s));
}
