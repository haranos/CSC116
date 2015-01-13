//
// bst_tester.cpp
//
//
#include <iostream>
#include <string>
#include <sstream>
#include "bst.h"
#include "tree_view.h"

using namespace std;

int tree1_to_add = 15;
const char * tree1_keys[] = { "blue","dog","icecream","hockey","house","car","cry","apple","baseball","apple","school","red","why","dog","street"};
int tree1_values[] = { 18,17,32,41,28,18,18,9,7,41,40,37,8,9,10};
unsigned int tree1_height = 6;
unsigned int tree1_size = 13;
const char*    tree1_keys_preorder[] = {"blue","apple","baseball","dog","car","cry","icecream","hockey","house","school","red","why","street"};
int     tree1_values_preorder[] = {18,41,7,9,18,18,32,41,28,40,37,8,10};
const char*    tree1_keys_postorder[] = {"baseball","apple","cry","car","house","hockey","red","street","why","school","icecream","dog","blue"};
int     tree1_values_postorder[] = {7,41,18,18,28,41,37,10,8,40,32,9,18};
const char*    tree1_keys_inorder[] = {"apple","baseball","blue","car","cry","dog","hockey","house","icecream","red","school","street","why"};
int     tree1_values_inorder[] = {41,7,18,18,18,9,41,28,32,37,40,10,8};
const char*    tree1_keys_levelorder[] = {"blue","apple","dog","baseball","car","icecream","cry","hockey","school","house","red","why","street"};
int     tree1_values_levelorder[] = {18,41,9,7,18,32,18,41,40,28,37,8,10};

int tree2_to_add = 16;
const char * tree2_keys[] = { "blue","baseball","field","field","what","street","sing","bird","yellow","pitch","dog","jump","bike","shop","school","apple"};
int tree2_values[] = { 41,21,39,23,38,3,12,19,6,5,14,33,39,11,23,42};
unsigned int tree2_height = 8;
unsigned int tree2_size = 15;
const char*    tree2_keys_preorder[] = {"blue","baseball","apple","bird","bike","field","dog","what","street","sing","pitch","jump","shop","school","yellow"};
int     tree2_values_preorder[] = {41,21,42,19,39,23,14,38,3,12,5,33,11,23,6};
const char*    tree2_keys_postorder[] = {"apple","bike","bird","baseball","dog","jump","school","shop","pitch","sing","street","yellow","what","field","blue"};
int     tree2_values_postorder[] = {42,39,19,21,14,33,23,11,5,12,3,6,38,23,41};
const char*    tree2_keys_inorder[] = {"apple","baseball","bike","bird","blue","dog","field","jump","pitch","school","shop","sing","street","what","yellow"};
int     tree2_values_inorder[] = {42,21,39,19,41,14,23,33,5,23,11,12,3,38,6};
const char*    tree2_keys_levelorder[] = {"blue","baseball","field","apple","bird","dog","what","bike","street","yellow","sing","pitch","jump","shop","school"};
int     tree2_values_levelorder[] = {41,21,23,42,19,14,38,39,3,6,12,5,33,11,23};

int tree3_to_add = 5;
const char * tree3_keys[] = { "court","globe","school","pitch","hockey"};
int tree3_values[] = { 33,35,9,32,0};
unsigned int tree3_height = 5;
unsigned int tree3_size = 5;
const char*    tree3_keys_preorder[] = {"court","globe","school","pitch","hockey"};
int     tree3_values_preorder[] = {33,35,9,32,0};
const char*    tree3_keys_postorder[] = {"hockey","pitch","school","globe","court"};
int     tree3_values_postorder[] = {0,32,9,35,33};
const char*    tree3_keys_inorder[] = {"court","globe","hockey","pitch","school"};
int     tree3_values_inorder[] = {33,35,0,32,9};
const char*    tree3_keys_levelorder[] = {"court","globe","school","pitch","hockey"};
int     tree3_values_levelorder[] = {33,35,9,32,0};

int tree4_to_add = 14;
const char * tree4_keys[] = { "run","red","bird","bannana","blue","orange","street","icecream","yellow","hockey","football","bird","football","football"};
int tree4_values[] = { 29,11,6,28,13,31,6,6,40,25,1,30,5,0};
unsigned int tree4_height = 8;
unsigned int tree4_size = 11;
const char*    tree4_keys_preorder[] = {"run","red","bird","bannana","blue","orange","icecream","hockey","football","street","yellow"};
int     tree4_values_preorder[] = {29,11,30,28,13,31,6,25,0,6,40};
const char*    tree4_keys_postorder[] = {"bannana","football","hockey","icecream","orange","blue","bird","red","yellow","street","run"};
int     tree4_values_postorder[] = {28,0,25,6,31,13,30,11,40,6,29};
const char*    tree4_keys_inorder[] = {"bannana","bird","blue","football","hockey","icecream","orange","red","run","street","yellow"};
int     tree4_values_inorder[] = {28,30,13,0,25,6,31,11,29,6,40};
const char*    tree4_keys_levelorder[] = {"run","red","street","bird","yellow","bannana","blue","orange","icecream","hockey","football"};
int     tree4_values_levelorder[] = {29,11,6,30,40,28,13,31,6,25,0};

class bst_tester_exception
{
	public:
		bst_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s;
			s << _line;

			return _msg + " line number: " + s.str(); 
		}
	private:
		bst_tester_exception();
		string _msg;
		unsigned int _line;
};

void add_key_values (BinarySearchTree<string, int> &t, const char* keys[], int *values, int count)
{
	for (int i = 0; i < count; i++)
		t.insert(string(keys[i]), values[i]);
}

void compare_lists (const char * key_expected[], int value_expected[], unsigned int count, list<pair<string, int> > &l)
{
	if (count != l.size())
		throw bst_tester_exception(__func__,__LINE__);
	
	list<pair<string,int> >::iterator i = l.begin();
	unsigned int pos = 0;
	while (i != l.end())
	{
		if (i->first != key_expected[pos])
			throw bst_tester_exception(__func__,__LINE__);
		if (i->second != value_expected[pos])
			throw bst_tester_exception(__func__,__LINE__);
		++i;
		pos++;
	}	
}

void tree1_test()
{
	BinarySearchTree<string, int> t;
	add_key_values(t,tree1_keys, tree1_values, tree1_to_add);
	//cout << t.height() << endl;
	if (t.height() != tree1_height)
		throw bst_tester_exception(__func__,__LINE__);

	tree_view<string,int>	v(t);

	// if you aren't passing this test, you can
	// get a printout of your code by uncommenting 
	// this code:
	//
	// v.dot_print(cout);
	//
	// This will output your tree in "dot" language
	// which you can cut and paste here:
	//
	// http://sandbox.kidstrythisathome.com/erdos/
	//
	// to see what your tree actually looks like and 
	// compare it to the picture in the assignment
	// PDF.
	//


	list<pair<string, int> > l = v.preorder();
	compare_lists (tree1_keys_preorder, tree1_values_preorder, tree1_size, l);	

	l = v.postorder();
	compare_lists (tree1_keys_postorder, tree1_values_postorder, tree1_size, l);	

	l = v.inorder();
	compare_lists (tree1_keys_inorder, tree1_values_inorder, tree1_size, l);	

	l = t.key_value_pairs();
	compare_lists (tree1_keys_levelorder, tree1_values_levelorder, tree1_size, l);	

	cout << __func__ << " passed." << endl;
}

void tree2_test()
{
	BinarySearchTree<string, int> t;
	add_key_values(t,tree2_keys, tree2_values, tree2_to_add);

	if (t.height() != tree2_height)
		throw bst_tester_exception(__func__,__LINE__);

	tree_view<string,int>	v(t);

	// if you aren't passing this test, you can
	// get a printout of your code by uncommenting 
	// this code:
	//
	// v.dot_print(cout);
	//
	// This will output your tree in "dot" language
	// which you can cut and paste here:
	//
	// http://sandbox.kidstrythisathome.com/erdos/
	//
	// to see what your tree actually looks like and 
	// compare it to the picture in the assignment
	// PDF.
	//


	list<pair<string, int> > l = v.preorder();
	compare_lists (tree2_keys_preorder, tree2_values_preorder, tree2_size, l);	

	l = v.postorder();
	compare_lists (tree2_keys_postorder, tree2_values_postorder, tree2_size, l);	

	l = v.inorder();
	compare_lists (tree2_keys_inorder, tree2_values_inorder, tree2_size, l);	

	l = t.key_value_pairs();
	compare_lists (tree2_keys_levelorder, tree2_values_levelorder, tree2_size, l);	

	cout << __func__ << " passed." << endl;
}

void tree3_test()
{
	BinarySearchTree<string, int> t;
	add_key_values(t,tree3_keys, tree3_values, tree3_to_add);

	if (t.height() != tree3_height)
		throw bst_tester_exception(__func__,__LINE__);

	tree_view<string,int>	v(t);

	// if you aren't passing this test, you can
	// get a printout of your code by uncommenting 
	// this code:
	//
	// v.dot_print(cout);
	//
	// This will output your tree in "dot" language
	// which you can cut and paste here:
	//
	// http://sandbox.kidstrythisathome.com/erdos/
	//
	// to see what your tree actually looks like and 
	// compare it to the picture in the assignment
	// PDF.
	//


	list<pair<string, int> > l = v.preorder();
	compare_lists (tree3_keys_preorder, tree3_values_preorder, tree3_size, l);	

	l = v.postorder();
	compare_lists (tree3_keys_postorder, tree3_values_postorder, tree3_size, l);	

	l = v.inorder();
	compare_lists (tree3_keys_inorder, tree3_values_inorder, tree3_size, l);	

	l = t.key_value_pairs();
	compare_lists (tree3_keys_levelorder, tree3_values_levelorder, tree3_size, l);	

	cout << __func__ << " passed." << endl;
}

void tree4_test()
{
	BinarySearchTree<string, int> t;
	add_key_values(t,tree4_keys, tree4_values, tree4_to_add);

	if (t.height() != tree4_height)
		throw bst_tester_exception(__func__,__LINE__);

	tree_view<string,int>	v(t);

	// if you aren't passing this test, you can
	// get a printout of your code by uncommenting 
	// this code:
	//
	// v.dot_print(cout);
	//
	// This will output your tree in "dot" language
	// which you can cut and paste here:
	//
	// http://sandbox.kidstrythisathome.com/erdos/
	//
	// to see what your tree actually looks like and 
	// compare it to the picture in the assignment
	// PDF.
	//


	list<pair<string, int> > l = v.preorder();
	compare_lists (tree4_keys_preorder, tree4_values_preorder, tree4_size, l);	

	l = v.postorder();
	compare_lists (tree4_keys_postorder, tree4_values_postorder, tree4_size, l);	

	l = v.inorder();
	compare_lists (tree4_keys_inorder, tree4_values_inorder, tree4_size, l);	

	l = t.key_value_pairs();
	compare_lists (tree4_keys_levelorder, tree4_values_levelorder, tree4_size, l);	

	cout << __func__ << " passed." << endl;
}

void test_insert_size_height()
{
	BinarySearchTree<string,string>	t;

	if (t.height() != 0)
		throw bst_tester_exception(__func__,__LINE__);

	if (t.size() != 0 )
		throw bst_tester_exception(__func__,__LINE__);

	t.insert("bob", "bobdata");
	t.insert("abe", "abedata");
	t.insert("jane", "janedata");

	if (t.height() != 2)
		throw bst_tester_exception(__func__,__LINE__);

	if (t.size() != 3 )
		throw bst_tester_exception(__func__,__LINE__);

	cout << __func__ << " passed." << endl;
}

void test_insert_find()
{
	BinarySearchTree<string,string>	t;

	t.insert("bob", "bobdata");
	t.insert("joe", "joedata");
	t.insert("jane", "janedata");

	try
	{
		string s = t.find("bob");
		if (s != "bobdata")
			throw bst_tester_exception(__func__,__LINE__);
	}
	catch (key_not_found_exception &e)
	{
			throw bst_tester_exception(__func__,__LINE__);
	}

	try
	{
		string s = t.find("sarah");
		throw bst_tester_exception(__func__,__LINE__);
	}
	catch (key_not_found_exception &e)
	{
		// this is expected.
	}
	
	t.insert("bob", "newbobdata");
	try
	{
		string s = t.find("bob");
		if (s != "newbobdata")
			throw bst_tester_exception(__func__,__LINE__);
	}
	catch (key_not_found_exception &e)
	{
			throw bst_tester_exception(__func__,__LINE__);
	}
	cout << __func__ << " passed." << endl;
}


int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_insert_size_height();
		tests_passed++;

		test_insert_find();
		tests_passed++;

		tree1_test();
		tests_passed++;

		tree2_test();
		tests_passed++;

		tree3_test();
		tests_passed++;

		tree4_test();
		tests_passed++;


	}
	catch (bst_tester_exception &e)
	{
		cout << "Failed test case: " << e.what() << std::endl;
	}
	catch (...)
	{
		cout << "Caught unhandled exception." << std::endl;
	}
	cout << "Passed: " << tests_passed << endl;

	return tests_passed;
}

