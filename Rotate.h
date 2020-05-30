#pragma once
#include "Action.h"
#include"Image.h"
#include"Enum_types.h"

class Rotate : public Action
{
public:
	Rotate(Image*, direction_t);
	void execute() override final;
	void undo() override final;
};

