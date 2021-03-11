
void	draw_ver_line(int x, int drawStart, int drawEnd, int color, int **data)
{
	int i = 0;
	while (i < 480){
		// in order, wall, ceil, floor
		if (i >= drawStart && i <=drawEnd){
			(*data)[i * 640 + x] = color;
		}
		else if (i < 240) {
			(*data)[i * 640 + x] = 0x0000aa;
		}
		else{
			(*data)[i * 640 + x] = 0x000000;
		}
		i++;
	}
}

