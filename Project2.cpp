//Temp Project 2.cpp
// This is what im thinking havent completed the vector storage for all the nodes yet.

#include "stdafx.h"
#include <vector>
using std::vector;
#include <String>
using std::string;

class BinaryTree
{
private:
	class Node
	{
		string id;
		string parentID;
		string rawEvent;
		string LHASH;
		Node* left;
		string RHASH;
		Node* right;
		vector <string> LHIST;
		vector<string> RHIST;
	};
	Node* root;
	
public:
	vector< Node> tree;
};


int main()
{
    return 0;
}

