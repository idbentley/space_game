#include "Util.h"

int Util::strtoint(string s){
	std::stringstream ss(s);
	int i;
	ss >> i;
	return i;
}




