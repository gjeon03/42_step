#include "push_swap.h"

t_stack_ls	*stack_lsnew(int data)
{
	t_stack_ls	*new;

	if (!(new = malloc(sizeof(t_stack_ls))))
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void		stack_lsadd_front(t_stack_ls **lst, t_stack_ls *new)
{
  if (lst == 0 || new == 0)
		return ;
  new->next = *lst;
  *lst = new;
}

void		stack_lsadd_back(t_stack_ls **lst, t_stack_ls *new)
{
	t_stack_ls  *temp;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
}

void		set_stack(t_stack_ls **stack, int data)
{
	t_stack_ls	*new;

	new = stack_lsnew(data);
	if (*stack != 0)
		stack_lsadd_back(stack, new);
	else
		*stack = new;
}

void		stack_lsclear(t_stack_ls **stack)
{
	t_stack_ls	*tmp;

	if (stack == 0)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = 0;
}
