#pragma once
#include "Action.h"
#include"Image.h"
#include"Enum_types.h"

class Negative : public Action
{
public:
	Negative(Image*);
	void execute() override final;
	void undo() override final;
};

