#include "pvector.h"
using namespace std;

void Pvector::Run(bool r) {
	if (!r) return; 
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto &i : v)
		i *= i; 

	for (auto i : v)
		cout << i << " ";

	cout << endl; 

	// 

	string s("some string");

	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}

	cout << s << endl; 

	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
		*it = toupper(*it);
	}

	const vector<string> text = {"Iterate the text", "Until there is an empty line", "", "hahaha"};

	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
		cout << *it << endl; 
	}
}