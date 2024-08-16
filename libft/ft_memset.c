
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char str[] = "coucou";
	ft_memset(str, 'A', 2);
	printf("%s", str);
	return (0);
}*/
