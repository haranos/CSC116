#ifndef __CSC116__DICTIONARY__
#define __CSC116__DICTIONARY__

#include <iostream>
#include "bst.h"

// The dictionary class supports two main operations:
//	insert
// 	find
//
// with the additional convinience of operator[].
//

template <class K, class V> class Dictionary
{
public:
	
	BinarySearchTree<K, V> bst;
	// Constructor
	Dictionary()
	{
	}
	
	// Destructor
	~Dictionary()
	{
	}

	//
	// Purpose:
	//	return a reference to the value stored at key
	//
	// 	If key is not in the dictionary, add a new
	//	key / value pair, at the key.  Use the 
	//	default constructor to initialze the value and
	//	return a reference to that value.
	//
	//Dictionary<K, V> d;
	V & operator[] (K key)
	{
		// unfortunately there is nothing I can write
		// here that will make this compile without warnings.

		V deflt = V();
		try
		{
			bst.find(key);
		}
		catch (key_not_found_exception &e)
		{
			bst.insert(key,deflt);
			return bst.find(key);
		}
		
		return bst.find(key);
	}

	//
	// Purpose:
	//	Add a new key/value pair to the dictionary.
	//
	void insert (K key, V value)
	{	
		bst.insert(key,value);
	}

	//
	// Purpose:
	//	Return the value stored at key.
	//	
	//	throw key_not_found_exception if key is not in the 
	//	dictionary.
	V & find (K key)
	{
		// unfortunately there is nothing I can write
		// here that will make this compile without warnings.
		return bst.find(key);
	}

	//
	// Purpose:
	//	Return a list of all the key/value pairs in the
	//	dictionary.
	//
	list<pair<K,V> > key_value_pairs() 
	{
	}

	//
	// Purpose:
	//	Return the number of elements stored in the dictionary
	//
	unsigned int size()
	{
		return bst.size();
	}

private:
	//int m_count;

};

#endif

