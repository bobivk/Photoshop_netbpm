#pragma once
#include "Image.h"
#include"PGM_pixel.h"



class PGM_image : public Image
{
private:
	vector<PGM_pixel> pixels;
	Dimensions dimensions;
public:
	PGM_image(istream& in);
	void save(string filename) const override;
};