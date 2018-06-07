#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,q;
	cin >> n >>q;
	string line;
	getline(cin,line);
	regex opentag ("<([\\w]+)");
	regex expression ("(\\S+)\\s\\=\\s\"(\\S+)\"");
	smatch matched;
	string currCaller = "";
	map<string,string> variables;

	for (int i = 0; i < n; ++i)
	{
		getline(cin,line);
		regex_search(line, matched, opentag);
		if (matched[0] != ""){ //open tag
			currCaller += matched[1];
			currCaller += ".";
			while(regex_search(line, matched, expression)){
				currCaller.pop_back();
				string key = currCaller + "~" + matched[1].str();
				variables[key] = matched[2];
				currCaller += ".";
				line = matched.suffix();
			}
		} else{//closing tag
			currCaller.pop_back();
			size_t  extension = currCaller.find_last_of(".");
			if (extension == string::npos) currCaller = "";
			else{
				currCaller = currCaller.substr(0,extension);
				currCaller += ".";
			}
		}
	}
	for (int i = 0; i < q; ++i)
	{
		string querry;
		cin >> querry;
		string res;
		res = variables[querry];
		if (res == "") cout << "Not Found!" << endl;
		else cout << res << endl;
	}
}
