/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:50:27 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/08 15:04:20 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
int	ft_strlen(char *s1)
{
	int		i;
	char	limit;

	limit = '\n';
	if (!s1)
		return ('\0');
	i = 0;
	while (s1[i] != '\0' && s1[i] != limit)
		i++;
	return (i + 1);
}

char	*ft_substr(char *s1, int len)
{
	int	i;
	char	*res;
	char	stop;

	i = 0;
	stop = '\n';
	if (!s1 && !stop)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] != '\0' && s1[i] != stop && i < len)
			((char *)res)[i] = s1[i];
		i++;
	}
	res[i] = '\n';
	res[i + 1] = '\0';
	return (res);
}

char	*ft_str_clean(char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i] != '\n')
		s1[i++] = '\0';
	s1[i] = '\0';
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		*BUFFER;
	int			step;
	static char	*tmp;

	if (fd == -1)
		return (NULL);
	step = read(fd, BUFFER, SIZE_MAX);
	tmp = BUFFER;
	res = ft_substr(tmp, step); 
	tmp = ft_str_clean(BUFFER);
	free(BUFFER);
	return (res);	
}
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
int	main()
{
	int	fd;
	char *res;

	fd = open("/Users/rbordin/Desktop/LINK_PLAYLIST_LEZIONI.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	return (0);
}
	
