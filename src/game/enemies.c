#include "../../so_long.h"

void	roaming(t_root *root)
{
	for(int i=0; i<root->game->map.count.enemy_count; i++) 
	{
		roam_enemy(root, &root->game->map.enemies[i]);
	}
}

void roam_enemy(t_root *root, t_enemy *enemy)
{
	// look left
	const char tile_left = root->game->map.map[enemy->position.x-1][enemy->position.y];
	if(tile_left == TILE_PATH || tile_left == TILE_PLAYER) {
		enemy->position.x--;
	}
}

void	add_enemy(t_root *root, t_enemy new_enemy)
{
	// allocate new memory, enough for one more enemy
	t_enemy	*enemies;
	enemies = malloc(sizeof(t_enemy) * (root->game->map.count.enemy_count + 1));
	if (!enemies)
	{
		nullptr_error("Unable to allocate memory for Enemies!");
		return ;
	}

	if(root->game->map.count.enemy_count > 0) {
		// copy existing enemies to new memory
		ft_memcpy(enemies, root->game->map.enemies, root->game->map.count.enemy_count);
		// free old enemies' memory
		free(root->game->map.enemies);
	}
	
	// repoint enemies pointer to new memory location
	root->game->map.enemies = enemies;
	// apply new enemy data
	++root->game->map.count.enemy_count;
	root->game->map.enemies[root->game->map.count.enemy_count-1] = new_enemy;
}

void	init_enemies(t_root *root)
{
	int		row;
	int		column;

	row = 0;
	// Iterate through each tile in the map
	// Create a new enemy if the tile is an enemy
	while (row < root->game->map.row)
	{
		column = 0;
		while (column < root->game->map.column)
		{
			if(root->game->map.map[row][column] == TILE_ENEMY){
				t_enemy new_enemy;
				new_enemy.position.x = column;
				new_enemy.position.y = row;
				add_enemy(root, new_enemy);
			}
			column++;
		}
		row++;
	}
}

void free_enemies(t_root *root)
{
	free(root->game->map.enemies);
}