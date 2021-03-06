#pragma once
#include"PGM_pixel.h"
#include"Image.h"


class PGM_image : public Image
{
private:
	vector<vector<PGM_pixel>> pixel_matrix;
	Dimensions dimensions;
	string filename;
	int max_pixel_value{ 0 };
	bool is_binary;


	void load_txt();
	void load_binary();
	void save_txt() const;
	void save_binary() const;
public:
	PGM_image(string filename, bool binary = false);
	PGM_image(const PGM_image&);
	PGM_image& operator=(const PGM_image&);
	void print() const override;
	void save() const override;
	string get_file_name() const override;
	string get_magic_number() const override;
	int get_max_pixel_value() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PGM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PGM_pixel>>&);


};