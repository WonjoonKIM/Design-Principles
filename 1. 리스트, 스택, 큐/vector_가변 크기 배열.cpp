#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//std::vector<int> vec; //ũ�� ������ �ʿ䰡 ����
	std::vector<int> vec = { 1,2,3,4,5 }; // ũ�Ⱑ 5�� ���� ����
	//std::vector<int> vec(10); // ũ�� ��������
	//std::vector<int> vec(10, 5); // ũ�Ⱑ 10�̰� ��� ���Ұ� 5�� �ʱ�ȭ�� ���� ����

	vec.insert(vec.begin(), 0);

	vec.push_back(6);

	vec.insert(find(vec.begin(), vec.end(), 1), 4); // 1�տ� 4�߰��ϱ�

	std::vector<int> vec2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vec2.pop_back();
	vec2.erase(vec2.begin());
	vec2.erase(vec2.begin() + 1, vec.begin() + 4); // 1��° ���Һ��� 4��° �� ���ұ��� �����մϴ�.

	for (auto it = vec.begin(); it != vec.end(); it++) {
		auto element = (*it);
		std::cout << element << ", ";
	}

	//vec.clear();
	//vec2.clear();

}