#include <graphics.h>
#include <math.h>

//x control
int _x(int x)
{
	return x;
}

//y control
int _y(int y)
{
	return getmaxy()-y;
}

//Draw point 
void point(int x, int y)
{
	putpixel(_x(x), _y(y), getcolor());
}

//Bresenham line algorithm
void myline(int sx, int sy, int ex, int ey)
{
	int dx = ex - sx;	//difference in x
	int dy = ey - sy;	//difference in y
	int sign = (1.0*dy)/dx > 0 ? 1 : -1;	//sign of the slope

	if(abs(dx) > abs(dy))	//X-major line
	{
		int pk = 2*abs(dy) - abs(dx);
		while(sx != ex && sy != ey)
		{
			point(sx, sy);	//draw point
			sx = sx + 1;	//increment x
			if(pk > 0)
			{	
				sy = sy + sign; //increment or decrement y
				pk = pk + 2*abs(dy) - 2*abs(dx);
			}
			else
			{	
				pk = pk + 2*abs(dy);
			}
		}
	}
	else	//Y-major line
	{
		int pk = 2*abs(dx) - abs(dy);
		while(sx != ex && sy != ey)
		{
			point(sx, sy);	//draw point
			sy = sy + sign; //increment or decrement y
			if(pk > 0)
			{	
				sx = sx + 1;	//increment x
				pk = pk + 2*abs(dx) - 2*abs(dy);
			}
			else
			{	
				pk = pk + 2*abs(dx);
			}
		}
	}

}

//Bresenham circle algorithm
void mycircle(int cx, int cy, int r)
{
	int pk = 1 - r;
	int x = 0;
	int y = r;

	while(x < y)
	{
		for(int i=-1; i<=1; i+=2)
		{
			for(int j=-1; j<=1; j+=2)
			{
				point(cx + i*x, cy + j*y);
				point(cx + i*y, cy + j*x);
			}
		}
		x = x + 1;
		if(pk > 0)
		{
			y = y - 1;
			pk = pk + 1 + 2*x - 2*y;
		}
		else
		{
			pk = pk + 1 + 2*x;
		}
	}
}