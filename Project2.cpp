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
	string input, par, id, event;
	vector<struct node> tree;
	
	cout << " Tracking Tree" << endl << "----------------------------------" << endl;
	cout << " Instructions:CREATE ROOT FIRST|root(creates root of tree)| new (for new node)| preOrder(Displays preOrder traversal)," << endl;
	cout << "search - display(shows inormation for a specific node)| update(update contents of specific node)| DONE (closes application)" << endl;
	cout << "----------------------------------" << endl;
	cin >> input;
	if (input == "root")
	{
		cout << "Enter your raw event: ";
		cin >> event;
		rootNode(tree, event);
		cout << endl << "Root Created" << endl;
	}
	if (input == "new")
	{
		cout << "Enter your raw event: ";
		cin >> event;
		insert(tree, event);
		cout << endl << "Node sucsessfully added" << endl;

	}
	if (input == "preorder")
	{
		cout << "Enter your raw event: ";
		cin >> event;
		insert(tree, event);
		cout << endl << "Node sucsessfully added" << endl;
	}
	if (input == "search")
	{

	}if (input == "update")
	{

	}
	if (input == "DONE")
	{

	}
return 0;
}


