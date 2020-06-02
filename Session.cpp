#include "Session.h"

Session::Session():
	id{ get_new_id() } {
	cout << "Session with ID: " << id << " started.\n";
}
Session::Session(const Session& other) :
	images{ other.images },
	actions{ other.actions },
	id{ other.id }{}

Session::~Session() {
}
unsigned Session::get_new_id() {
	return ++session_last_id;
}
unsigned Session::session_last_id{ 0 };

void Session::load_image(string filename) {
	ifstream file(filename, ios::beg);
	string magic_number;
	file >> magic_number;
	file.close();
	if (magic_number == "P4") {
		images.push_back(new PBM_image(filename, false));
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
	//else cout << "Can't load this image\n";
	cout << "Loaded image " << filename << endl;
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
	cout << "Session ID: " << id << endl;
	cout << images.size() << " Images in the session : ";
	for(size_t i = 0; i < images.size(); ++i){
		cout << images[i]->get_file_name() << " " << images[i]->get_dimensions()<< ", ";
	}
	
	cout << "\nPending actions : ";
	for (size_t i = 0; i < actions.size(); ++i) {
		cout << actions[i]->get_name() << ", ";
	}
	cout << endl;
}
void Session::rotate(direction_t direction) {
	actions.push_back(new Rotate(direction));
}
void Session::grayscale() {
	actions.push_back(new Grayscale());
}
void Session::monochrome() {
	actions.push_back(new Monochrome);
}
void Session::negative() {
	actions.push_back(new Negative);
}
bool Session::has_pending_actions() {
	return actions.size() > 0;
}
void Session::make_collage(orientation_t orientation, Image* first, Image* second, string outfilename) {
	ofstream out(outfilename, ios::beg | ios::trunc);
	out << first->get_magic_number() << '\n';
	if (dynamic_cast<PBM_image*>(first) && dynamic_cast<PBM_image*>(second)) {
		PBM_image* pbmimage1 = dynamic_cast<PBM_image*>(first);
		PBM_image* pbmimage2 = dynamic_cast<PBM_image*>(second);
		if (orientation == orientation_t::horizontal) {
			Dimensions new_dimensions(max(first->get_dimensions().x, second->get_dimensions().x),
				first->get_dimensions().y + second->get_dimensions().y);
			out << new_dimensions;
			for (unsigned row = 0; row < new_dimensions.x; ++row) {
				for (unsigned col = 0; col < new_dimensions.y; ++col) {

				}
			}
		}
		if (orientation == orientation_t::vertical) {
			Dimensions new_dimensions(first->get_dimensions().x + second->get_dimensions().x,
				max(first->get_dimensions().y, second->get_dimensions().y));
			out << new_dimensions;

		}
	}
}