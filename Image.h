#pragma once
#include"Enum_types.h"
#include"Dimensions.h"
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;



class Image
{
private:
public:
	virtual void save(string filename) const = 0;
	virtual ~Image() = default;
};

