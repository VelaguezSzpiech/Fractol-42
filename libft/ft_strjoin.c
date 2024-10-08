
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (free((char *)s1), newstr);
}
/*
int	main(void)
{
	char	s1[] = "Hello ";
	char s2[] = "World";

	printf("%s", ft_strjoin(s1, s2));
	free(ft_strjoin(s1, s2));
	return (0);
}*/
