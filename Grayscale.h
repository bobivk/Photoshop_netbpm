#pragma once
#include "Action.h"
#include"Image.h"
#include"Enum_types.h"

class Grayscale : public Action
{
public:
	Grayscale(Image*);
	void execute() override final;
	void undo() override final;
	~Grayscale();
};

