#pragma once
#include <assert.h>

template <typename T>
class CListNode
{
	template <typename T>
	friend class CLinkedList;
private:
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~CListNode()
	{

	}

private:
	T m_Data; // 실제 데이터를 저장할 변수
	CListNode<T>* m_pNext; // 다음노드의 주소를 저장할 변수
	CListNode<T>* m_pPrev; // 이전노드의 주소를 저장할 변수
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{

	}

	~CLinkedList()
	{

	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:


};
