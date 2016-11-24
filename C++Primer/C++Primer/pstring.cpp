#include "pstring.h"
using namespace std; 

void Pstring::Run(bool r) {
	if (!r) return; 
	string s1; 
	string s2 = s1; 
	string s3 = "hiya";
	string s4(10, 'c');

	cout << isalnum('1') << endl;
	cout << isalpha('A') << endl;
	cout << iscntrl('\t') << endl;
	cout << isgraph('-') << endl;
	cout << isgraph('a') << endl;
	cout << isprint(' ') << endl;
	cout << ispunct(',') << endl;
	cout << isspace('\t') << endl;
	cout << isxdigit('F') << endl;
	cout << tolower('A') << endl;
	cout << toupper('a') << endl;

	string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0; 
	for (auto c : s)
		if (ispunct(c))
			++punct_cnt;

	cout << punct_cnt << " punctuation characters in " << s << endl; 


	for (auto &c : s)
		c = toupper(c); 

	cout << s << endl; 

	s = "some string";
	for (decltype(s.size()) i = 0; i != s.size() && !isspace(s[i]); ++i) {
		s[i] = toupper(s[i]); 
	}
	cout << s << endl; 

	const string hexdigits = "0123456789ABCDEF";
	const string input = "12 0 5 15 8 15";
	string result;
	string::size_type n;
	while (cin >> n)
		if (n < hexdigits.size()) result += hexdigits[n];

	cout << "Your hex number is: " << result << endl; 
}