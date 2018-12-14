#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;
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

	vector<string>LHIST,RHIST;

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

string leftChildHash(string ID ,string parent, string rawE,string LHASH,string RHASH)
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



	struct node root = { b, rawEvent,c,-1,-1 };
	v1.push_back(root);
}



void setLChild(vector<struct node> &tree, int curr, string rawEvent)
{
	int leftIndex = tree.size();
	tree[curr].leftInd = leftIndex;
	struct node n = { NULL,rawEvent,NULL,-1,-1 };
	tree.push_back(n);
}

void setrChild(vector<struct node> &tree, int curr, string rawEvent)
{
	int rightIndex = tree.size();
	tree[curr].rightInd = rightIndex;
	struct node n = { NULL,rawEvent,NULL,-1,-1 };
	tree.push_back(n);
}


void Insert(vector<struct node> &tree, string rawE)
{
	if (tree.size() == 0)
	{
		cout << "No root, create a root first" << endl;
		return;
	}
	int curr = 0;
	while (curr < tree.size())
	{
		if (rawE <= tree[curr].rEvent)
		{
			if (tree[curr].leftInd == -1)
			{
				setLChild(tree, curr, rawE);
				break;
			}
			else
				curr = tree[curr].leftInd;
		}
		else
		{
			if (tree[curr].rightInd == -1)
			{
				setrChild(tree, curr, rawE);
				break;
			}
			else
				curr = tree[curr].rightInd;
		}
	}
