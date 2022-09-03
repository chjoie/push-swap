/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:51:32 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/17 12:14:27 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
#include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int				number;
	int	group;
	struct s_pile	*next;
}	t_pile;

void		my_putstr(char *str);
void		print_error(void);
int			check_argv(int argc, char *argv[]);
int			check_argv_content(char *argv[]);
char		**get_elements(char **argv);
char		**fill_elems(char **elements, char *str, int *i);
char		**fill_tmp(char **tmp, char	*str);
char		*my_substr(char *str, char *substr, int start, int end);
int			my_atoll(char *str, char **args, t_pile *root);
int			is_space(char *str);
int			new_size(char *str, int size);
int			get_args_size(char **argv);
int			word_size(char *str, int size);
void		free_and_exit(char **args, t_pile **root);
void		insert_end(t_pile **root, int number);
void		free_list(t_pile **root);
int			check_duplicate(t_pile **root);
int			check_if_sorted(t_pile *root);
void		free_char_lst(char **args);
void		swap_a(t_pile **root);
void		swap_b(t_pile **root);
void		sa_and_sb(t_pile *pile_a, t_pile *pile_b);
void		swap_a_noprint(t_pile **root);
void		swap_b_noprint(t_pile **root);
void		push_a(t_pile **root_a, t_pile **root_b);
void		push_b(t_pile **root_a, t_pile **root_b);
void		rotate_a(t_pile **root);
void		rotate_b(t_pile **root);
void		rotate_b_noprint(t_pile **root);
void		rotate_a_noprint(t_pile **root);
void		ra_and_rb(t_pile **pile_a, t_pile **pile_b);
void		reverse_rotate_a(t_pile **root);
void		reverse_rotate_b(t_pile **root);
void		reverse_rotate_a_noprint(t_pile **root);
void		reverse_rotate_b_noprint(t_pile **root);
void		rra_and_rrb(t_pile **pile_a, t_pile **pile_b);
void		check_arguments(int c, char **args);
void		sort(char **args, t_pile **root_a, t_pile **root_b);
int		get_arg_number(t_pile **root);
int		is_lowest(int x, t_pile **root);
int		is_biggest(int x, t_pile **root);
void		sort_3_args(t_pile **root);
void		sort_over_3(t_pile **root_a, t_pile **root_b);
void		sort_5(t_pile **root_a, t_pile **root_b);
void		sort_a_lot(t_pile **root_a, t_pile **root_b);
int		stack_count(t_pile **root);
int		lowest_index(t_pile **root);
int		biggest_index(t_pile **root);
void		fill_stack_b(t_pile **root_a, t_pile **root_b, t_pile *list_a);
void		fill_stack_a(t_pile **root_a, t_pile **root_b);
void		more_than_2(t_pile **root_a, t_pile **root_b, t_pile *list_a);
void		less_than_2(t_pile **root_a, t_pile **root_b, t_pile *list_a);
void		sort_a_lot(t_pile **root_a, t_pile **root_b);
void		is_already_in(t_pile **root, int x, char **args);
int		get_lowest(t_pile **root);
int		get_biggest(t_pile **root);
int		get_next_int(int x, t_pile **root);
int		all_group(t_pile **root);
void		set_group(int num, t_pile **root, int group);
void		get_group(t_pile **root, int limit);
void		sort_optimized(t_pile **root_a, t_pile **root_b);
int		closest_to_top(t_pile **root, int group);
int		get_instructions_nb(t_pile **root, int number);
int		get_position(t_pile **root, int number);
int		check_group(t_pile **root, int group);
void		put_value_top(t_pile **root, int value);
void		put_value_top_b(t_pile **root, int value);

#endif
