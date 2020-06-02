#pragma once
#include"PGM_pixel.h"
#include"Image.h"


class PGM_image : public Image
{
private:
	vector<vector<PGM_pixel>> pixel_matrix;
	Dimensions dimensions;
	string filename;
	int max_pixel_value;
	bool binary;
public:
	PGM_image(string filename);
	PGM_image(const PGM_image&);
	PGM_image& operator=(const PGM_image&);
	void save() const override;
	void print() const override;
	string get_file_name() const override;
	string get_magic_number() const override;
	int get_max_pixel_value() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PGM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PGM_pixel>>);


};