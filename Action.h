#pragma once
class Action
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Action() = default;
};

