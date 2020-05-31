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
		file.close();
		PBM_image image(filename);
		images.push_back(&image);
	}
	else if (magic_number == "P2") {
		PGM_image image(filename);
		images.push_back(&image);
	}
	else if (magic_number == "P3") {
		PPM_image image(filename);
		images.push_back(&image);
	}
	
	else if (magic_number == "P5") {
		PGM_image image(filename);
		images.push_back(&image);
	}
	else if (magic_number == "P6") {
		PPM_image image(filename);
		images.push_back(&image);
	}
}
void Session::save() {
	for (size_t i = 0; i < actions.size(); ++i) {
		actions[i]->execute(images);
	}
	for (size_t i = 0; i < images.size(); ++i) {
		images[i]->save();
	}
	actions.clear();
}
void Session::undo() {
	if (actions.size() > 0) actions.erase(actions.end() - 1);
	else "No pending actions to undo.\n";
}
void Session::session_info() {
	cout << "Images in the session : ";
	for(size_t i = 0; i < images.size(); ++i){
		cout << images[i]->get_file_name() << ", ";
	}
	cout << "\nPending actions : ";
	for (size_t i = 0; i < actions.size(); ++i) {
		cout << actions[i]->get_name() << ", ";
	}
	cout << endl;
}
void Session::rotate(direction_t direction) {
	actions.push_back(&Rotate(direction));
}
void Session::grayscale() {
	actions.push_back(&Grayscale());
}
void Session::monochrome() {
	actions.push_back(&Monochrome());
}
void Session::negative() {
	actions.push_back(&Negative());
}
bool Session::has_pending_actions() {
	return actions.size() > 0;
}