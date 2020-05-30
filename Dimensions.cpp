#include "Dimensions.h"

istream& operator>>(istream& in, Dimensions& dimensions) {
	return in >> dimensions.x >> dimensions.y;
}
ostream& operator<<(ostream& out, const Dimensions& dimensions){
	return out << dimensions.x << " " << dimensions.y << '\n';
}