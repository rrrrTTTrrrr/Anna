namespace Universe
{


namespace MultiThread
{



enum class Result
{
    
	// The following enumeration purpose - notify user that the operation completed successfully
	Success,

	// The following enumeration purpose - notify user that an instance already exist, and thereforre the operation can not be completed
	AlreadyExist,

	// The following enumeration purpose - notify user that an instance does not exist, and thereforre the operation can not be completed
	DoesNotExist,

};



}  //  Namespace MultiThread


}  //  Namespace Universe