#pragma once
//not finished
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include<functional>
using std::hash;

//calculate index of left child v[2*k+1]
//calc ind of rchild v[2*k +2]
//calc ind of root v[(k-1)/2


struct node
{

	string ID;
	string parentID;
	string rEvent;

	int leftInd;
	int rightInd;

	string LHASH;
	string RHASH;

	vector<string>LHIST, RHIST;

};

string hashID(string parent, string rawEvent)
{
	string id = rawEvent + parent;
	std::hash<string> hash_fn;
	size_t ID = hash_fn(id);
	int a = ID;
	string b = to_string(a).substr(0, 7);
	return b;

}

string ChildHash(string ID, string parent, string rawE, string LHASH, string RHASH)
{
	string l = ID + parent + rawE + LHASH + RHASH;
	std::hash<string> hash_fn;
	size_t h = hash_fn(l);
	int a = h;
	string b = to_string(a).substr(0, 7);
	return b;

}

void rootNode(vector<struct node> &v1, string rawEvent)
{
	string id = rawEvent + "No Parent";
	string parId = "No Parent";
	std::hash<string> hash_fn;
	size_t ID = hash_fn(id);
	size_t par = hash_fn(parId);
	int a = ID;
	string b = to_string(a).substr(0, 7);
	a = par;
	string c = to_string(a).substr(0, 7);



	struct node root = { b,c,rawEvent,NULL,NULL };
	v1.push_back(root);
}



void fillNode(vector<struct node> &tree, string rawEvent, int i)
{
	tree[i].rEvent = rawEvent;
	tree[i].ID = hashID(tree[i].parentID, rawEvent);

}

void insert(vector<struct node> &tree, string rawEvent)
{
	
	int size = tree.size();
	if (size == 0)
	{
		rootNode(tree, rawEvent);
	}
	else
	{
		for(int i=0;i<size;i++)
		{
			
			if (tree[i].leftInd == NULL && tree[i].rightInd == NULL)
			{
				struct node a = { hashID(tree[i].ID,rawEvent), tree[i].ID, rawEvent, NULL, NULL };
				tree.push_back(a); 
				tree[i].leftInd= (2 * i) + 1;
				
				struct node empty = { hashID(tree[i].ID,"null"),tree[i].ID,"null",NULL,NULL };
				tree.push_back(empty);
				tree[i].rightInd= (2 * i) + 2;
				break;
			}
			else if (tree[tree[i].leftInd].rEvent !="null"  && tree[tree[i].rightInd].rEvent=="null" )
			{
				fillNode(tree, rawEvent, (2 * i + 2));
				break;
			}
			else if (tree[tree[i].rightInd].rEvent != "null"  && tree[tree[i].leftInd].rEvent == "null")
			{
				fillNode(tree, rawEvent, (2 * i + 1));
				break;
			}

		}
	}
}

void updateRightHash(vector <struct node> &tree, int index)
{
	int rchildindex = (2 * index) + 2;
	node r = tree[rchildindex];
	string theID = r.ID;
	string parent = r.parentID;
	string rawE = r.rEvent;
	string left = r.LHASH;
	string right = r.RHASH;
	string a = theID + parent + rawE + right + left;
	hash<string> hash_fn;
	size_t h = hash_fn(a);
	tree[index].RHASH = a;
	int parentIndex = (index - 1) / 2;
	if (parentIndex > 0)
	{
		updateRightHash(tree, parentIndex);
	}
}

void updateLeftHash(vector <struct node> &tree, int index)
{
	int lchildindex = (2 * index) + 1;
	node m = tree[lchildindex];
	string theID = m.ID;
	string parent = m.parentID;
	string rawE = m.rEvent;
	string left = m.LHASH;
	string right = m.RHASH;
	string a = theID + parent + rawE + right + left;
	hash<string> hash_fn;
	size_t h = hash_fn(a);
	tree[index].LHASH = a;
	int parentIndex = (index - 1) / 2;
	if (parentIndex > 0)
	{
		updateLeftHash(tree, parentIndex);
	}
}

void updateRightHist(vector <struct node> &tree, int index)
{
	string a = tree[index].RHASH;
	string b = a.substr(0, 7);
	tree[index].RHIST.push_back(b);
}

void updateLeftHist(vector <struct node> &tree, int index)
{
	string a = tree[index].LHASH;
	string b = a.substr(0, 7);
	tree[index].LHIST.push_back(b);
}

void printpreorder(vector <struct node> &tree, int index)
{
	int size = tree.size();
	int leftindex = (2 * index) + 1;
	int rightindex = (2 * index) + 2;
	cout << tree[index].ID << endl;
	if (tree[leftindex].ID != "NULL" && leftindex < size)
	{
		cout << "| ";
		printpreorder(tree, leftindex);
	}
	if (tree[rightindex].ID != "NULL" && rightindex < size)
	{
		cout << "| ";
		printpreorder(tree, rightindex);
	}
}
