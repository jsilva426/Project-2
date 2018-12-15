// Project2.cpp 
//Jacob Siva,Matt Hanley, and Jacob Leuquire
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
	bool finished = false;
	vector<struct node> tree;
	while(input!="DONE")
	{
	cout << " Tracking Tree" << endl << "----------------------------------" << endl;
	cout << " Instructions:CREATE ROOT FIRST|root(creates root of tree)| new (for new node)| preorder(Displays preOrder traversal)," << endl;
	cout << " display(shows inormation for a specific node)| update(update contents of specific node)| DONE (closes application) " << endl;
	cout << "----------------------------------" << endl;
	
	
		cout << " Tracking Tree:  ";
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
			PreTrav(tree, 0);
			cout << endl;
		}
		if (input == "display")
		{
			cout << "Enter ID: ";
			cin >> id;
			display(tree, id);

		}
		if (input == "update")
		{
			cout << "Enter ID:  ";
			cin >> id;
			cout << endl << "Enter new event: ";
			cin >> event;
			update(tree, id, event);
			cout << endl << "Record Updated"<<endl;

		}

	}
	return 0;

}
