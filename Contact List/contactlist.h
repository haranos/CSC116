#ifndef __CSC116__PHONEBOOK_
#define __CSC116__PHONEBOOK_

#include <iostream>
#include "dictionary.h"

class ContactList
{
public:

	Dictionary<string, string> d;
	
	ContactList()
	{
	}

	~ContactList()
	{
	}
	
	/*
	 * Looks for an entry in contacts that matches name and 
	 * returns the phone number of that entry
	 * 
	 * Pre-conditions:
	 *	none
	 *
	 * Returns:
	 *	if found string representing contacts phone number 
	 *	else returns an empty string
	 *
	 */
	string lookup (string name)
	{
		return d[name];
	}
	
	/*
	 * Adds an entry to contacts with pair <name,number> 
	 * 
	 * Pre-conditions:
	 *	the contact name does not already exist
	 *
	 * Returns:
	 *	none
	 *
	 */
	void addtocontacts (string name, string number) 
	{
		d.insert(name,number);
	}
	
	/*
	 * Updates an existing contact matching name with number
	 * 
	 * Pre-conditions:
	 *	the contact name already exists
	 *
	 * Returns:
	 *	none
	 *
	 */
	void updatecontact (string name, string number) 
	{
		d[name] = number;
	}

private:
	
};

#endif

