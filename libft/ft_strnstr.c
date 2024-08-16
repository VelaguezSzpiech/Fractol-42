
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (big[i + j] == little[j] && little[j] && k < len)
			{
				j++;
				k++;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	return (0);
}*/
