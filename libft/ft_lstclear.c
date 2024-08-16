
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	size_t	size;

	size = ft_lstsize(*lst);
	temp = *lst;
	while (size > 0)
	{
		temp = *lst;
		*lst = (*lst)->next;
		(*del)(temp->content);
		free(temp);
		size--;
	}
	*lst = NULL;
}
