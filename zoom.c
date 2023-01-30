/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:10 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/29 16:32:41 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int zoom(int button, int x, int y, t_data *data)
{
    double zoom_factor = 0.1;

    if (button == 5) {
        data->zoom *= zoom_factor;
        data->offset_x += x / data->zoom - x / (data->zoom / zoom_factor);
        data->offset_y += y / data->zoom - y / (data->zoom / zoom_factor);
    }
    else if (button == 4) {
        data->zoom /= zoom_factor;
        data->offset_x -= x / data->zoom - x / (data->zoom * zoom_factor);
        data->offset_y -= y / data->zoom - y / (data->zoom * zoom_factor);
    }
    ft_draw_fractal(data);
    return 0;
}