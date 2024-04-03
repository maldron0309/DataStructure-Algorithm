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
	T m_Data; // ���� �����͸� ������ ����
	CListNode<T>* m_pNext; // ��������� �ּҸ� ������ ����
	CListNode<T>* m_pPrev; // ��������� �ּҸ� ������ ����
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
