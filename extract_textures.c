#include "cub3d.h"

int	extract_textures(t_cub3d *cub3d)
{
	cub3d->text->text_ptr_n = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_n, &cub3d->mlx->text_w,  &cub3d->mlx->text_h);
	cub3d->text->text_d_n = (int *)mlx_get_data_addr(cub3d->text->text_ptr_n,
		&cub3d->mlx->bpp, &cub3d->mlx->size_l, &cub3d->mlx->endian);
	cub3d->text->text_ptr_s = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_s, &cub3d->mlx->text_w,  &cub3d->mlx->text_h);
	cub3d->text->text_d_s = (int *)mlx_get_data_addr(cub3d->text->text_ptr_s,
		&cub3d->mlx->bpp, &cub3d->mlx->size_l, &cub3d->mlx->endian);
	cub3d->text->text_ptr_w = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_w, &cub3d->mlx->text_w,  &cub3d->mlx->text_h);
	cub3d->text->text_d_w = (int *)mlx_get_data_addr(cub3d->text->text_ptr_w,
		&cub3d->mlx->bpp, &cub3d->mlx->size_l, &cub3d->mlx->endian);
	cub3d->text->text_ptr_e = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_e, &cub3d->mlx->text_w,  &cub3d->mlx->text_h);
	cub3d->text->text_d_e = (int *)mlx_get_data_addr(cub3d->text->text_ptr_e,
		&cub3d->mlx->bpp, &cub3d->mlx->size_l, &cub3d->mlx->endian);

	return (1);
}
