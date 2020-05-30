#pragma once
#include "Action.h"
#include"Enum_types.h"
#include"Image.h"

class Collage : public Action
{
public:
	Collage(orientation_t, Image* first, Image* second, string output_filename);
	void execute() override final;
	void undo() override final;
	~Collage() override final;
};

