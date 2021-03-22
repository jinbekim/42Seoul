
// static int	fade_color(int color, t_stripe stripe)
// {
// 	double	fade;
// 	double	pwd;
// 	int	r;
// 	int	g;
// 	int	b;

// 	pwd = 1 / (stripe.height / (double)SC_H);
// 	fade = pwd / (double)24 * 10;
// 	fade = 1 / fade + 0.3;
// 	if (fade > 1)
// 		fade = 1;
// 	r = (int)((int)((color & 0xff0000) * fade) & 0xff0000);
// 	g = (int)((int)((color & 0x00ff00) * fade) & 0x00ff00);
// 	b = (int)((int)((color & 0x0000ff) * fade) & 0x0000ff);
// 	return (r + g + b);
// }
