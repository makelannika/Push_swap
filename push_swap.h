#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack_node
{
	int			value;
	int			index;
	struct	s_list_node	*next;
	struct  s_list_node     *prev;
} t_stack_node

#endif
