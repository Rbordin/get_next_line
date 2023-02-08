
#include <stdlib.h>

int	ft_strlen(char *s1)
{
	static int	i;
	char		limit;

	limit = '\n';
	if (!s1)
		return ('\0');
	i = start;
	while (s1[i] != '\0' && s1[i] != limit)
		i++;
	return (i);
}

char	*substr(char *s1, int len)
{
	int	i;
	char	*res;
	char	stop;

	i = 0;
	stop = '\n';
	if (!s1 && !start && !stop)
		return (NULL);
	char *res = (char *)malloc(sizeof(ft_strlen(s1, start)));
	if (res == NULL)
		return (NULL);
	while (s[i++])
	{
		if (s1[i] != '\0' && s[i] != stop && i < len)
			((char *)res)[i] = s[i];
	}
	return (res);
}

char	str_clean(char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i] != '\n')
		s1[i] = '\0';
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		*BUFFER;
	int		step;
	static char	*tmp;

	if (fd = -1)
		return (NULL);
	step = read(fd, BUFFER, SIZE_MAX);
	tmp = BUFFER;
	while (tmp[i] != '\n')
		res[i] = tmp[i];
//	res = substr(tmp, step); 
	tmp = str_clean(BUFFER);
	return (res);	
}
