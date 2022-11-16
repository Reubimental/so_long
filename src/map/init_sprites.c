#include "../../so_long.h"

void	init_player(t_entity *entity, void *mlx)
{
	
}

void	init_enemy(t_entity *entity, void *mlx)
{
	entity->enemy.sprite.img = mlx_xpm_file_to_image();
	entity->enemy.sprite.addr
}

void	init_item(t_entity *entity, void *mlx)
{
	entity->item.sprite.img = mlx_xpm_file_to_image(mlx, (IMAGE FILE PATH),
			&entity->item.size.x, &entity->item.size.y);
	entity->item.sprite.addr = mlx_get_data_addr(entity->item.sprite.img, &entity->item.sprite.bpp,
			&entity->item.sprite.line_size, &entity->item.sprite.endian);
}

void	init_exit(t_entity *entity, void *mlx)
{
	entity->exit.sprite.img = mlx_xpm_file_to_image();
	entity->exit.sprite.addr
}

void	init_wall(t_walls *wall, void *mlx)
{
	wall->sprite.img = mlx_xpm_file_to_image();
	wall->sprite.addr
}