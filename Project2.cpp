// Project2.cpp 
//

#include "stdafx.h"
#include "Project2.h"
#include <iostream>
using std::cout;
#include <vector>
using std::vector;


int main()
{
vector<struct node> tree;
rootNode(tree, "this is a test");

cout << tree[0].ID;
    
return 0;
}


