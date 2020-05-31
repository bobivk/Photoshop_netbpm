#pragma once
#include"PGM_pixel.h"
#include"Image.h"


class PGM_image : public Image
{
private:
	vector<vector<PGM_pixel>> pixel_matrix;
	Dimensions dimensions;
	string filename;
	int pixel_max_value;
public:
	PGM_image(string filename);
	void save() const override;
	string get_file_name() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PGM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PGM_pixel>>);

};