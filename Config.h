#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <map>
#include <fstream>

#define CONFIG_FILE "config.txt"
#define MAX_PROPERTY_SIZE 100

using namespace std;
class Config{
	private:
		Config();
		~Config();
		static Config *instance;
		map<string,string> data;
		map<string,string> getConfigFromFile(const char* filename);
		
	public:
		static Config* getInstance();
		void trim(string& str);
		map<string,string> getConfig();
		string getConfigValue(string property);
};
#endif
