#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret;

	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	ret = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&ret, new);
	}
	return (ret);
}
