#pragma once
#include<iostream>
class Bad_pixel_exception : std::exception
{
private:
	std::string bad_pixel;
public:
	Bad_pixel_exception(std::string in_bad_pixel) :
		bad_pixel{ in_bad_pixel } {

	}
	
	std::string get_bad_pixel() const {
		return bad_pixel;
	}
};

