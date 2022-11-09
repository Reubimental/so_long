/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:28:05 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/03 19:28:08 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data 	img;
	void	*mlx;
	void	*mlx_win;
	int 	x = 400;
	int 	y = 400;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1366, 768, "Hello World!");
	img.img = mlx_new_image(mlx, 1366, 768);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
