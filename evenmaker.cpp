#include <iostream>
#include <fstream>

using namespace std;


int main() {
	ofstream file;
	string tabs="	";
	file.open("even.cpp");
	file << "#include <iostream>\n\nusing namespace std;\n\nbool isEven(int num) {\n";
		for(int i=0;i<1000000;i++) {
			file << tabs << "if(num==" << i << ")\n" << tabs << "	return " << ((i%2)?"false":"true") << ";\n" << tabs <<"else\n";
		}
	file << "		return false;\n}\n\nint main() {\n	cout << isEven(2) << endl;\n}";
	file.close();
}
