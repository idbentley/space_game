#include "Config.h"

Config *Config::instance = NULL;
map<string,string> data;

Config::Config(){
	data = getConfigFromFile(CONFIG_FILE);
}

Config::~Config(){}

Config *Config::getInstance(){
	if(instance == NULL)
		instance = new Config();
	return instance;
}

map<string,string> Config::getConfig(){
	return data;
}

string Config::getConfigValue(string property){
	if(data.find(property)!=data.end()){
		return data[property];
	}
	return "";	
}


map<string,string> Config::getConfigFromFile(const char* filename){

	//Read in config file
	map<string,string> configMap;
	ifstream inFile;
	inFile.open(filename);
	
	if (!inFile) {
    		cerr << "Unable to open file" << filename;
		//exit(0);
	}
	
	int eqIndex;
	int endIndex;
	cout << "Reading config file("<< filename << ")..." << endl;
	while(!inFile.eof()) {
		char lineIn[MAX_PROPERTY_SIZE];
 		inFile.getline(lineIn, sizeof(lineIn), '\n');
		string line(lineIn);
		if(line.size()>1){
			eqIndex = line.find("=",0);
			endIndex = line.find("\n",eqIndex);
			string propertyName = line.substr(0,eqIndex);
			string propertyValue = line.substr(eqIndex+1,endIndex);
			//Add to map
			cout << "property: " << propertyName << ", Value: " << propertyValue << endl;
			configMap.insert ( pair<string,string>(propertyName,propertyValue) );
			cout.flush();
		}
	}
	cout << "Finished reading config file." << endl;
	
	inFile.close();
	return configMap;
}


