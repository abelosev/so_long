/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abelosev <abelosev@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/05 01:18:52 by abelosev		  #+#	#+#			 */
/*   Updated: 2024/02/06 10:21:49 by abelosev         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h" 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define TWIDTH	  	64
# define THEIGHT	 	64
# define BUFFER_SIZE 50

# define A   97
# define D   100
# define S   115
# define W   119

# define LEFT	65361
# define RIGHT   65363
# define DOWN	65364
# define UP	  	65362 

typedef struct s_textures
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
}	t_textures;

typedef struct s_map
{
	int	player_nb;
	int	collect_nb;
	int	score;
	int	exit_path;
	int	exit_nb;
	int	line_len;
	int	line_nb;
	int	p_x;
	int	p_y;
}	t_map;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	float		w_width;
	float		w_height;
	int			move_nb;
	t_map		map;
	t_textures	textures;
	char		**tab;
	char		**tab_path1;
}	t_mlx_data;

void	input_handler(int ac, char **av);
void	free_tab(char **arr);
void	error_handler(int value);
void	data_initiate(t_mlx_data *data);
void	nb_check(t_mlx_data *data);
void	wall_check(t_mlx_data *data);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void	moves_announcer(int nb);
void	map_parsing(t_mlx_data *data);
void	map_check(t_mlx_data *data);
void	put_textures(t_mlx_data *data, int t_width, int t_height);
void	rendering(t_mlx_data *data, int t_width, int t_height);
char	**get_tab(int fd, int line_nb);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *prev_line, char *buf);
char	*ft_get_line(char *prev_line);
char	*ft_new_prevline(char *prev_line);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		handle_key(int keycode, t_mlx_data *data);
int		game_close(t_mlx_data *data);
int		line_count(int fd);
void	path_check(t_mlx_data *data, char **av);
int		fill(t_mlx_data *data, int y, int x);

#endif
