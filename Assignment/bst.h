#ifndef __CSC116__BST_H__
#define __CSC116__BST_H__

//
// An implementation of a binary search tree.
//
// This tree stores both keys and values associated with those keys.
//
// More information about binary search trees can be found here:
//
// http://en.wikipedia.org/wiki/Binary_search_tree
//
// Note: Wikipedia is using a different definition of 
//       depth and height than we are using.  Be sure
//       to read the comments in this file for the
//	 height function.
//

#include <list>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;


//
// Each node in the tree stores
// both a key and a value
//
template <class K, class V> class TreeNode
{
public:
	TreeNode(K k, V v): key(k), value(v), left(0), right(0) {}

	K		key;
	V		value;
	TreeNode<K,V>	*left;
	TreeNode<K,V>	*right;
	template <class X, class Y> friend std::ostream & operator<< (std::ostream &s, const TreeNode<X,Y> &t);
};

// 
// TreeNodes can output themselves to streams
template <class K, class V> std::ostream & operator << (std::ostream &s, const TreeNode<K,V> &n)
{
	s << "\"" << n.key << ":" << n.value << "\"";
	return s;
}

//
// This exception is thrown if you try to find 
// a key in the tree that isn't present.
//

class key_not_found_exception {
};

//
// The binary search tree class.
//
// When creating an instance of the class you need
// to specify the type for both the key and the values
// stored.
//
// For example:
//
// BinarySearchTree<string, int> t1;
//
// or:
//
// BinarySearchTree<int, bool> t2;
//

template <class K, class V> class BinarySearchTree {
public:
	//
	// Constructor
	//
	BinarySearchTree ()
	{
		count = 0;
		root = NULL;
	}

	// 
	// Destructor
	// 
	// You must call delete on all the nodes in the
	// tree.  You will need to implement
	// a helper function that performs a post-order
	// traversal over the tree deleting nodes after
	// both children have been deleted.
	//
	~BinarySearchTree()
	{
	}

	//
	// Purpose:
	//
	// Insert a new Key:Value pair into the tree.  If the Key
	// already exists in the tree, update the value stored at 
	// that node with the new value.
	//
	// Pre-Conditions:
	// 	the tree is a valid binary search tree
	// 
	void insert (K k, V v)
	{
		if (root == NULL)
		{
			root = new TreeNode<K,V>(k,v);
			count++;
		}

		else 
		{
			TreeNode<K,V>	*pointer;
			pointer = root;
			
			unsigned int inserted = 0;
			while (inserted == 0)
			{
				if (k == pointer->key)
				{
					pointer->value = v;
					inserted = inserted+1;
				}
				else if (k < pointer->key)
				{
					if (pointer->left == NULL){
						pointer->left = new TreeNode<K,V>(k,v);
						count++;
						inserted = inserted+1;
					}
					else{
						pointer = pointer->left;
					}
				}
				else if (k > pointer->key)
				{
					if (pointer->right == NULL){
						pointer->right = new TreeNode<K,V>(k,v);
						count++;
						inserted = inserted+1;
					}
					else{
						pointer = pointer->right;
					}
				}
			}//end while

		}
	}

	//
	// Purpose:
	//
	// Return the value stored at key.  Throw a key_not_found_exceptoin
	// if the key isn't in the tree.
	//
	// Pre-conditions:
	//	the tree is a valid binary search tree
	//
	// Returns:
	//	they value stored at key
	//
	// Throws:
	//	key_not_found_exception if key isn't in the tree
	//	
	K target_key;
	V & find (K key)
	{
		target_key = key;
		return doFind(root);
	}
	
	V & doFind (TreeNode<K,V> *t)
	{
		if (t == NULL)
			throw key_not_found_exception();
		
		else if (t->key == target_key)
			return t->value;
		
		else if (t->key > target_key)
		{
			return doFind(t->left);
		}
		else  //(t->key < target_key)
		{
			return doFind(t->right);
		}
		
	}

	//
	// Purpose:
	//
	// Return the number of nodes in the tree.
	//
	// Returns:
	//	the number of nodes in the tree.
	unsigned int size()
	{
		return count;
	}

	//
	// Purpose:
	//
	// Return the height of the tree.  We define height
	// as being the number of nodes on the path from the root
	// to the deepest node.
	// 
	// This means that a tree with one node has height 1.
	// 
	// Examples:
	//	See the assignment PDF and the test program for
	//	examples of height.
	//
	unsigned int height()
	{
		return doHeight(root);
	}

	//
	// Purpose:
	//
	// Return a list of all the key/value pairs stored in the tree
	// The list will be constructed by performing a level-order
	// traversal of the tree.
	//
	// Level order is most commonly implemented using a queue of nodes.
	//
	//  From wikipedia (they call it breadth-first), the algorithm for level order is:
	//
	//	levelorder()
	//		q = empty queue
	//		q.enqueue(root)
	//		while not q.empty do
	//			node := q.dequeue()
	//			visit(node)
	//			if node.left ≠ null then
	//			      q.enqueue(node.left)
	//			if node.right ≠ null then
	//			      q.enqueue(node.right)
	// There is some inefficiency here as the list is copied.
	//
	
	list<pair<K,V> > key_value_pairs() 
	{
		list<pair<K, V> > l;
		doLevelOrder(l,root);
		return l;			
	}	
	
	void doLevelOrder (list<pair<K,V> > &l, TreeNode<K,V> *n)
	{
		if (!n)
			return;
			
		queue<TreeNode<K,V> *> q;
		q.push(n);
		l.push_back(make_pair(n->key,n->value));
		while (!q.empty())
		{
			TreeNode<K,V> *   pos = q.front();
			q.pop();
			if (pos->left != NULL)
			{
				q.push(pos->left);
				l.push_back(make_pair(pos->left->key,pos->left->value));
			}
			if (pos->right != NULL)
			{
				q.push(pos->right);
				l.push_back(make_pair(pos->right->key,pos->right->value));
			}
			//cout << "1 " << endl;
		}
	
	}

private:

	unsigned int doHeight (TreeNode<K,V> *t)
	{
		if (t == NULL)
			return 0;
		else
		{
			unsigned int left_height = doHeight(t->left);
			unsigned int right_height = doHeight(t->right);
			if (left_height > right_height)
				return (left_height+1);
			else 
				return (right_height+1);
		}
	}

	void		doDelete (TreeNode<K,V> * n )
	{
	}

	TreeNode<K,V>	*root;
	unsigned int	count;

	template <class X, class Y> friend class tree_view;	
	template <class X, class Y> friend std::ostream & operator << (std::ostream &s, const BinarySearchTree<X,Y> &t);
};

template <class K,class V> void do_inorder (std::ostream &s, const TreeNode<K,V> *n)
{
	if (!n)
		return;
	do_inorder(s,n->left);
	s << n->key << ":" << n->value << " ";
	do_inorder(s,n->right);
}

//
// Output the tree to a stream by doing an in-order traversal
//
template <class K, class V> std::ostream & operator << (std::ostream &s, const BinarySearchTree<K,V> &t)
{
	s << "{ ";
	do_inorder(s,t.root);
	s << "}";
	return s;
}
#endif

