namespace Universe
{


    namespace CentralProcessingUnit
    {



// Central processing unit clock cycle counter :
//
//	The Intel 64 architecture define a time stamp counter mechanism that can be used to monitor and identify the relative time occurrence of processor
//	events. The counter's architecture includes the following components :
//
//		1. Time stamp counter flag ( TSC ) - a feature bit that indicates the availability of the time stamp counter. The counter is available if
//		   the the state of the bit using the 'CPUID' instruction is 1 ( CPUID.1:EDX.TSC[bit 4] = 1 )
//		2. IA32_TIME_STAMP_COUNTER model specific register - this is used as the counter
//		3. 'RDTSC' instruction - used to read the time stamp counter
//		4. Time stamp disable flag ( TSD ) - a control register flag is used to enable or disable the time stamp counter ( enabled if CR4.TSD[bit 2] = 1 )
//
//	The time stamp counter is 64 bit. It is initialized to 0 following a 'RESET' instruction to the processor. After initialization, the counter
//	increments even when the processor is halted by the 'HLT' instruction or the external STPCLK# pin. Note that the assertion of the external 
//	DPSLP# pin may cause the time stamp counter to stop.
//
//	There are 2 ways to increment the time stamp counter :
//
//		1. The time stamp counter increments with every internal processor clock cycle. The internal processor clock cycle is determind by the current
//		   core clock to bus clock ratio. Intel feature 'SpeedStep' transitions may also impact the processor clock
//		2. The time stamp incremetns at a constant rate. That rate may be set by the maximum core clock to bus clock ratio of the processor or may 
//		   be set by the maximum resolved frequency at which the processor is booted. The maximum resolved frequency may differ from the processor
//		   base frequency and on certain processors the frequency may not be the same as the frequency in the brand string
//	
//	The specific processor configuration determines the behavior. Constant time stamp counter behavior ensures that the duration of each clock tick
//	is uniform and supports the use of it as a 'clock' even if the processor core changes frequency!
//
//	The 'RDTSC' instruction reads the time stamp counter and is guaranteed to return a monotonically increasing unique value whatever executed,
//	except for when the 64 bits all been used the next increment will set the counter to 0 and from it will continue normally. Intel guarantees
//	that this will not happen within 10 years from restart. 
//
//	Normally, the 'RDTSC' instruction can be executed by programs and procedures at any privilege level. The time stamp disable flag allows use 
//	of this instruction to be restricted to programs and procedures running at privilege level 0. A secure operating system would set this flag
//	during system initialization to disable user access to the time stamp counter.
//
//	The 'RDTSC' instruction is not serializing or ordered with the other instructions. It does not necessarily wait until all previous instructions
//	have been executed before reading the counter. Similarly, subsequent instructions may begin execution before the 'RDTSC' instruction operation
//	is performed.
//
//	The 'RDMSR' and 'WRMSR' instructions read and write the time stamp counter, treating the time stamp counter as an ordinary model specific
//	register ( address 0x10 ).
	//		
	//	The time stamp counter may support an enhancement, refered to as invariant time stamp counter. Processors support for this feature are
	//	indicated by CPUID.80000007H:EDX[8]. The invariant time stamp counter will run at a constant rate in all ACPI P-, C-. and T-states. Operating
	//	systems may use this counter for real time services. Time stamp counter reads are much more efficient and od not incur the overhead associated
	//	with a ring transition or access to a platform resource.
	//
	//	Software can modify the value of the time stamp counter of a logical processor by using the 'WRMSR' instruction to write to the model specific
	//	register IA32_TIME_STAMP_COUNTER ( address 0x10 ). Because such a write applies only to that logical processor, software seeking to synchronize
	//	the time stamp counter values of multiple logical processors must perform these writes on each logical processor. It may be difficult for
	//	software to do this in a way that ensures that all logical processors will have the same value for the time stamp counter at the given point
	//	in time.
	//
	//	The synchronization adjustment can be simplified by using the 64 bit IA32_TSC_ADJUST model specific register ( address 0x3B ). Like the
	//	IA32_TIME_STAMP_COUNTER model specific register is maintained separately for each logical processor. A logical processor maintains and 
	//	uses the IA32_TSC_ADJUST model specific register as follows :
	//
	//		1. On reset, the value of the IA32_TSC_ADJUST will be 0
	//		2. If an execution of the 'WRMSR' to the IA32_TIME_STAMP_COUNTER adds or subtracts value from it, the logical processor also adds or
	//		   subtracts the same value from the IA32_TSC_ADJUST and vice versa 
	//
	//	Unlike the time stamp counter, the value of the IA32_TSC_ADJUST changes only in response to 'WRMSR'. Its value does not otherwise change
	//	as time elapses. Software seeking to adjust the time stamp counter can do so by using 'WRMSR' to write the same value to the IA32_TSC_ADJUST
	//	on each logical processor. Processor support for the IA32_TSC_ADJUST model specific register is indicated by CPUID.EAX=0x07:EBX.TSC_ADJUST[bit 1].
	//
	//	The invariant time stamp counter is based on the invariant timekeeping hardware called 'Always Running' ( ART ), that runs at the core crystal 
	//	clock frequency. The ratio defined by CPUID leaf 0x15 expresses the frequency relationshio between the 'Always Running' hardware and the time
	//	stamp counter. If CPUID.15H:EBX[31:0] is not zero and CPUID.80000007:EDX.InvariantTSC[bit ] = 1, the following linearity relationship holds 
	//	between the time stamp counter and the 'Always Running' hardware :
	//
	//		TimeStampCounterValue = ( ( AlwaysRunningValue *  CPUID.15H:EBX[31:0] ) / CPUID.15H:EAX[31:0] ) + Constant
	//
	//	Where the constant is an offset that can be adjusted by a privileged agent. When 'Always Running' hardware is reset both invariant time stamp
	//	counter and the constant are reset also
	


// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//      1. The object inherits from the object NoInstances to prevent any instances of the object
//
//		2. This object inherits a well defined default state, to state that it is not suited for use in it's current state, from the object DefaultStateCapable
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ClockCycleCounter
{
public:


    // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//			NONE
		//
		//  Expectations :
		//
		//		Please let the test pass lord!!
		//
		//  Possible errors :
		//
		//		It says there are no problems, which is even scarier, did I just wrote a working code??
		//
		static void UnitTest();

	)  //  End of debug tool


private:


};  //  Class ClockCycleCounter



    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe