namespace Universe 
{

namespace CentralProcessingUnit
{



//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void ReadAndWriteFromInputOrOutputDevices::UnitTest()
	{
		WriteByteToInputOrOutputPort( 0x01, 0x70 );

		auto mm = ReadByteFromInputOrOutputPort( 0x71 );

		std::cout << mm << std::endl;
	}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe