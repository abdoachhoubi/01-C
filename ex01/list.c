#include "list.h"

list	*new_node(char *data)
{
	list	*node;

	node = malloc(sizeof(list));
	if (!node)
		return (NULL);
	node->data = strdup(data);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(list **head, list *node)
{
	list	*tmp;

	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	add_front(list **head, list *node)
{
	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	node->next = *head;
	(*head)->prev = node;
	*head = node;
}

void	remove_node(list **head, list *node)
{
	list	*tmp;

	if (!head || !node)
		return ;
	if (*head == node)
	{
		*head = node->next;
		if (*head)
			(*head)->prev = NULL;
		free(node->data);
		free(node);
		return ;
	}
	tmp = *head;
	while (tmp && tmp->next != node)
		tmp = tmp->next;
	if (!tmp)
		return ;
	tmp->next = node->next;
	if (node->next)
		node->next->prev = tmp;
	free(node->data);
	free(node);
}

void	swap_nodes(list **head, list *node1, list *node2)
{
	list	*tmp;

	if (!head || !node1 || !node2)
		return ;
	if (node1 == node2)
		return ;
	if (node1->next == node2)
	{
		remove_node(head, node1);
		add_front(head, node1);
		return ;
	}
	if (node2->next == node1)
	{
		remove_node(head, node2);
		add_front(head, node2);
		return ;
	}
	tmp = node1->next;
	remove_node(head, node1);
	add_front(head, node1);
	remove_node(head, node2);
	add_front(head, node2);
	node1->next = node2->next;
	node2->next = tmp;
}

void	free_list(list **head)
{
	list	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->data);
		free(tmp);
	}
}

void	print_list(list **head)
{
	list	*tmp;

	if (!head || !*head)
		return ;
	tmp = *head;
	printf("[ ");
	while (tmp)
	{
		printf("(%s) ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}

void	sort_list(list **head)
{
	list	*tmp;
	list	*tmp2;
	char	*swap;
	size_t	len;

	if (!head || !*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (strlen(tmp->data) > strlen(tmp2->data))
				len = strlen(tmp->data);
			else
				len = strlen(tmp2->data);
			if (strncmp(tmp->data, tmp2->data, len) > 0)
			{
				swap = tmp->data;
				tmp->data = tmp2->data;
				tmp2->data = swap;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
size_t	list_size(list **head)
{
	list	*tmp;
	size_t	size;

	if (!head || !*head)
		return (0);
	tmp = *head;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
