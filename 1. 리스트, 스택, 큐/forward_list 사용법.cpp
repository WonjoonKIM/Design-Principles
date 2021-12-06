#include <iostream>
#include <forward_list>
using namespace std;

int main(void) {
	std::forward_list<int> fwd_list = { 1,2,3 };
	fwd_list.push_front(0);
	fwd_list.pop_front();

	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5); // �� ó�� ���� �ڿ� 5 �߰�
	fwd_list.insert_after(it, 6);

	fwd_list.erase_after(it); // �� ���� ���� ���� ����
	fwd_list.erase_after(it, fwd_list.end()); //�� ���� ���� �������� �� ������ ���ұ��� ����

}