#include "calculator.h"

using namespace std;

int priority(char c) {
	switch (c) {
	case '^':
		return 0;
	case '~':
		return 1;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 3;
	case '(':
		return 4;
	}
}

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

void workWithStack(char x, stringstream& s, stack<char>& st) {
	while (!st.empty() && priority(x) >= priority(st.top())) {
		s << st.top() << " ";
		st.pop();
	}
	st.push(x);
}

bool checkExpression(stringstream& f, stringstream& s) {
	char x;
	stack<char> st;
	int j = 0, cnt = 0;
	bool flag = false;
	while (f.peek() != EOF) {
		x = f.peek();
		// j == 0 ожидаем на вход число или скобку ( или унарный -
		// j == 1 ожидаем операцию или закрывающую скобку )
		if (isdigit(x))
		{
			if (j != 0)
				return false;
			flag = false;
			double a;
			f >> a;
			s << a << " ";
			j = 1;

		}
		else
		{
			f >> x;
			switch (x) {
			case '+':
			case '*':
			case '/':
			case '^':
				if (flag)
					return false;
				flag = true;
				if (j != 1)
					return false;
				workWithStack(x, s, st);
				j = 0;
				break;
			case '(':
				cnt++;
				if (f.peek() == ')')
					return false;
				flag = false;
				st.push(x);
				break;
			case ')':
				if (--cnt < 0 || j != 1 || f.peek() == '(')
					return false;
				flag = false;
				while (!st.empty() && st.top() != '(') {
					s << st.top() << " ";
					st.pop();
				}
				if (!st.empty())
					st.pop();
				break;
			case '-':
				if (flag)
					return false;
				flag = true;
				if (j == 0)
					x = '~';
				workWithStack(x, s, st);
				j = 0;
				break;
			default:
				return false;
			}
		}
	}
	while (!st.empty()) {
		s << st.top() << " ";
		st.pop();
	}
	if (cnt == 0 && j == 1 && !flag)
		return true;
	return false;

}

double calculate(const std::string& expr) {
	if (checkExpression(expr))
		return evaulateExpression(expr);
	else
		throw exception();
}
