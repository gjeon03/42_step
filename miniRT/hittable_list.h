#ifndef HITTABLE_LIST_H
# define HITTABLE_LIST_H

# include "hittable.h"
# include "sphere.h"

typedef struct		s_list
{
	t_hittable		object;
	struct s_list	*next;
}					t_list;

t_list	*list_(t_hittable object)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->object = object;
		new->next = NULL;
	}
	return (new);
}

void	push(t_list **lst, t_list *new)
{
	if (lst)
	{
		t_list	*temp;

		temp = *lst;
		*lst = new;
		(*lst)->next = temp;
	}
}

void	drop(t_list *lst)
{
	if (lst)
	{
		free(lst->object.pointer);
		free(lst);
	}
}

void	clear(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			drop(*lst);
			(*lst) = temp;
		}
		lst = NULL;
	}
}

int		hit(t_hittable *object, t_ray r, double t_min, double t_max, t_hit_record *rec)
{
	switch (object->mesh)
	{
		case _sphere:
			if (hit_sphere(object->pointer, r, t_min, t_max, rec))
				return (TRUE);
			break ;
	}
	return (FALSE);
}

int		list_hit(t_list **lst, t_ray r, double t_min, double t_max, t_hit_record *rec)
{
	t_hit_record	temp_rec;
	t_list			*current;
	double			closest_so_far = t_max;
	int				hit_anything = FALSE;

	current = lst ? *lst : NULL;
	while (current)
	{
		if (hit(&(current->object), r, t_min, t_max, &temp_rec))
		{
			hit_anything = TRUE;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		current = current->next;
	}
	return (hit_anything);
}

#endif
