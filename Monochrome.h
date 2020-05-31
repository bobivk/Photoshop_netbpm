#pragma once
#include "Action.h"
#include"Image.h"
#include"Enum_types.h"

class Monochrome : public Action
{
public:

	string get_name() const override;
	void execute(vector<Image*>& images) override;
};

