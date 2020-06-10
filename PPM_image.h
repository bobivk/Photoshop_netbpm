#pragma once
#include"PPM_pixel.h"
#include"Image.h"

class PPM_image : public Image
{
private:
	vector<vector<PPM_pixel>> pixel_matrix;
	Dimensions dimensions;
	string filename;
	bool is_binary;
	int max_pixel_value{ 0 };

	void load_txt();
	void load_binary();
	void save_txt() const;
	void save_binary() const;
public:
	PPM_image(string filename, bool binary = false);
	PPM_image(const PPM_image&);
	PPM_image& operator=(const PPM_image&);
	void print() const override;
	void save() const override;
	string get_file_name() const override;
	string get_magic_number() const override;
	int get_max_pixel_value() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PPM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PPM_pixel>>&);


};
 
