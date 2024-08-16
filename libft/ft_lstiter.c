
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size;

	size = ft_lstsize(lst);
	while (size > 0)
	{
		(*f)(lst->content);
		lst = lst->next;
		size--;
	}
}
