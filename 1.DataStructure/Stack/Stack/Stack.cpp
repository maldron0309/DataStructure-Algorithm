#include <iostream>
#include <vector>

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Stack
{
private:
	Node<T>* topNode; // 스택 최상위 노드
	size_t stackSize; // 스택 크기

public:
	Stack() : topNode(nullptr), stackSize(0) {}

	~Stack()
	{
	}

	T& top()
	{
		if (empty())
		{
			throw std::runtime_error("Stack is Empty");
		}
		return topNode->data; // 스택 topNode 데이터 반환
	}

	void pop()
	{
		if (empty())
		{
			std::cerr << "Stack is underflow" << std::endl;
			return;
		}

		Node<T>* temp = topNode; // topNode를 temp에 저장
		topNode = topNode->next; // topNode를 next노드로 변경
		delete temp; // temp에 저장되어 있는 임시 노드를 삭제
		--stackSize; // 스택 크기 감소
	}


	void push(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);

		newNode->next = topNode; // newNode의 next를 topNode로 설정
		topNode = newNode; // topNode를 newNode로 저장
		++stackSize; // 스택 크기 증가
	}

	bool empty()
	{
		return topNode == nullptr; // 스택 비어있는 지 확인 (비어있으면 true, 노드가 하나라도 있으면 fasle)
	}

	size_t size()
	{
		return stackSize; // 스택 크기 반환
	}
};

int main()
{
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3); // current : 3

	std::cout << "Top :  " << s.top() << std::endl; // Top : 3

	s.pop(); // current : 2
	std::cout << "Pop :  " << s.top() << std::endl; // Pop : 2

	std::cout << "Stack size :  " << s.size() << std::endl; // Stack size : 2

	s.pop(); // current : 1
	s.pop(); // current : 0
	std::cout << "Pop : " << s.top() << std::endl; // ERROR!

	if (s.empty()) // 스택이 없으니 true
	{
		std::cout << "Stack is Empty" << std::endl; // Stack is Empty
	}

	return 0;
}