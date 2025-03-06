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

