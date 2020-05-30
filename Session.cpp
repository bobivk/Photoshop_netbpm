#include "Session.h"

Session::Session():
	id{ get_new_id() } {
	cout << "Session with ID: " << id << " started.\n";
}
Session::~Session() {
}
unsigned Session::get_new_id() {
	return session_last_id++;
}
unsigned Session::session_last_id{ 0 };

void Session::load_image() {
	string filename;
	cin >> filename;
	ifstream file(filename, ios::beg);
	string magic_number;
	file >> magic_number;
	if (magic_number == "P1" || magic_number == "P4") {
		PBM_image image(file);
		images.push_back(&image);
	}
	else if (magic_number == "P2") {
		PGM_image image(file);
		images.push_back(&image);
	}
	else if (magic_number == "P3") {
		PPM_image image(file);
		images.push_back(&image);
	}
	
	else if (magic_number == "P5") {
		PGM_image image(file);
		images.push_back(&image);
	}
	else if (magic_number == "P6") {
		PPM_image image(file);
		images.push_back(&image);
	}

}

