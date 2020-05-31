#include"Session.h"


int main() {
	cout << "Welcome to Netbpm photoshop!  Load a pbm, pgm or ppm image to start.\n";
	cout << "Choose one of the following commands:\n";
	cout << "1. load <filename>\n";
	cout << "2. session_info\n";
	cout << "3. switch <session_id>\n";
	cout << "4. rotate <left|right>\n";
	cout << "5. monochrome\n";
	cout << "6. grayscale\n";
	cout << "7. negative\n";
	cout << "8. save\n";
	cout << "9. exit\n";
	cout << " > ";
	vector<Session> sessions;
	Session current_session;
	sessions.push_back(current_session);
	string command;
	bool running = true;
	while (running) {
		cin >> command;
		if (command == "load") {
			if (current_session.has_pending_actions()) {
				Session new_session;
				sessions.push_back(new_session);
				current_session = new_session;
			}
			current_session.load_image();
		}
		else if (command == "save") {
			current_session.save();
		}
		else if (command == "session_info") {
			current_session.session_info();
		}
		else if (command == "switch") {
			int id;
			cin >> id;
			current_session = sessions[id - 1];
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
		else if (command == "grayscale") {
			current_session.grayscale();
		}
		else if (command == "negative") {
			current_session.negative();
		}
		else if (command == "monochrome") {
			current_session.monochrome();
		}
		else if (command == "exit") running = false;
	}
	return 0;
}