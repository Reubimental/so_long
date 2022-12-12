#include "../../so_long.h"

void	init_player(t_entity *entity, void *mlx)
{
	entity->player.direction.up.img = mlx_xpm_file_to_image(mlx, PATH_PU,
			&entity->player.size.x, &entity->player.size.y);
	entity->player.direction.up.addr = mlx_get_data_addr(entity->player.direction.up.img, &entity->player.direction.up.bpp,
			&entity->player.direction.up.line_length, &entity->player.direction.up.endian);
	entity->player.direction.down.img = mlx_xpm_file_to_image(mlx, PATH_PD,
			&entity->player.size.x, &entity->player.size.y);
	entity->player.direction.down.addr = mlx_get_data_addr(entity->player.direction.down.img, &entity->player.direction.down.bpp,
			&entity->player.direction.down.line_length, &entity->player.direction.down.endian);
	entity->player.direction.left.img = mlx_xpm_file_to_image(mlx, PATH_PL,
			&entity->player.size.x, &entity->player.size.y);
	entity->player.direction.left.addr = mlx_get_data_addr(entity->player.direction.left.img, &entity->player.direction.left.bpp,
			&entity->player.direction.left.line_length, &entity->player.direction.left.endian);
	entity->player.direction.right.img = mlx_xpm_file_to_image(mlx, PATH_PR,
			&entity->player.size.x, &entity->player.size.y);
	entity->player.direction.right.addr = mlx_get_data_addr(entity->player.direction.right.img, &entity->player.direction.right.bpp,
			&entity->player.direction.right.line_length, &entity->player.direction.right.endian);
	entity->player.sprite = entity->player.direction.down;
	entity->player.facing = FACING_DOWN;
}

void	init_enemy(t_entity *entity, void *mlx)
{
	entity->enemy.direction.left.img = mlx_xpm_file_to_image(mlx, PATH_EL,
			&entity->enemy.size.x, &entity->enemy.size.y);
	entity->enemy.direction.left.addr = mlx_get_data_addr(entity->enemy.direction.left.img, &entity->enemy.direction.left.bpp,
			&entity->enemy.direction.left.line_length, &entity->enemy.direction.left.endian);
	entity->enemy.direction.right.img = mlx_xpm_file_to_image(mlx, PATH_ER,
			&entity->enemy.size.x, &entity->enemy.size.y);
	entity->enemy.direction.right.addr = mlx_get_data_addr(entity->enemy.direction.right.img, &entity->enemy.direction.right.bpp,
			&entity->enemy.direction.right.line_length, &entity->enemy.direction.right.endian);
	entity->enemy.sprite = entity->enemy.direction.left;
}

void	init_item(t_entity *entity, void *mlx)
{
	entity->item.sprite.img = mlx_xpm_file_to_image(mlx, PATH_I,
			&entity->item.size.x, &entity->item.size.y);
	entity->item.sprite.addr = mlx_get_data_addr(entity->item.sprite.img, &entity->item.sprite.bpp,
			&entity->item.sprite.line_length, &entity->item.sprite.endian);
}

void	init_exit(t_entity *entity, void *mlx)
{
	entity->exit.sprite.img = mlx_xpm_file_to_image(mlx, PATH_EX,
			&entity->exit.size.x, &entity->exit.size.y);
	entity->exit.sprite.addr = mlx_get_data_addr(entity->exit.sprite.img, &entity->exit.sprite.bpp,
			&entity->exit.sprite.line_length, &entity->exit.sprite.endian);
}

void	init_wall(t_entity *entity, void *mlx)
{
	entity->wall.sprite.img = mlx_xpm_file_to_image(mlx, PATH_W,
			&entity->wall.size.x, &entity->wall.size.y);
	entity->wall.sprite.addr = mlx_get_data_addr(entity->wall.sprite.img, &entity->wall.sprite.bpp,
			&entity->wall.sprite.line_length, &entity->wall.sprite.endian);
	entity->path.sprite.img = mlx_xpm_file_to_image(mlx, PATH_P,
			&entity->path.size.x, &entity->path.size.y);
	entity->path.sprite.addr = mlx_get_data_addr(entity->path.sprite.img, &entity->path.sprite.bpp,
			&entity->path.sprite.line_length, &entity->path.sprite.endian);
}

