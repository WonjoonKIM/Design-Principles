#include <iostream>
#include <deque>
#include <stack>

int main() {
	std::deque<int> stk1;
	stk1.push_back(1);
	stk1.push_back(2);
	stk1.pop_back();
	stk1.push_front(1); // 스택 구조에 맞지 않아서 구현해서는 안되는 함수입니다.

	std::stack<int> stk2;
	stk2.push(1);
	stk2.push(2);
	stk2.pop();
	//stk2.push_front(0); //실수로 스택 구조에서는 구현해서는 안되는 함수를 사용할 수 없도록 문법적으로 막아두었습니다.
}