#pragma once

#include <algorithm>

#define MAX_QUEUE_SIZE 5

template <typename T>
class BQueue
{
public:
	BQueue(int size);
	~BQueue();
	bool IsFull();
	bool IsEmpty();
	void Enque(T val);
	T Deque();
private:
	bool m_bFull;
	bool m_bEmpty;
	int m_Front;
	int m_Rear;
	int m_Size;
	T m_Data[MAX_QUEUE_SIZE];
	BQueue<T> *m_pBackupQueue;
};

template<typename T>
inline BQueue<T>::BQueue(int size)
{
	m_pBackupQueue = NULL;
	m_bFull = false;
	m_bEmpty = true;
	m_Size = std::min(size, MAX_QUEUE_SIZE);
	m_Front = m_Rear = 0;
}

template<typename T>
inline BQueue<T>::~BQueue()
{
	if (m_pBackupQueue)
		m_pBackupQueue->~BQueue();
}

template<typename T>
inline bool BQueue<T>::IsFull()
{
	return m_bFull;
}

template<typename T>
inline bool BQueue<T>::IsEmpty()
{
	return m_bEmpty;
}

template<typename T>
inline void BQueue<T>::Enque(T val)
{
	if (IsFull())
	{
		if (m_pBackupQueue == NULL)
			m_pBackupQueue = new BQueue<T>(MAX_QUEUE_SIZE);
		m_pBackupQueue->Enque(val);
	}
	else
	{
		m_Rear = (m_Rear + 1) % m_Size;
		m_Data[m_Rear] = val;
		if (m_Front == m_Rear)
			m_bFull = true;
		m_bEmpty = false;
	}
}

template<typename T>
inline T BQueue<T>::Deque()
{
	if (IsEmpty())
		throw "Queue is empty";
	m_Front = (m_Front + 1) % m_Size;
	T result = m_Data[m_Front];
	if (m_Front == m_Rear)
		m_bEmpty = true;
	m_bFull = false;
	if (m_pBackupQueue && !m_pBackupQueue->IsEmpty())
		this->Enque(m_pBackupQueue->Deque());
	return result;
}
