#include "src/main.c"
#include "fractol.h"

int	on_keypress(int keysym, t_data *mlx)
{    
	printf("Keyrelease: %d\n", keysym);
	if(keysym == XK_Escape)
		free_all(mlx);
	if(keysym == XK_Up || keysym == XK_w)
		printf("UP\n");
	if(keysym == XK_Down || keysym == XK_s)
		printf("DOWN\n");
	if(keysym == XK_Left || keysym == XK_a)
		printf("LEFT\n");
	if(keysym == XK_Right || keysym == XK_d)
		printf("RIGHT\n");
	render_frame(mlx);
	return (0);
}


//CRAZY COLOR FLASHES
int	draw_texture(t_data *mlx) //put in render
{
	int x = 0;
	int y = 0;
	static int i;
	static int j;
	int color;
	static int flag;

//
			if(i % 4 == 0)
				color = encode_argb(0, i, i/5, i/5);
			if((i+1) % 4 == 0)
				color = encode_argb(0, i/5, i, i/5);
			if((i+2) % 4 == 0)
				color = encode_argb(0, i/5, i/5, i);
			if((i+3) % 4 == 0)
				color = encode_argb(0, i, i/5, i);
			if(i <= 254 && j % 40 == 0 && flag == 0)
			{
				i++;
				if(i == 255)
					flag = 1;

			}
			if(i >= 1 && j % 10 == 0 && flag == 1)
			{		
				i--;
				if(i == 0)
					flag = 0;
			}
			j++;

//
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			mlx_put_pixel(mlx, x, y, color);
			//encode_argb(0, 0, 255, (((x+y)/2)*255) / ((WIDTH+HEIGHT)/2))
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}


int initializer(t_data *mlx)
{
	mlx->connect = NULL;
	mlx->window = NULL;
	mlx->img = NULL;
	mlx->img_addr = NULL;
	mlx->img_bpp = 0;
	mlx->img_line_len = 0;
	mlx->img_endian = 0;
	return(0);
}

int	main(void)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
		return(MLX_ERROR);
	initializer(mlx);
	mlx->connect = mlx_init();
	if (!mlx->connect)
		return (MLX_ERROR);
	mlx->window = mlx_new_window(mlx->connect, WIDTH, HEIGHT, "ganda fract-ol");
	if (!mlx->window)
	{
		free(mlx->connect);
		return (MLX_ERROR);
	}
	mlx->img = mlx_new_image(mlx->connect, WIDTH, HEIGHT);
	mlx->img_addr = mlx_get_data_addr(
		mlx->img, &mlx->img_bpp, &mlx->img_line_len, &mlx->img_endian);	

	mlx_loop_hook(mlx->connect, render_frame, &mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, on_keypress, &mlx);
	mlx_loop(mlx->connect);
}

