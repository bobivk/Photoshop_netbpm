#pragma once
#include "Image.h"
#include"PPM_pixel.h"

class PPM_image : public Image
{
private:
	vector<PPM_pixel> pixels;
	Dimensions dimensions;
public:
	PPM_image(istream& in);
	void save(string filename) const override;
	friend istream& operator>>(istream& in, PPM_pixel& pixel);
};
 
