#pragma once
#include "Image.h"
#include"PBM_pixel.h"


class PBM_image : public Image
{
private:
	vector<PBM_pixel> pixels;	//0=white, 1=black
	Dimensions dimensions;
public:
	PBM_image(ifstream& in);
	void save(string filename) const override;

};

