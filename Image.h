#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

#include"Dimensions.h"
using namespace std;

class Image {

public:

	virtual void save() const = 0;
	virtual void print() const = 0;
	virtual string get_file_name() const = 0;
	virtual string get_magic_number() const = 0;
	virtual int get_max_pixel_value() const = 0;
	virtual Dimensions get_dimensions() const = 0;
	virtual void set_dimensions(Dimensions&) = 0;
	virtual ~Image() = default;
};
