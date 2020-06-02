#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
#include"PBM_image.h"
#include"PGM_image.h"
#include"PPM_image.h"
#include"Rotate.h"
#include"Monochrome.h"
#include"Negative.h"
#include"Grayscale.h"
#include"Collage.h"
#include"Enum_types.h"

using namespace std;


class Session
{
public:
	Session();
	Session(const Session&);
	~Session();
	void load_image(string);
	void save();
	void undo();
	void session_info()const;
	void print()const;
	void rotate(direction_t);
	void grayscale();
	void monochrome();
	void negative();
	void collage_input();
	bool has_pending_actions();

	static unsigned session_last_id;
private:
	vector<Image*> images;
	vector<Action*> actions;
	unsigned id;

	

	void make_collage(orientation_t, Image*, Image*, string in_outfilename);


	unsigned get_new_id();
};

