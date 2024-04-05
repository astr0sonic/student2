#include "bracket.h"
#include <stack>
#include <sstream>

using namespace std;

bool checkBrackets(const std::string& s) {
	stringstream str(s);
	return checkParenthesis(str);
}

bool checkParenthesis(istream& f) {
	char c;
	stack<char> st;
	while (f.peek() != EOF) {
		f >> c;
		if (c == '(' || c == '[' || c == '{' || c == '<')
			st.push(c);
		else
		{
			switch (c) {
			case ')':
				if (st.empty() || st.top() != '(')
					return false;
				st.pop();
				break;
			case '}':
				if (st.empty() || st.top() != '{')
					return false;
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[')
					return false;
				st.pop();
				break;
			case '>':
				if (st.empty() || st.top() != '<')
					return false;
				st.pop();
				break;
			}
		}
	}
	return st.empty();
}