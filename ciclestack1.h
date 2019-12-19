#pragma once
template <typename T> class ciclestack1
{
public:
	typedef struct Node
	{
		Node *nextnode;
		T info;
	};
	ciclestack1();
	~ciclestack1();
};

