
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (s < d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "Je t'aime";
	char dest[] = "Beaucoup";
	
	ft_memmove(dest, src, 3);
	printf("%s", dest);
	return (0);
}*/
