#include <iostream>
#include <deque>
#include <stack>

int main() {
	std::deque<int> stk1;
	stk1.push_back(1);
	stk1.push_back(2);
	stk1.pop_back();
	stk1.push_front(1); // ���� ������ ���� �ʾƼ� �����ؼ��� �ȵǴ� �Լ��Դϴ�.

	std::stack<int> stk2;
	stk2.push(1);
	stk2.push(2);
	stk2.pop();
	//stk2.push_front(0); //�Ǽ��� ���� ���������� �����ؼ��� �ȵǴ� �Լ��� ����� �� ������ ���������� ���Ƶξ����ϴ�.
}