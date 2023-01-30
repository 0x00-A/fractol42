/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:20:14 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/30 10:26:21 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	render(t_data *data)
{
	(void)data;
	// ft_draw_complex_plan(data);
	// ft_draw_rec(data, (t_rec){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 100, 50});
	// ft_draw_circle(data, (t_cir){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 60});
	if (!ft_strncmp(data->fractal.name, "mandelbrot", 11))
		ft_draw_mandelbrot(data);
	else if (!ft_strncmp(data->fractal.name, "julia", 5))
		ft_draw_julia(data);
	else
	{
		ft_print_options();
		window_close(data);
	}
	return (0);
}

void	ft_print_options(void)
{
	ft_printf("Not enough or invalid args\n");
	ft_printf("Usage: <./fractol> <fractal_name>\n");
	ft_printf("Available fractals: Mandelbrot Julia\n");
	ft_printf("Note: julia set can have a third paramiter for generating different sets [1-3]\n");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
	{
		ft_print_options();
		exit(1);
	}
	data.fractal.name = av[1];
	if (ac == 3)
		data.fractal.julia_opt = av[2];
	else
		data.fractal.julia_opt = 0;
	if (makewindow(&data) == 1)
		return (1);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handel_escape, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, window_close, &data);
	// mlx_hook(data.win_ptr, 4, 0, zoom, &data);
	mlx_loop(data.mlx_ptr);
}
