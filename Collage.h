#pragma once
#include "Action.h"
#include"Enum_types.h"
#include"Image.h"

class Collage
{
public:
	Collage(orientation_t, Image* first, Image* second, string output_filename);
	string get_name() const;
	
};

