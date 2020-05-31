#pragma once
#include"PPM_pixel.h"
#include"Image.h"

class PPM_image : public Image
{
private:
	vector<vector<PPM_pixel>> pixel_matrix;
	Dimensions dimensions;
	string filename;
	int max_pixel_value;
public:
	PPM_image(string filename);
	void save() const override;
	string get_file_name() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PPM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PPM_pixel>>);

};
 
