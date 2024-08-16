
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c))
{
	char	*newstr;
	int		j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	j = 0;
	while (s[j])
	{
		newstr[j] = f(j, s[j]);
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
/*
char	*maj(unsigned int i, char c)
{
	char	*str;
	str = NULL;
	i = 0;
	c = str[i];
	while (str[i])
	{
		c = c - 32;
		i++;
	}
	return (str);
}
int	main(void)
{
	char *str = "salut";
 	char *newstr;
	int	i;
	
	i = 0;
	newstr = ft_strmapi(str, maj);
	printf("%s\n", newstr);
	free(newstr);
	return (0);
}*/
