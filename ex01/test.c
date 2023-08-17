#include "list.h"

int	main(int ac, char **av)
{
	list	*head;
	list	*node;
	int		i;

	head = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		node = new_node(av[i]);
		add_back(&head, node);
		i++;
	}
	printf("List size: %zu\n", list_size(&head));
	printf("List before sorting:\t");
	print_list(&head);
	sort_list(&head);
	printf("List after sorting:\t");
	print_list(&head);
	return (0);
}
