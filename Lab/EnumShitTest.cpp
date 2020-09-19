#include <iostream> 


using namespace std;

// The following enumration describe the list of objects the container ContainerTransformerer support
enum SupportedObjects
{

    // Array objects :
    RawArray = 0,
    BasicTypesArray = 1,
    BasicTypesFixedSizeArray = 2,
    ObjectsArray = 3,
    ObjectsFixedSizeArray = 4,

    // Linked lists objects :
    RawSingleLinkedList = 5,
    RawDoubleLinkedList = 6,
    BasicTypesSingleLinkedList = 7,
    BasicTypesDoubleLinkedList = 8,
    ObjectsSingleLinkedList = 9,
    ObjectsDoubleLinkedList = 10,

    // This will be used to count the number of supported objects. It is declared without a value, to 
    // make the compiler set it's value to 1 more then previous value in the list, which is the number
    // of supported objects
    NumberOfSupportedObjects

};


int main()  
{

	if ( NumberOfSupportedObjects == 11 )
	{
		cout << "Wowwwww" << endl;
	}

	return ( 0 );
}