#include "../include/fractol.h"

// Remove static to match the header file declaration
void ft_put_pixel(int x, int y, t_img *img, int color)
{
    *(unsigned int *)(img->pixels + (y * img->line_len) + (x * (img->bpp / 8))) = color;
}

static inline void ft_set_fractal(t_complex *z, t_complex *c, t_fractol *f)
{
    if (f->set == JULIA)
    {
        c->x = f->julia_x;
        c->y = f->julia_y;
    }
    else
    {
        *c = *z;
    }
}

static inline int ft_get_color(int iter, int max_iter)
{
    int intensity = (int)(255.0 * ((double)iter / max_iter));
    return (intensity << 16) | (intensity << 8) | intensity;
}

void ft_handle_pixel(int x, int y, t_fractol *f, double zoom, double shift_x, double shift_y)
{
    t_complex c;
    double zx = (ft_map(x, -2, 2, WIDTH) * zoom) + shift_x;
    double zy = (ft_map(y, 2, -2, HEIGHT) * zoom) + shift_y;
    double zx2 = zx * zx;
    double zy2 = zy * zy;
    int i = 0;

    ft_set_fractal(&(t_complex){zx, zy}, &c, f);

    while (i < f->iter && (zx2 + zy2) <= f->escape_val)
    {
        zy = 2 * zx * zy + c.y;
        zx = zx2 - zy2 + c.x;
        zx2 = zx * zx;
        zy2 = zy * zy;
        i++;
    }

    ft_put_pixel(x, y, &f->img, i < f->iter ? ft_get_color(i, f->iter) : f->color);
}

void ft_render(t_fractol *f)
{
    double zoom = f->zoom;
    double shift_x = f->shift_x;
    double shift_y = f->shift_y;

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            ft_handle_pixel(x, y, f, zoom, shift_x, shift_y);
        }
    }

    mlx_put_image_to_window(f->mlx, f->window, f->img.img_ptr, 0, 0);
}
