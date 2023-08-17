#ifndef LIST_H
# define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list {
	char			*data;
	struct s_list	*next;
	struct s_list	*prev;
	
}	list;

list	*new_node(char *data);
void	add_back(list **head, list *node);
void	add_front(list **head, list *node);
void	remove_node(list **head, list *node);
void	sort_list(list **head);
void	swap_nodes(list **head, list *node1, list *node2);
void	free_list(list **head);
void	print_list(list **head);
size_t	list_size(list **head);

#endif