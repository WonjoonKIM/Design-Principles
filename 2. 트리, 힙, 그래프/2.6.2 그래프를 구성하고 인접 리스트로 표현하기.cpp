// 각 노드에 직접 연결되어 있는 노드의 ID만 저장하는 방식으로 그래프를 표현할 수 있습니다.

#include <iostream>
#include <vector>
#include <algorithm>

enum class city :int { // enum클래스를 이용하여 도시 이름 저장
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c) { // city enum에 대해 연산자 <<정의
	switch (c) {
	case city::LONDON:
		os << "런던";
		return os;

	case city::MOSCOW:
		os << "모스크바";
		return os;

	case city::SEOUL:
		os << "서울";
		return os;

	case city::SEATTLE:
		os << "시애틀";
		return os;

	case city::DUBAI:
		os << "두바이";
		return os;

	case city::SYDNEY:
		os << "시드니";
		return os;

	default:
		return os;
	}
}

struct graph { // 실제 데이터를 저장할 graph구조체를 정의합니다.
	std::vector<std::vector<std::pair<int, int>>> data;

	graph(int n) {
		// 다만 안쪽 벡터의 크기가 전체 노드 개수가 아니라 해당노드에 연결된 노드 개수와 같다.
		data = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>());
	}

	//2차원 벡터를 사용하여 데이터를 저장하지만 처음에는 에지가 없으므로 모든 행은 비어있는 형태로 초기화됩니다.
	void addEdge(const city c1, const city c2, int dis) {
		std::cout << "에지 추가 : " << c1 << " - " << c2 << " = " << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);

		// 에지 끝에 있는 두 노드에 대해 각각 에지 연결을 설정한다.
		data[n1].push_back({ n2, dis });
		data[n2].push_back({ n1, dis });
	}

	void removeEdge(const city c1, const city c2) {
		std::cout << "에지 삭제 : " << c1 << " - " << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {
			return pair.first == n2;
			});
		std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {
			return pair.first == n1;
			});
	}
};

int main() {
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	// 전체 에지 개수 E에 비례한 크기의 메모리를 사용합니다.

	return 0;
}

