#include <iostream>
#include <list>
#include <vector>

int main() {
	std::list<int> list1 = { 1,2,3,4,5 };
	list1.push_back(6);
	list1.insert(next(list1.begin()), 0);
	list1.insert(list1.begin(), 0);
	//list1.insert(list1.begin()+3, 10); 특정위치로 한 번에 이동하는 것을 불가능하다.
	list1.insert(list1.end(), 7);

	list1.pop_back();
	std::cout << "삽입 & 삭제 후 리스트 : ";
	for (auto i : list1)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> vec = { 1,2,3,4,5 };
	auto V_it4 = vec.begin() + 4;
	vec.insert(vec.begin() + 2, 0); // V_it4 반복자는 무효화 됩니다.
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	std::list < int> lst = { 1,2,3,4,5 };
	auto l_it4 = next(lst.begin(), 4);
	lst.insert(lst.begin(), 2, 0); // l_it4 반복자는 여전히 유효합니다.
	for (auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
}