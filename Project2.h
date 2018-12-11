#pragma once
//Recieved Help from https://www.codeproject.com/Articles/602805/Creating-a-Binary-Search-Tree-B
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
struct BinaryTree
{
	string ID;
	string parentID;
	string rawEvent;
	string LHASH;
	string RHASH;
	int rightIndex;
	int leftIndex;
	vector<string> LHIST;
	vector<string> RHIST;
};

void createNode(vector<BinaryTree> &tree, string rawEvent)
{
	struct BinaryTree b1 = { NULL,NULL,rawEvent,NULL,NULL,-1,-1};
	tree.push_back(b1);
}

void setLeft(vector<BinaryTree> &tree, int curr, string rawEvent)
{
	int leftInd = tree.size();
	tree[curr].leftIndex = leftInd;
	struct BinaryTree b1 = { NULL,NULL,rawEvent,NULL,NULL,-1,-1 };
	tree.push_back(b1);

}

void setRight(vector<BinaryTree> &tree, int curr, string rawEvent)
{
	int rightInd = tree.size();
	tree[curr].rightIndex = rightInd;
	struct BinaryTree b1 = { NULL,NULL,rawEvent,NULL,NULL,-1,-1 };
	tree.push_back(b1);
}

void Insert(vector<BinaryTree> &tree, string rawEvent)
{
	if (tree.size() == 0)
	{
		cout << "Tree is empty" << endl;
		return;
	}
 int currentIdx = 0;
	while (currentIdx < tree.size())
	{
		if (rawEvent<= tree[currentIdx].rawEvent)
		{
			if (tree[currentIdx].leftIndex == -1)
			{
				setLeft(tree, currentIdx, rawEvent);
				break;
			}
			else
				currentIdx = tree[currentIdx].leftIndex;
		}
		else
		{
			if (tree[currentIdx].rightIndex == -1)
			{
				setRight(tree, currentIdx, rawEvent);
				break;
			}
			else
				currentIdx = tree[currentIdx].rightIndex;
		}
	}
}

void InTrav(vector <BinaryTree> &tree, unsigned int Idx)
{
	if (tree[Idx].leftIndex != -1)
		InTrav(tree, tree[Idx].leftIndex);
	cout << tree[Idx].rawEvent << endl;
	if (tree[Idx].rightIndex != -1)
		InTrav(tree, tree[Idx].rightIndex);
}

void PreTrav(vector <BinaryTree> &tree, unsigned int Idx)
{
	cout << tree[Idx].rawEvent << endl;
	if (tree[Idx].leftIndex != -1)
		PreTrav(tree, tree[Idx].leftIndex);
	if (tree[Idx].rightIndex != -1)
		PreTrav(tree, tree[Idx].rightIndex);
}
void PostTrav(vector <BinaryTree> &tree, unsigned int Idx)
{
	if (tree[Idx].leftIndex != -1)
		PostTrav(tree, tree[Idx].leftIndex);
	if (tree[Idx].rightIndex != -1)
		PostTrav(tree, tree[Idx].rightIndex);
	cout << v1[Idx].rawEvent << endl;
}

void rootHash()
{

}

void hashFunction()
{

}