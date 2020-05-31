#pragma once
#include<string>
#include<vector>
#include"PBM_image.h"
#include"PGM_image.h"
#include"PPM_image.h"
#include"Enum_types.h"
class Action
{
public:
	virtual void execute(std::vector<Image*>& images) = 0;
	virtual std::string get_name() const = 0 ;

	virtual ~Action() = default;
};

