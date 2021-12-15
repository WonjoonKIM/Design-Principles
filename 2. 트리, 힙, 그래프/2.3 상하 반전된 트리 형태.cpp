//직원은 두명의 부하직원을 거느릴 수 있다.

#include <iostream>
#include <queue>

struct node {
	std::string position;
	node* first;
	node* second;
};

struct org_tree {
	node* root;
	static org_tree create_org_structure(const std::string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const std::string& value) {
		if (root == NULL)
			return NULL;
		if (root->position == value)
			return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const std::string& manager, const std::string& subordinate) {
		auto managerNode = org_tree::find(root, manager);
		if (!managerNode) {
			std::cout << manager << "을 찾을 수 없습니다." << std::endl;
			return false;
		}
		if (managerNode->first && managerNode->second) {
			std::cout << manager << " 아래에 " << subordinate << "을 찾을 수 없습니다." << std::endl;
			return false;
		}
		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL }; \

			std::cout << manager << " 아래에 " << subordinate << "을 추가했습니다" << std::endl;

		return true;
	}

	static void preOrder(node* start) {
		if (!start)
			return;

		std::cout << start->position << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}

	static void inOrder(node* start) {
		if (!start)
			return;

		inOrder(start->first);
		std::cout << start->position << ", ";
		inOrder(start->second);
	}

	static void postOrder(node* start) {
		if (!start)
			return;

		postOrder(start->first);
		postOrder(start->second);

		std::cout << start->position << ", ";
	}

	//레벨 순서 순회(level order traversal) : 트리의 맨 위 레벨부터 아래 레벨까지 왼쪽 노드에서 오른쪽 노드 순서로 방문합니다.
	static void levelOrder(node* start) {
		if (!start)
			return;
		std::queue<node*> q;
		q.push(start);

		while (!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front();
				q.pop();
				std::cout << current->position << ", ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}
			std::cout << std::endl;
		}
	}
}; 

int main() {
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("부사장", "재무부장");
	tree.addSubordinate("마케팅부장", "마케팅팀장");

	org_tree::levelOrder(tree.root); 
}