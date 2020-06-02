#pragma once
#include"PBM_pixel.h"
#include"Image.h"

class PBM_image : public Image
{
private:
	vector<vector<PBM_pixel>> pixel_matrix;	//0=white, 1=black
	Dimensions dimensions;
	string filename;
public:
	PBM_image(string filename, bool binary);
	PBM_image(const PBM_image&);
	PBM_image& operator=(const PBM_image&);
	void swap_with(PBM_image&);
	~PBM_image() = default;
	void load_txt();
	void load_binary();
	void save() const override;
	string get_file_name() const override;
	string get_magic_number() const override;
	int get_max_pixel_value() const override;
	Dimensions get_dimensions() const override;
	void set_dimensions(Dimensions&) override;
	vector<vector<PBM_pixel>> get_pixel_matrix() const;
	void set_pixel_matrix(vector<vector<PBM_pixel>>);

};

