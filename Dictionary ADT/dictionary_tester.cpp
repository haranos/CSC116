//
// bst_tester.cpp
//
//
#include <iostream>
#include <string>
#include <sstream>

#include "dictionary.h"

using namespace std;

class dictionary_tester_exception
{
	public:
		dictionary_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s;
			s << _line;

			return _msg + " line number: " + s.str(); 
		}
	private:
		dictionary_tester_exception();
		string _msg;
		unsigned int _line;
};

void test_one()
{
	Dictionary<string, int> d;
	
	if (d.size() != 0 )
		throw dictionary_tester_exception(__FILE__, __LINE__);

	d.insert("abc", 10);
	
	if (d.size() != 1)
		throw dictionary_tester_exception(__FILE__, __LINE__);
	
	d.insert("abc", 15);

	if (d.size() != 1)
		throw dictionary_tester_exception(__FILE__, __LINE__);
	
	try
	{
		int val = d.find("abc");
	
		if (val != 15)
			throw dictionary_tester_exception(__FILE__, __LINE__);
	}
	catch (key_not_found_exception e)
	{
		throw dictionary_tester_exception(__FILE__, __LINE__);
	}

	try
	{
		int val = d.find("def");
		throw dictionary_tester_exception(__FILE__, __LINE__);
		val = val + 1;

	}
	catch (key_not_found_exception e)
	{
		// this is expected	
	}
	cout << __func__ << " passed." << endl;
}

void test_two()
{
	Dictionary<string,int>	d;

	d["bob"] = 5;
	if (d["bob"] != 5)
		throw dictionary_tester_exception(__FILE__, __LINE__);

	if (d["jane"] != 0)
		throw dictionary_tester_exception(__FILE__, __LINE__);

	d["bob"] = 99;
					
	if ( d["bob"] != 99)
	{
		throw dictionary_tester_exception(__FILE__, __LINE__);
	}
	cout << __func__ << " passed." << endl;
}


int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_one();
		tests_passed++;

		test_two();
		tests_passed++;
	}
	catch (dictionary_tester_exception &e)
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

