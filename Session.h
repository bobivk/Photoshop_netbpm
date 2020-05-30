#pragma once
#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<fstream>
#include"Image.h"
#include"PBM_image.h"
#include"PGM_image.h"
#include"PPM_image.h"
#include"Action.h"
#include"Enum_types.h"

using namespace std;


class Session
{
public:
	Session();
	~Session();
	void load_image();
	void save(string file_name);
	void grayscale();
	void monochrome();
	void negative();
	void rotate_input();
	void undo();
	void session_info();
	void collage_input();

	static unsigned session_last_id;
private:
	vector<Image*> images;
	stack<Action*> actions;
	unsigned id;

	

	void rotate(direction_t);
	void make_collage();

	unsigned get_new_id();
};

