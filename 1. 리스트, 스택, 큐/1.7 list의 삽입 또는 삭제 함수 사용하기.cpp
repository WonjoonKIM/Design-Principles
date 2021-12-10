#include <iostream>
#include <list>
#include <vector>

int main() {
	std::list<int> list1 = { 1,2,3,4,5 };
	list1.push_back(6);
	list1.insert(next(list1.begin()), 0);
	list1.insert(list1.begin(), 0);
	//list1.insert(list1.begin()+3, 10); Ư����ġ�� �� ���� �̵��ϴ� ���� �Ұ����ϴ�.
	list1.insert(list1.end(), 7);

	list1.pop_back();
	std::cout << "���� & ���� �� ����Ʈ : ";
	for (auto i : list1)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> vec = { 1,2,3,4,5 };
	auto V_it4 = vec.begin() + 4;
	vec.insert(vec.begin() + 2, 0); // V_it4 �ݺ��ڴ� ��ȿȭ �˴ϴ�.
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	std::list < int> lst = { 1,2,3,4,5 };
	auto l_it4 = next(lst.begin(), 4);
	lst.insert(lst.begin(), 2, 0); // l_it4 �ݺ��ڴ� ������ ��ȿ�մϴ�.
	for (auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
}