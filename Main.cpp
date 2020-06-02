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
	cout << "9. new\n";
	cout << "10. exit\n";
	vector<Session> sessions;
	Session current_session;
	sessions.push_back(current_session);
	string command;


	bool running = true;
	while (running) {
		cout << " > ";
		cin >> command;
		if (command == "load") {
			string filename;
			cin >> filename;
			if (current_session.has_pending_actions()) {
				Session new_session;
				sessions.push_back(new_session);
				current_session = new_session;
			}
			current_session.load_image(filename);
		}
		else if (command == "save") {
			current_session.save();
		}
		else if (command == "i") {
			current_session.session_info();
		}
		else if (command == "print") {
			current_session.print();
		}
		else if(command == "switch") {
			unsigned id;
			cin >> id;
			if (id >= current_session.session_last_id) {
				Session new_session;
				sessions.push_back(new_session);
				current_session = new_session;
				cout << "Switched to session with ID: " << current_session.session_last_id;
			}
			else {
				current_session = sessions[id - 1];
			}
		}
		else if (command == "new"){
			Session new_session;
			sessions.push_back(new_session);
			current_session = new_session;
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
		else if (command == "collage") {
			current_session.collage_input();
		}

		else if (command == "exit") running = false;
	}
	return 0;
}