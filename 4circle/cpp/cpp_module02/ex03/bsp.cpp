#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	AB_x = b.getX() - a.getX();
	Fixed	AB_y = b.getY() - a.getY();
	Fixed	AP_x = point.getX() - a.getX();
	Fixed	AP_y = point.getY() - a.getY();

	Fixed	BC_x = c.getX() - b.getX();
	Fixed	BC_y = c.getY() - b.getY();
	Fixed	BP_x = point.getX() - b.getX();
	Fixed	BP_y = point.getY() - b.getY();

	Fixed	CA_x = a.getX() - c.getX();
	Fixed	CA_y = a.getY() - c.getY();
	Fixed	CP_x = point.getX() - c.getX();
	Fixed	CP_y = point.getY() - c.getY();

	Fixed	cross1 = (AB_x * AP_y) - (AB_y * AP_x);
	Fixed	cross2 = (BC_x * BP_y) - (BC_y * BP_x);
	Fixed	cross3 = (CA_x * CP_y) - (CA_y * CP_x);

	Fixed	zero(0);

	if (cross1 == zero || cross2 == zero || cross3 == zero)
		return (false);
	return ((cross1 > zero && cross2 > zero && cross3 > zero) || \
			(cross1 < zero && cross2 < zero && cross3 < zero));
}