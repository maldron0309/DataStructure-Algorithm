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
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		// 처음에는 추가된 노드가 없으므로 Begin의 다음으로
		// End를 지정하고 End의 이전으로 Begin를 지정한다.
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;

	}

	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_iSize;

public:
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data; 

		// 뒤에 추가를 해야 하므로 End의 이전 노드를 얻어온다.
		PNODE pPrev = m_pEnd->m_pPrev;

		// 얻어온 이전 노드와 End노드 사이에 새로 생성한 노드를 추가한다.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End노드와 새로 생성한 노드를 연결한다.
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void pop_front()
	{
		if (empty())
		{
			assert(false);
		}

		// 지울 노드를 얻어온다.
		PNODE pDeleteNode = m_pBegin->m_pNext;

		// 지울 노드의 다음 노드를 얻어오고 해당 노드와 Begin노드를 연결해준다.
		PNODE pNext = pDeleteNode->m_pNext;

		pNext->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNext;

		// 노드를 지워준다.
		delete pDeleteNode;

		// 사이즈를 1 감소시킨다.
		--m_iSize;
	}

	T front() const
	{
		if (empty())
		{
			assert(false);
		}
		return m_pBegin->m_pNext->m_Data;
	}

	T back() const
	{
		if (empty())
		{
			assert(false);
		}
		return m_pEnd->m_pPrev->m_Data;
	}

	// Begin과 End를 제외한 실제 추가한 노드의 삭제 기능을 만들어준다.
	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// 현재 노드의 다음 노드를 얻어온다.
			PNODE pNext = pNode->m_pNext;

			// 현재 노드를 지워준다.
			delete pNode;

			// pNode에 다음 노드의 주소를 넣어준다.
			pNode = pNext;
		}

		m_iSize = 0;

		// Begin과 End를 서로 연결해준다.
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size() const
	{
		return m_iSize;
	}

	// 리스트가 비어있을 경우 true, 아닐 경우 false를 반환한다.
	bool empty() const
	{
		return m_iSize == 0;
	}
};
