
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	temp = s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "helcou";
	ft_bzero(str + 3, 3);
	printf("%s", str);
	return (0);
}*/
