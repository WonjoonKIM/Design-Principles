// std::forward_list������ ���� ���길 �����ϸ� �̷��� �ݺ��ڸ� ������ �ݺ��ڶ�� �մϴ�.
// �ݺ��ڸ� ����Ͽ� Ư���� ��ġ�� ���ҿ� ��ٷ� ������ ���̰� �̸� ���� ���� �ݺ��ڶ�� �մϴ�.
// �ݺ��� Ÿ�ӿ� ���� ����� �� �ִ� �Լ� �߿��� advance(), next(), prev() �Լ��� �ֽ��ϴ�.
// ���� �ݺ����� ���� ���� ������ O(1)�� �ð� ���⵵�� �����ϴ�.

#include <iostream>
#include <forward_list>
#include <vector>

int main() {

	std::vector<std::string> vec = {
		"Lewis", "Lewis", "Nico", "Sebastian", " Lewis", "Sebastian", "Sebastian", "Sebastian", "Fernando"
	};

	auto it = vec.begin();
	std::cout << "���� �ֱ� ����� : " << *it << std::endl;

	it += 8; // ���ϴ� �ε���
	std::cout << "8���� ����� : " << *it << std::endl;

	advance(it, -3); // �� �� 3�� �� ����� 
	std::cout << "�� �� 3�� �� ����� : " << *it << std::endl;

	std::forward_list<std::string> fwd(vec.begin(), vec.end());
	auto it2 = fwd.begin();
	std::cout << "���� �ֱ� �����: " << *it2 << std::endl;
	advance(it2, 5);
	std::cout << "5���� ����� : " << *it2 << std::endl;

	//forward_list�� ���������θ� �̵��� �� �����Ƿ� ���� �߻�!
	//advance(it2, -3); 
	
	// forward_list�� ����ð����� ���� ���ϹǷ� ���� �߻�!
	// it2+=1;

}