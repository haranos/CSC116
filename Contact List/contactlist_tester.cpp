//
// Phonebook tester
//

#include <iostream>
#include <string>
#include <sstream>
#include "contactlist.h"

using namespace std;


string names[10] = {"Jenny", "Shea", "Jason", "Macoy", "Robert", 
			"Micaela", "Michael", "Courtney", "Bowen", "Caitlyn" };
string numbers[10] = {"867-5309", "555-8901", "555-8902", "555-8903", "555-8904",
			"555-8905", "555-8906", "555-8907", "555-8908", "555-8909"};
class contactlist_tester_exception
{
	public:
		contactlist_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s;
			s << _line;

			return _msg + " line number: " + s.str(); 
		}
	private:
		contactlist_tester_exception();
		string _msg;
		unsigned int _line;
};

void test_add_lookup()
{
	ContactList mycontacts;
	
	for(int i=0; i<10; i++) 
		mycontacts.addtocontacts(names[i], numbers[i]);
	
	for(int i=9; i>=0; i--) 
		if (mycontacts.lookup(names[i]).compare(numbers[i]) != 0)
			throw contactlist_tester_exception(__func__,__LINE__);
			
	cout << __func__ << " passed." << endl;
}

void test_lookup_update()
{
	ContactList mycontacts;
	
	for(int i=0; i<10; i++) 
		mycontacts.addtocontacts(names[i], numbers[i]);
	
	for(int i=9; i>=0; i--) 
		if (mycontacts.lookup(names[i]).compare(numbers[i]) != 0)
			throw contactlist_tester_exception(__func__,__LINE__);
			
	if (mycontacts.lookup("Celina") != "")
		throw contactlist_tester_exception(__func__,__LINE__);
	

	mycontacts.addtocontacts("Celina", "555-2501");
	if (mycontacts.lookup("Celina") != "555-2501")	
		throw contactlist_tester_exception(__func__,__LINE__);
	
	mycontacts.updatecontact("Celina", "555-9999");
	if (mycontacts.lookup("Celina") != "555-9999")	
		throw contactlist_tester_exception(__func__,__LINE__);
		
	cout << __func__ << " passed." << endl;
	
}

int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_add_lookup();
		tests_passed++;

		test_lookup_update();
		tests_passed++;

	}
	catch (contactlist_tester_exception &e)
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