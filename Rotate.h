#pragma once
#include "Action.h"
#include"Image.h"
#include"PBM_image.h"
#include"PGM_image.h"
#include"PPM_image.h"
#include"Enum_types.h"

class Rotate : public Action
{
public:
	direction_t direction;
	Rotate(direction_t);
	string get_name() const override;
	void execute(vector<Image*>& images) override;
};

