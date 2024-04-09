#include "rpn.h"
#include <stack>
#include <cmath>


using namespace std;

double evaulateExpression(stringstream& s) {
	char c;
	double a, b;
	stack<double> st;
	while (s.peek() != EOF) {
		c = s.peek();
		if (isdigit(c)) {
			s >> a;
			st.push(a);
		}
		else {
			s.get();
			switch (c) {
			case ' ':
				break;
			case '^':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(pow(a, b));
				break;
			case '~':
				b = st.top();
				st.pop();
				st.push(-b);
				break;
			case '*':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a * b);
				break;
			case '/':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a / b);
				break;
			case '+':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a + b);
				break;
			case '-':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a - b);
				break;
			}
		}
	}
	return st.top();
}

double calculateRPN(const std::string& expr) {
	stringstream str(s);
	return evaulateExpression(str);
}
