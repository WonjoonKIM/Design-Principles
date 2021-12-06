#include <iostream>
#include <forward_list>
using namespace std;

int main(void) {
	std::forward_list<int> fwd_list = { 1,2,3 };
	fwd_list.push_front(0);
	fwd_list.pop_front();

	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5); // 맨 처음 원소 뒤에 5 추가
	fwd_list.insert_after(it, 6);

	fwd_list.erase_after(it); // 맨 앞의 다음 원소 삭제
	fwd_list.erase_after(it, fwd_list.end()); //맨 앞의 원소 다음부터 맨 마지막 원소까지 삭제

}