//Temp Project 2.cpp
// This is what im thinking havent completed the vector storage for all the nodes yet.

#include "stdafx.h"
#include <vector>
using std::vector;
#include <String>
using std::string;
#include "Project2.h"



int main()
{
		vector <BinaryTree> v1;
		createNode(v1, "A");
		Insert(v1, "b");
		Insert(v1, "c");
		Insert(v1, "d");
		Insert(v1, "e");
		Insert(v1, "f");
		Insert(v1, "g");

		InTrav(v1, 0);
		PreTrav(v1, 0);
		PostTrav(v1, 0);
		return 0;
	
}

