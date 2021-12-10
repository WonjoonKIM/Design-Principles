#include <iostream>
#include <deque>

int main() {
	std::deque<int> deq = { 1,2,3,4,5 };
	deq.push_front(0);
	deq.push_back(6);
	deq.insert(deq.begin() + 2, 10);

	for (auto i : deq)
		std:: cout << i << " ";
	std::cout << std::endl;

	deq.pop_back();
	deq.pop_front();
	deq.erase(deq.begin() + 1);
	deq.erase(deq.begin() + 3, deq.end());

	for (auto i : deq)
		std::cout << i << " ";
	std::cout << std::endl;
}