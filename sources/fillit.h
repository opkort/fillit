/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:45:59 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/20 18:18:24 by ihilmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define TETROS_NUMBER 26

typedef	struct		s_tetro
{
	int				points[4][2];
	struct s_tetro	*next;
}					t_tetro;

typedef struct		s_matrix
{
	int				coord[2];
	int				tetro_id;
	int				is_filled;
	struct s_matrix	*right;
	struct s_matrix	*down;
	struct s_matrix *pos_in_matrix;
}					t_matrix;

void				fillit(char *name);
void				del_last_tetros(t_tetro *tetros);
void				free_tetro(t_tetro *tetros);
void				free_struct(t_matrix *matrix);
int					valid(int fd, t_tetro *tetros);
int					read_tetro(int fd, t_tetro *ptr);
int					check_conditions(t_tetro tetro);
int					check_neigh(int i, t_tetro tetro);
int					count_write(char *line, t_tetro *tetros,
					int pt_nb, int line_nb);
t_tetro				*new_tetro(t_tetro *ptr);
int					builder(t_tetro *tetros, t_matrix **solution,
					t_matrix **matrix);
void				print_solutions(t_matrix *matrix, int size);
void				move_tetro(t_tetro *tmp, int x, int y);
int					fill_matrix(t_tetro *tetros, t_matrix **matrix,
					int size);
void				null_terminate_solution(t_matrix **solution,
					t_matrix *rowlast);
void				print_tetro_arr(int size, int arr[][size]);
void				init_arr(t_matrix *matrix, int size, int arr[][size]);
void				null_init_arr(int size, int arr[][size]);
int					ft_tetros_area(t_tetro *tetros);
int					min_size(int tetros_area, t_tetro *tetros);
int					check_tetros_types(t_tetro *tetros);
void				norm_tetro(t_tetro *tetros);
void				move_tetro(t_tetro *tmp, int x, int y);
int					algorithm_x(t_matrix **matrix, t_matrix **solution,
					int size, int tetros_area);
void				free_storage(t_matrix **storage);
void				restore_matrix(t_matrix **storage, t_matrix **solution,
					t_matrix **matrix);
void				null_terminate_solution(t_matrix **solution,
					t_matrix *rowlast);
void				return_row_from_solution(t_matrix **matrix,
					t_matrix **solution);
void				from_solution_to_beginning(t_matrix **matrix,
					t_matrix **solution);
void				return_row(t_matrix **matrix, t_matrix **row_storage);
void				return_norm_row(t_matrix **matrix, t_matrix *row);
void				return_first_row(t_matrix **matrix, t_matrix *row);
void				null_terminate_row_storage(t_matrix **row_storage);
void				return_col(t_matrix **matrix, t_matrix **col_storage);
void				return_norm_col(t_matrix **matrix, t_matrix *col);
void				return_first_col(t_matrix **matrix, t_matrix *col);
void				null_terminate_col_storage(t_matrix **col_storage);
void				rebuild_matrix(t_matrix **storage, t_matrix **solution,
					t_matrix **matrix);
void				remove_rows(t_matrix **matrix, t_matrix **row_storage,
					t_matrix *solution);
void				rem_rows_helper(t_matrix **col, t_matrix **mat,
					t_matrix **matrix, t_matrix **row_storage);
void				remove_cols(t_matrix **matrix, t_matrix **col_storage,
					t_matrix *solution);
void				remove_cols_helper(t_matrix **col_storage,
					t_matrix **matrix, t_matrix **tmp, int *flag);
void				matrix_delete_col(t_matrix **matrix, t_matrix **ptr);
void				del_norm_col(t_matrix **matrix, t_matrix *col);
void				del_first_col(t_matrix **matrix, t_matrix *col);
void				col_to_storage(t_matrix **col_storage, t_matrix *col);
void				row_to_storage(t_matrix **row_storage, t_matrix *row);
void				matrix_delete_row(t_matrix **matrix, t_matrix **ptr);
void				del_normal_row(t_matrix **matrix, t_matrix *row);
void				del_first_row(t_matrix **matrix, t_matrix *row);
void				row_to_solution(t_matrix **solution, t_matrix *row);
t_matrix			*find_row(t_matrix *matrix, t_matrix *rts);
int					check_cols(t_matrix *matrix, t_matrix *solution,
					int size, int tetros_area);
int					decision_condition(t_matrix *solution, int tetros_area);
int					check_empty_cols(t_matrix *matrix);
t_matrix			*find_small_col(t_matrix *matrix);
int					new_cell(t_matrix **matrix, int coords[]);
void				init_state(t_matrix **matrix, t_tetro *tetros,
					int tetro_id);
t_matrix			*create_state(t_tetro *tetros, int size, int tetro_id);
int					is_right_shift(t_tetro *tetros, int size);
int					is_down_shift(t_tetro *tetros, int size);
void				join_states(t_matrix **matrix, t_matrix *src);
t_matrix			*form_states(t_tetro *tetros, int size, int tetro_id);

#endif
