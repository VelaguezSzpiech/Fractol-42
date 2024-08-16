
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lens;

	lens = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lens);
}
/*
int	main(void)
{
	const char	src[] = "Hello ";
	char	dest[] = "World";
	printf("%zu\n", ft_strlcpy(dest, src, 3));
	printf("%s", dest);
	return (0);
}*/
