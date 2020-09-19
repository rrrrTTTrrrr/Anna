#include <iostream> 

using namespace std;

inline void InvokeCPUIDandStoreTheResultToTheMemoryAddress_Private( int set_EAX_toThisValue, int* memoryAddressToStoreTheInformation, int set_ECX_toThisValue )
{

    // The following is an extended inline assembly statement. It will be used to invoke the 'CPUID' instruction to obtain information on the
    // central processing unit, and store it to the given memory address. The first set of 4 bytes at the memory address will store the content of the
    // EAX part of the RAX register, the second set of 4 bytes at the memory address will store the content of the EBX part of the RBX register, The 
    // third set of 4 bytes at the memory address will store the content of the ECX part of the RCX register, and the last 4 bytes set at the memory 
    // address will store the content of the EDX part of the RDX register. This is not possible only using C++

    __asm__ volatile (  "MOV EAX, %[SetEAXtoThisValue];"
                        "MOV ECX, %[SetECXtoThisValue];"
                        "CPUID;"
                        "MOV %[StoreEAX], EAX;"
                        "MOV %[StoreEBX], EBX;"
                        "MOV %[StoreECX], ECX;"
                        "MOV %[StoreEDX], EDX;"

                        : [StoreEAX] "=m" ( *memoryAddressToStoreTheInformation ), [StoreEBX] "=m" ( *( memoryAddressToStoreTheInformation + 1 ) ), [StoreECX] "=m" ( *( memoryAddressToStoreTheInformation + 2 ) ), [StoreEDX] "=m" ( *( memoryAddressToStoreTheInformation + 3 ) )
                        : [SetEAXtoThisValue] "r" ( set_EAX_toThisValue ), [SetECXtoThisValue] "r" ( set_ECX_toThisValue )
                        : "memory", "%eax", "%ebx", "%ecx", "%edx" );

}


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	int result[4] = {0};

    	InvokeCPUIDandStoreTheResultToTheMemoryAddress_Private( 32768, result, 0 );

    	std::cout << (unsigned int)result[0] << std::endl;
    	
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}