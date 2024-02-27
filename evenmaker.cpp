#include <iostream>
#include <fstream>
#include <climits>
#include <unordered_map>

using namespace std;

struct limit {
	long long min;
	unsigned long long max;
};

unordered_map<string,struct limit> limits =
{
	{"short",{SHRT_MIN,SHRT_MAX}},
	{"signed short",{SHRT_MIN,SHRT_MAX}},
	{"unsigned short",{0,USHRT_MAX}},
	{"int",{INT_MIN,INT_MAX}},
	{"signed int",{INT_MIN,INT_MAX}},
	{"unsigned int",{0,UINT_MAX}},
	{"long",{LONG_MIN,LONG_MAX}},
	{"signed long",{LONG_MIN,LONG_MAX}},
	{"unsigned long",{0,ULONG_MAX}},
	{"long long",{LLONG_MIN,LLONG_MAX}},
	{"signed long long",{LLONG_MIN,LLONG_MAX}},
	{"unsigned long long",{0,ULLONG_MAX}}
};

int main(int argN, char** args) {
	string type="";
	string type2="";
	for(int i=1;i<argN;i++) {
		type=type+((i!=1)?" ":"")+((string)args[i]);
		type2=type2+((i!=1)?"_":"")+((string)args[i]);
	}
	long long min;
	unsigned long long minAlt=0; //this is used if you are using an unsigned long long and only then
	long long max=limits[type].max;
	unsigned long long maxAlt=limits[type].max;


		cout << (minAlt<maxAlt) << endl;
	if(limits.count(type)) {
		string name= "even."+type2+".h";
		ofstream file;
		string tabs="	";
		file.open(name);
		file << "#pragma once\n#include <iostream>\n\nbool isEven(" << type <<" num) {\n";
			if(type!="unsigned long long")
				for(min=limits[type].min;min<max+1;min++)
					file << tabs << "if(num==" << min << ")\n" << tabs << "	return " << ((min%2)?"false":"true") << ";\n" << tabs <<"else\n";
			else
				for(minAlt=0;minAlt<maxAlt;minAlt++)
					file << tabs << "if(num==" << minAlt << ")\n" << tabs << "	return " << ((minAlt%2)?"false":"true") << ";\n" << tabs <<"else\n";

		file << "		return false;\n}\n";
		file.close();
	}
}
