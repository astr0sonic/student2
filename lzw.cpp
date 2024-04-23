#include "lzw.h"
#include <map>

using namespace std;

vector<int> compress(const string& text) {
	map<string, int> dict;
	for (int i = 0; i < 256; i++)
		dict[string(1, static_cast<char>(i))] = i;
	string bufer = "";
	vector<int> v;
	string buferSecond = "";
	for (int i = 0; i < text.size(); i++) {
		buferSecond = bufer + string(1, text[i]);
		if (dict.find(buferSecond) != dict.end())
			bufer = buferSecond;
		else {
			dict[buferSecond] = dict.size();
			v.push_back(dict[bufer]);
			bufer = { text[i] };
		}
	}
	v.push_back(dict[{text[text.size() - 1]}]);
	return v;
}

string decompress(const vector<int>& v) {
	map<int, string> dict;
	for (int i = 0; i < 256; i++) {
		dict[i] = string(1, static_cast<char>(i));
	}
	string s = dict[v[0]];
	string curStr = dict[v[0]];
	string prevStr = "";
	for (int i = 1; i < v.size(); i++) {
		if (dict.find(i) != dict.end())
			curStr = dict[v[i]];
		else
			curStr = prevStr + prevStr[0];
		dict[dict.size()] = prevStr + curStr[0];
		s += curStr;
		prevStr = curStr;
	}
	return s;
}