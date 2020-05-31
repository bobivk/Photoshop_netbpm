#include"Session.h"

vector<Session> sessions;

int main() {
	Session current_session;
	string command;
	cout << " > ";
	cin >> command;
	if (command == "load") {
		current_session.load_image();
	}
	else if (command == "save") {
		current_session.save();
	}
	else if (command == "session_info") {
		current_session.session_info();
	}
	else if (command == "rotate") {
		string directionstr;
		cin >> directionstr;
		if (directionstr == "right") {
			current_session.rotate(direction_t::right);
		}
		else if (directionstr == "left") {
			current_session.rotate(direction_t::left);
		}
	}

	return 0;
}