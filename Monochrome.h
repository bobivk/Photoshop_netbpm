#pragma once
#include "Action.h"
#include"Image.h"
#include"Enum_types.h"

class Monochrome : public Action
{
public:
	Monochrome(Image*);
	void execute() override final;
	void undo() override final;
};

