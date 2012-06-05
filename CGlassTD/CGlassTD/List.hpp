#ifndef __List_hpp_
#define __List_hpp_

// ----------MyNode-----------
template< typename T >
class MyNode
{
public:
	T mData;
	MyNode<T>* next;
	MyNode<T>* prev;

	MyNode()
	{
		next = NULL;
		prev = NULL;
	}

	virtual bool isHead() const = 0;
	virtual bool isEnd() const = 0;
};


// ----------MyHeadNode-----------
template< typename T >
class MyHeadNode : public MyNode<T>
{
public:
	bool isHead() const
	{
		return true;
	}
	bool isEnd() const
	{
		return false;
	}
};


// ------------MyEndNode------------
template< typename T >
class MyEndNode : public MyNode<T>
{
public:
	bool isHead() const
	{
		return false;
	}
	bool isEnd() const
	{
		return true;
	}
};

// ------------MyInnerNode------------
template< typename T >
class MyInnerNode : public MyNode<T>
{
public:
	bool isHead() const
	{
		return false;
	}
	bool isEnd() const
	{
		return false;
	}
};





template< typename T >
class MyList
{
public:
	MyList();
	~MyList();

	void insertAhead(const T& element);
	void clear();

	void start();
	bool forward();
	T getData() const;
	void deleteCurrentNode();

	int size() const;

private:
	MyNode<T>* mHead;
	MyNode<T>* mCurrentNode;
	int mSize;

	MyNode<T>* mDeleted;
};


template< typename T >
MyList<T>::MyList()
	: mSize(0), mDeleted(NULL)
{
	mHead = new MyHeadNode<T>();
	mHead->next = new MyEndNode<T>();
	mHead->next->prev = mHead;

	mCurrentNode = NULL;
}

template< typename T >
MyList<T>::~MyList()
{
	this->clear();
	delete mHead->next;
	delete mHead;
}

template< typename T >
void MyList<T>::clear()
{
	MyNode<T>* scan = mHead->next;
	MyNode<T>* toDelete = NULL;

	while (!scan->isEnd())
	{
		toDelete = scan;
		scan = scan->next;
		delete toDelete;
	}

	mHead->next = scan;

	if (mDeleted != NULL)
	{
		delete mDeleted;
		mDeleted = NULL;
	}

	mCurrentNode = NULL;

	mSize = 0;
}

template< typename T >
void MyList<T>::start()
{
	mCurrentNode = mHead;
}

template< typename T >
bool MyList<T>::forward()
{
	if (mCurrentNode->next->isEnd()) return false;

	mCurrentNode = mCurrentNode->next;
	return true;
}

template< typename T >
T MyList<T>::getData() const
{
	return mCurrentNode->mData;
}

template< typename T >
void MyList<T>::deleteCurrentNode()
{
	if (mDeleted != NULL)
	{
		delete mDeleted;
		mDeleted = NULL;
	}

	if (mCurrentNode == NULL) return;
	if (mCurrentNode->isEnd()) return;
	if (mCurrentNode->isHead()) return;

	--mSize;

	mDeleted = mCurrentNode;
	mCurrentNode->next->prev = mCurrentNode->prev;
	mCurrentNode->prev->next = mCurrentNode->next;
}

template< typename T >
void MyList<T>::insertAhead(const T& element)
{
	++mSize;
	MyNode<T>* newNode = new MyInnerNode<T>();
	newNode->mData = element;

	MyNode<T>* firstNode = mHead->next;

	mHead->next = newNode;
	newNode->next = firstNode;
	newNode->prev = mHead;
	firstNode->prev = newNode;
}

template< typename T >
int MyList<T>::size() const
{
	return mSize;
}


#endif