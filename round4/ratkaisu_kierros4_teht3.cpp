#include <iostream>;
#include <string>;
#include <fstream>;
using namespace std;


int main() {
	// create file data writing object
	ofstream outputfile;
	string name, 
		description;

	// open the file for writing
	outputfile.open("index.html");

	// if file is open
	if (outputfile) {

		// ask user for name and description
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Describe yourself: ";
		getline(cin, description);

		// create/edit index.html to standard html page with given user data
		outputfile << "<html>\n<head>\n</head>\n<body>\n\t<center>\n\t\t<h1>"
			<< name << "<\h1>\n\t</center>\n\t<hr />\n\t"
			<< description << "\n\t<hr />\n</body>\n</html>";
		
		// close the file
		outputfile.close();
	}

	// if creating/editing file had issues, tell user
	else {
		cout << "Something unusual is going on.";
	}
	return 0;
}
