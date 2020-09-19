








                                                                            // ********************************************* //
                                                                            // ********************************************* //
                                                                            // **                                         ** //
                                                                            // **        INPUT AND OUTPUT DEVICES         ** //
                                                                            // **                                         ** //
                                                                            // ********************************************* //
                                                                            // ********************************************* //











// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\
// *                                                                                                                                                                                                * \\
// *                                                                                             OVERVIEW                                                                                           * \\
// *                                                                                                                                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\




  // In addition to providing abstractions such as processes, address spaces and files an operating system also controls all the computer's input and output
  // devices. It must issue commands to the devices, catch interrupts and handle errors. It should also provide interface between the devices and the rest of
  // the system that is simple and easy to use. To the extent possible, the interface should be the same for all devices ( device independent ). The input and
  // output code represents a significant fraction of the total operating system



// ************************************************************************************************************************************************************************************************** \\
// *                                                                             PRINCIPLES OF INPUT AND OUTPUT HARDWARE                                                                            * \\
// ************************************************************************************************************************************************************************************************** \\



  // Programmers look at the interface presented to the software - the commands the hardware accepts, the functions it carries out and the errors that can be
  // reported back. The programming of many input and out devices is often intimately connected with their internal operation.
  //
  // Input and output devices can be roughly divided into two categories, block devices and character devices. A block device is one that store information in
  // fixed size blocks, each one with its own address. Common block sizes range from 512 to 65536 bytes. All transfers are in units of one or more entire
  // blocks. The essential property of a block device is that it is possible to read or write each block independently of all the other ones. Hard disks,
  // Blu-ray discs and USB sticks are common block devices!
  //
  // A character device delivers or accepts a stream of characters, without regard to any block structure. It is not addressable and does not have any seek
  // operation. Printers, network interfaces, mice and most other devices that are not disk like can be seen as character devices.
  //
  // This classification scheme is not perfect. Some devices do not fit in. Clocks for example, are not block addressable. Nor do they generate or accept
  // character streams. All they do is cause interrupts at well defined intervals. Memory mapped screens do not fit the model well either. Nor do touch
  // screens. Still, the model of block and character devices is general enough that it can be used as a basis for making some of the operating system
  // software dealing with input and output devices independent. The file system, for example, deals just with abstract block devices and leaves the devices
  // dependent part to lower level software.
  //
  // Input and output devices cover a huge range in speeds, which puts considerable pressure on the software to perform well over many orders of magnitude
  // in data rates



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                       DEVICE CONTROLLERS                                                                                       * \\
// ************************************************************************************************************************************************************************************************** \\



  // Input and output units often consist of a mechanical component and an electronic component. It is possible to separate the two portions to provide a more
  // modular and general design. The electronic component is called the device controller or adapter. On personal computers, it often takes the form of a chip
  // on the parentboard or a printed circuit card that can inserted into ( PCIe ) expansion slot. The mechanical component is the device itself.
  //
  // The controller card usually has a connector on it, into which a cable leading to the device itself can be plugged. Many controllers can handle two, four
  // or even eight identical devices. If the interface between the controller and device is a standard interface, either an official ANSI, IEEE or ISO standard
  // or a de facto one, then companie can make controllers or devices that fit that interface.
  //
  // This interface between the controller and the device is often a very low level one. A disk for example, might be formatted with 2 million sectors of 512
  // bytes per track. What actually comes off the drive, however, is a serial bit stream, starting with a preamble, then the 4096 bits in a sector, and finally
  // a checksum, or error correcting code ( ECC ). The preamble is written when the disk is formatted and contains the cylinder and sector number, the sector
  // size and similar data as well as synchronization information.
  //
  // The controller's job is to convert the serial bit stram into a block of bytes and perform any error correction necessary. The block of bytes is typically
  // first assembled, bit by bit, in a buffer inside the controller. After its checksum has been verified and the block has been declared to be error free, it
  // can then be copied to main memory.
  //
  // The controller for an LCD display monitor also works as a bit serial device at an equally low level. It reads bytes containing the characters to be displayed
  // from memory and generates the signals to modify the polarization of the back light for the corresponding pixels in order to write them on screen. If it were
  // not for the display controller, the operating system programmer would have to explicitly program the electric fields of all pixels. With the controller, the
  // operating system initializes the controller with a few parameters, such as the number of characters or pixels per line and number of lines per screen, and
  // lets the controller take care of actually drive the electric fields



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                MEMORY MAPPED INPUT AND OUTPUT                                                                                  * \\
// ************************************************************************************************************************************************************************************************** \\



  // Each controller has a few registers that are used for communicating with the central processing unit. By writing into these registers, the operating system
  // can command the device to deliver data, accept data, switch itself on or off or otherwise perform some action. By reading from these registers, the operating
  // system can learn what the device's state is, whether it is prepared to accept a new command, and so on.
  //
  // In addition to the control registers, many devices have a data buffer that the operating system can read and write. The issue thus arises of how the central
  // processing unit communicates with the control registers and also with the device data buffers. Two alternatives exist. In the first approach each control
  // register is assigned an input and output port number, an 8 or 16 bit integer. The set of all the input and output ports from the input and output port space,
  // which is protected so that ordinary user programs cannot access it. Using a special input and output instruction such as :
  //
  //    IN PORT, REGISTER
  //
  // The central processing unit can read in control register 'PORT' and store the result in the central processing unit register 'REGISTER'. Similarly, using :
  //
  //    OUT REGISTER, PORT
  //
  // The central processing unit can write the content of the register to a control register. Most early computers, including nearly all mainframes worked this way.
  // In this scheme, the address spaces for memory and input and output are different. The instructions :
  //
  //    IN 4, RAX    -    MOV $4, RAX
  //
  // Are completely different in this design. The former reads the contents of input and output of port 4 and puts it into the 'RAX' register whereas the latter
  // reads the contents of memory address 4 and puts it into the register. The 4's in these examples refer to different and unrelated address spaces!
  //
  // The second approach, is to map all the control registers into the memory space. Each control register is assigned a unique memory address to which no memory
  // is assigned. This system is called memory mapped input and output. In most systems, the assigned addresses are at or near the top of the address space. A
  // hybrid scheme, with memory mapped input and output data buffers and separate input and output ports for the control registers also exist.
  //
  // In all cases when the central processing unit wants to read a word, either from memory or from an input and output port, it puts the address it needs on the
  // bus address lines and then asserts a READ signal on the bus control line. A second signal line is used to tell whether input and output space or memory
  // space is needed. If it is memory space, the memory responds to the request. If it is input and output space, the input and output device responds to the
  // request. If there is only memory space, every memory module and every input and output device compares the address lines to the range of addresses that it
  // services. If the address falls in its range, it responds to the request. Since no address is ever assigned to both memory and an input and output device,
  // there is no ambiguity and no conflict.
  //
  // These two schemes for addressing the controllers have different strengths and weaknesses. First of all, if special input input and output instructions are
  // needed to read and write the device control registers, access to them requires the use of assembly code since there is no way to execute an IN or OUT
  // instruction in C/C++. Calling such a procedure adds overhead to controlling input and output. In contrast, with memory mapped input and output, device
  // control registers are just variables in memory and can be addressed in C the same way as any other variables. Thus with memory mapped input and output,
  // an input and output device driver can be written entirely in C. Without memory mapped input and output, some assembly code is needed. Second, with memory
  // mapped input and output, no special protection mechanism is needed to keep user processes from performing input and output. All the operating system has
  // to do is refrain from putting that portion of the address space containing the control registers in any user's virtual address space. Better yet, if each
  // device has its control registers on a different page of the address space, the operating system can give a user control over specific devices but not
  // others by simply including the desired pages in its page table. Such a scheme can allow different device drivers to be placed in different spaces, not
  // only reducing kernel size but also keeping one driver from interfering with others. Third, with memory mapped input and output, every instruction that
  // can reference memory can also reference control registers. For example, if there is an instruction, TEST, that tests memory word for 0, it can also be
  // used to test a control register for 0, which might be the signal that the device is idle and can accept a new command. The assembly code might look like
  // this :
  //
  //    LOOP:
  //
  //      TEST PORT_4         // Check if port 4 is 0
  //      BEQ READY           // If it is 0, go to ready
  //      BRANCH LOOP         // Otherwise, continue testing
  //
  //    READY:
  //
  // If memory mapped input and output is not present, the control register must first be read into the central processing unit, then tested, requiring two
  // instructions instead of just one. In the case of the loop given above, a fourth instruction has to be added, slightly slowing down the responsiveness of
  // detecting an idle device.
  //
  // In computer design, practically everything involves trade-offs, and that is the case here, too. Memory mapped input and output also has its disadvantages.
  // First. most computers nowadays have some form of caching of memory words. Caching a device control register would be disastrous. The assembly code loop
  // given above in the presence of caching would cache the first reference to 'PORT_4'. Subsequent references would just take the value from the cache and
  // not even ask the device. Then when the device finally became ready, the software would have no way of finding out. Instead, the loop would go on forever.
  // To prevent this situation with memory mapped input and output, the hardware has to able to selectively disable caching, for example, on a per page basis.
  // This feature adds extra complexity to both the hardware and the operating system, which has to manage the selective caching. Second, if there is only
  // one address space, then all memory modules and all input and output devices must examine all memory references to see which ones to respond to. If the
  // computer has a single bus, having everyone look at every address is straightforward. However, the trend in modern personal computers is to have a
  // dedicated high speed memory bus. The bus is tailored to optimize memory performance, with no compromises for the sake of slow input and output devices.
  // x86 systems can have multiple buses ( memory, PXIe, SCSI, and USB ). The trouble with having a separate memory bus on memory mapped machines is that
  // the input and output devices have no way of seeing memory addresses as they go by on the memory bus, so they have no way of seeing memory addresses
  // as they go by on the memory bus, so they have no way of responding to them. Again, special measures have to be taken to make memory mapped input and
  // output work on system with multiple buses. One possibility is to first send all memory references to the memory. If the memory fails to respond, then
  // the central processing unit tries the other buses. This design can be made to work but requires additional hardware complexity. A second possible
  // design is to put a snooping device on the memory bus to pass all addresses presented to potentially interested input and output devices. The problem
  // here is the input and output devices may not be able to process requests at the speed the memory can. A third possible design, is to filter addresses
  // in the memory controller. In that case, the memory controller chip contains range registers that are preloaded at boot time. For example, 640K to 1M
  // could be marked as a non memory range. Addresses that fall within one of the ranges marked as non memory are forwarded to devices instead of to memory.
  // The disadvantage of this scheme is the need for figuring out at boot time which memory addresses are not really memory addresses. Thus each scheme has
  // arguments for and against it, so compromises and trade-offs are inevitable



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                    DIRECT MEMORY ACCESS                                                                                        * \\
// ************************************************************************************************************************************************************************************************** \\



  // No matter whether a central processing unit does or does not have memory mapped input and output, it needs to address the device controllers to exchange
  // data with them. The central processing unit can request data from and input and output controller one byte at a time, but doing so wastes the central
  // processing unit's time, so a different scheme, called direct memory access ( DMA ) is often used. To simplify the explanation, an assumption is made that
  // the central processing unit accesses all devices and memory via a single system bus that connects the central processing unit, the memory and the input
  // and output devices. The operating system can only use direct memory access if the hardware has a direct memory address controller, which most systems do.
  // Sometimes this controller is integrated into disk controllers and other controllers, but such a design requires a separate direct memory access controller
  // for each device. More commonly, a single direct memory access controller is available for regulating transfers to multiple devices, often concurrently.
  //
  // No matter where it is physically located, the direct memory access controller has access to the system bus independent of the central processing unit.
  // It contains several registers that can be written and read by the central processing unit. These include a memory address register, a byte count register
  // and one or more control registers. The control registers specify the input and output port to use, the direction of the transfer ( reading or writing
  // from the input and output device ), the transfer unit ( byte or word at a time ) and the number of bytes to transfer in one burst.
  //
  // To explain how direct memory access works, the first step is to understand how disk reads occur when direct memory access is not used. First the disk
  // controller reads the block ( one or more sectors ) from the drive serially, bit by bit, until the entire block is in the controller's internal buffer.
  // Next, it computes the checksum to verify that no read errors have occurred. Then the controller causes an interrupt. When the operating system starts
  // running, it can read the disk block from the controller's buffer a byte or a word at a time by executing a loop, with each iteration reading one byte
  // or word from a controller device register and storing it in main memory.
  //
  // When direct memory access is used, the procedure is different. First the central processing unit programs the direct memory access controller by setting
  // its registers so it knows what to transfer where. It also issues a command to the disk controller telling it to read data from the disk into its internal
  // buffer and verify the checksum. When valid data are in the disk controller's buffer, direct memory access can begin.
  //
  // The direct memory access controller initiates the transfer by issuing a read request over the bus to the disk controller. This read request looks like
  // any other read request, and the disk controller does not know whether it came from the central processing unit or from the direct memory access controller.
  // Typically, the memory address to write to is on the bus address lines, so when the disk controller fetches the next word from its internal buffer, it
  // knows where to write it. The write to memory is another standard bus cycle. When the write is complete, the disk controller sends an acknowledgement
  // signal to the direct memory access controller, also over the bus. The direct memory access controller then increments the memory address to use and
  // decrements the byte count. If the byte count is still greater than 0, the steps are repeated until the count reaches to 0. At that time, the direct
  // memory access controller interrupts the central processing unit to let it know that the transfer is now complete. When the operating system starts up,
  // it does not have to copy the disk block to memory, it is already there.
  //
  // Direct memory access controllers vary considerably in their sophistication. The simplest ones handle one transfer at a time, as described above. More
  // complex ones can be programmed to handle multiple transfers at the same time. Such controller have multiple sets of registers internally, one for each
  // channel. The central processing unit starts by loading each set of registers with the relevant parameters for its transfer. Each transfer must use a
  // different device controller. After each word is transferred the direct memory access controller decides which device to service next. It may be set up
  // to use a round robin algorithm, or it may have a priority scheme design to favor some devices over others. Multiple requests to different device
  // controllers may be pending at the same time, provided that there is an unambiguous way to tell the acknowledgements apart. Often a different acknowledgement
  // line on the bus us used for each direct memory access channel for this reason.
  //
  // Many buses can operate in two modes, word at a time mode or block mode. Some direct memory access controllers can also operate in either mode. In the former
  // mode, the operation is as described above, the direct memory access controller requests of one word and gets it. If the central processing unit also wants
  // the bus, it has to wait. The mechanism is called cycle stealing because the device controller sneaks in and steals an occasional bus cycle from the central
  // processing unit, delaying it slightly. In block mode, the direct memory address controller tells the device to acquire the bus, issue a series of transfers,
  // then release the bus. This form of operation is called burst mode. It is more efficient than cycle stealing because acquiring the bus takes time and multiple
  // words can be transferred for the prices of on bus acquisition. The down side to burst mode is that it can block the central processing unit and other
  // devices for a substantial period if a long burst is being transferred.
  //
  // In the model discussed, sometimes called 'fly by mode', the direct memory access controller tells the device controller to transfer the data directly to main
  // memory. An alternative mode that some direct memory access controllers use is to have the device controller send the word to the direct memory access controller,
  // which then issues a second bus request to write to the word to wherever it is supposed to go. This scheme requires an extra bus cycle per word transferred,
  // but is more flexible in that it can also perform device to device copies and even memory to memory copies ( by first issuing a read to memory and then issuing
  // a write to memory at a different address ).
  //
  // Most direct memory access controllers use physical memory addresses for their transfers. Using physical addresses requires the operating system to convert
  // the virtual address of the intended memory buffer into a physical address and write this physical address into the direct memory access controller's address
  // register. An alternative scheme used in a few direct memory access controllers is to write virtual addresses into the direct memory access controller instead.
  // Then the direct memory access controller must use the memory management unit ( MMU ) to have the virtual to physical translation done. Only in the case that
  // the memory management unit is part of the memory, rather then part of the central processing unit, can virtual addresses be put on the bus.
  //
  // The disk controller needs an internal data buffer for two reasons. First, by doing internal buffering, the disk controller can verify the checksum before
  // starting a transfer. If the checksum is incorrect, an error is signaled and no transfer is done. The second reason is that once a disk transfer has
  // started, the bits keep arriving from the disk at a constant rate, whether the controller is ready for them or not. If the controller tried to write data
  // directly to memory, it would have to go over the system bus for each word transferred. If the bus were busy due to some other device using it, the controller
  // would have to wait. It the next disk word arrived before the previous one have been stored, the controller would have to store it somewhere. If the bus were
  // very busy, the controller might end up storing quite a few words and having a lot of administration to do as well. When the block is buffered internally, the
  // bus is not needed until the direct memory access begins, so the design of the controller is much simpler because the direct memory access transfer to memory
  // is not time critical.
  //
  // Not all computers use direct memory access. The argument against it is that the main central processing unit is often far faster then the direct memory access
  // controller and can do the job much faster ( when the limiting factor is not the speed of the input and output device ). If there is no other work for it to
  // do, having the fast central processing unit wait for the slow direct memory access controllers to finish is pointless!



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                    INTERRUPTS REVISITED                                                                                        * \\
// ************************************************************************************************************************************************************************************************** \\



  // At the hardware level, interrupts work as follows. When an input and output device has finished the work given to it, it causes an interrupt ( assuming that
  // interrupts have been enabled by the operating system ). It does this by asserting a signal on a bus line that it has been assigned. This signal is detected
  // by the interrupt controller chip on the parent board, which then decides what to do.
  //
  // If no other interrupts are pending, the interrupt controller handles the interrupt immediately. However, if another interrupt is in progress, or another
  // device has made a simultaneous request on a higher priority interrupt request line on the bus, the device is just ignored for the moment. In this case it
  // continues to assert an interrupt signal on the bus until it is serviced by the central processing unit.
  //
  // To handle the interrupt, the controller puts a number on the address lines specifying which device wants attention and asserts a signal to interrupt the
  // central processing unit. The interrupt signal causes the central processing unit to stop what it is doing and start doing something else. The number on the
  // address lines is used as an index into a table called the interrupt vector to fetch a new program counter. This program counter points to the start of the
  // corresponding interrupt service procedure. Typically traps and interrupts use the same mechanism from this point on, often sharing the same interrupt
  // vector. The location of the interrupt vector can be hardwires into the machine or it can be anywhere in memory, with a central processing unit register
  // ( loaded by the operating system ) pointing to its origin.
  //
  // Shortly after it starts running, the interrupt service procedure acknowledges the interrupt by writing a certain value to one of the interrupt controller's
  // input and output ports. This acknowledgment tells the controller that it is free to issue another interrupt. By having the central processing unit delay
  // acknowledgment until it is ready to handle the next interrupt, race conditions involving multiple ( almost simultaneous ) interrupts can be avoided. As an
  // aside, some older computers do not have a centralized interrupt controller, so each device controller requests its own interrupts.
  //
  // The hardware always saves certain information before starting the service procedure. Which information is saved and where it is saved varies greatly from
  // central processing unit to another. As a bare minimum, the program counter must be saved, so the interrupted process can be restarted. At the other extreme,
  // all the visible registers and a large number of internal registers may be saved as well.
  //
  // One issue is where to save this information. One option is to put it in internal registers that the operating system can read out as needed. A problem with
  // approach is that then the interrupt controller cannot be acknowledged until all potentially relevant information has been read out, lest a second interrupt
  // overwrite the internal registers saving the state. This strategy leads to long dead times when interrupts are disabled and possibly to lost interrupts and
  // lost data.
  //
  // Consequently, most central processing unit save the information on the stack. However, this approach, too, has problems. To start with, whose stack? if the
  // current stack is used, it may well be a user process stack. The stack pointer may not even be legal, which would cause a fatal error when the hardware
  // tries to write some words at the address pointed to. Also, it might point to the end of a page. After several memory writes, the page boundary might be
  // exceeded and a page fault generated. Having a page fault occur during the hardware interrupt processing creates a bigger problem - where to save the
  // state to handle the page fault?
  //
  // If the kernel stack is used, there is a much better chance of the stack pointer being legal and pointing to a pinned page. However, switching into kernel
  // mode may required changing memory management unit ( MMU ) contexts and will probably invalidate most or all of the cache and translation lookaside buffers
  // ( TLB ). Reloading all of these, statically or dynamically, will increase the time to process an interrupt and thus waste central processing unit time


// *****************************************************************************   Precise and imprecise interrupts   ******************************************************************************* \\


  // Another problem is caused by the fact that most modern central processing units are heavily pipelined and often superscalar ( internally parallel ). In older
  // systems, after each instruction was finished executing, the microprogram or hardware checked to see if there was an interrupt pending. If so, the program
  // counter and program status word ( PSW ) were pushed onto the stack and the interrupt sequence begun. After the interrupt handler ran, the reverse process took
  // place, with the old program status word and program counter popped from the stack and the previous process continued.
  //
  // This model makes the implicit assumption that if an interrupt occurs just after some instruction, all the instructions up to and including that instruction
  // have been executed completely, and no instructions after it have executed at all. On older machines, this assumption was always valid. On modern ones it
  // may not be.
  //
  // For starters, what happens if an interrupt occurs while the pipeline is full ( the usual case )? many instructions are in various stages of execution. When
  // the interrupt occurs, the value of the program counter may not reflect the correct boundary between executed instructions and non executed instructions.
  // In fact, many instructions may have been partially executed, with different instructions being more or less complete. In this situation, the program counter
  // most likely reflects the address of the next instruction to be fetched and pushed into the pipeline rather then the address of the instruction that just
  // was processed by the execution unit.
  //
  // On a superscalar things are even worse. Instructions may be decomposed into micro operations and the micro operations may execute out of order, depending
  // on the availability of internal resources such as functional units and registers. At the time of an interrupt, some instructions started long ago may not
  // have started and others started more recently may be almost done. At the point when an interrupt is signaled, there may be many instructions in various
  // states of completeness, with less relation between them and the program counter.
  //
  // An interrupt that leaves the machine in a well defined state is called a 'precise interrupt'. Such an interrupt has four properties :
  //
  //  1. The program counter is saved in a known place
  //  2. All instructions before the one pointed to by the program counter have completed
  //  3. No instruction beyond the one pointed to by the program counter has finished
  //  4. The execution state of the instruction pointed to by the program counter is known
  //
  // Note that there is no prohibition on instructions beyond the one pointed to by the program counter from starting. It is just that any changes they make
  // to registers or memory must be undone before the interrupt happens. It is permitted that the instruction pointed to has been executed. It is also
  // permitted that it has not been executed. However, it must be clear which case applies. Often, if the interrupt is an input and output, the instruction
  // will not yet have started. However, if the interrupt is really a trap or page fault, then the program counter generally points to the instruction that
  // caused the fault so it can be restarted later.
  //
  // An interrupt that does not meed these requirements is called an imprecise interrupt ad makes life most unpleasant for the operating system writer, who
  // now has to figure out what has happened and what still has to happen. Machines with imprecise interrupts usually vomit a large amount of internal state
  // onto to the stack to give the operating system the possibility of figuring out what was going on. The code necessary to restart the machine is typically
  // exceedingly complicated. Also, saving a large amount of information to memory on every interrupt makes interrupts slow and recovery even worse. This
  // leads to the ironic situation of having very fast superscalar central processing unit sometimes being unsuitable for real time work due to slow interrupts.
  //
  // Some computers are designed so that some kinds of interrupts and traps are precise and others are not. For example, have input and output interrupts be
  // precise but traps due to fatal programming errors be imprecise is not so bad since no attempt need to be made to restart a running process after it has
  // divided by zero. Some machines have a bit that can be set to force all interrupts to be precise. The downside of setting this bit is that it forces the
  // central processing unit to carefully log everything it is doing and maintain shadow copies of registers so it can generate a precise interrupt at any
  // instant. All this overhead has a major impact on performance.
  //
  // Some superscalar machines, such as the x86 family, have precise interrupts to allow old software to work correctly. The price paid for backward compatibility
  // with precise interrupts is extremely complex interrupt logic within the central processing unit to make sure that when the interrupt controller signals
  // that it wants to cause an interrupt, all instructions up to some point are allowed to finish and none beyond that point are allowed to have any noticeable
  // effect on the machine state. Here the price is paid not in time, but in chip area and in complexity of the design. If precise interrupts were not required
  // for backward compatibility purposes, this chip area would be available for larger on chip caches, making the central processing unit faster. On the other
  // hand, imprecise interrupts make the operating system far more complicated and slower, so it is hard to tell which approach is really better



// ************************************************************************************************************************************************************************************************** \\
// *                                                                           PRINCIPLES OF INPUT AND OUTPUT SOFTWARE                                                                              * \\
// ************************************************************************************************************************************************************************************************** \\



// ***************************************************************************   Goals of the input and output software   *************************************************************************** \\


  // A key concept in the design of input and output software is known is device independence. This means that programs that can access any input and output
  // device can be written without having to specify the device in advance. It is up to the operating system to take care of the problems caused by the fact
  // that these devices really are different and require very different command sequences to read and write.
  //
  // Closely related to device independence is the goal of uniform naming. The name of a file or a device should simply be a string or an integer and not
  // depend on the device in any way. In UNIX, all disks can be integrated in the file system hierarchy in arbitrary ways so the user need not be aware of
  // which name corresponds to which device. In this way, all files and devices are addressed the same way - by a path name.
  //
  // Another important issue for input and output software is error handling. In general, errors should be handled as close to the hardware as possible. If
  // the controller discovers a read error, it should try to correct the error itself if it can. If it cannot, then the device driver should handle it,
  // perhaps by just trying to read the block again. Only if the lower levels are not able to deal with the problem should the upper layers be told about it.
  // In many cases, error recovery can be done transparently at a low level without the upper levels even knowing about the error.
  //
  // Still another important issue is that of synchronous ( blocking ) vs asynchronous ( interrupt driven ) transfers. Most physical input and output is
  // asynchronous, the central processing unit starts the transfer and goes off to do something else until the interrupt arrives. User programs are much
  // easier to write if the input and output operations are blocking - after a read system call the program is automatically suspended until the data
  // are available in the buffer. It is up to the operating system to make operations that are actually interrupt driven look blocking to the user programs.
  // However, some very high performance applications need to control all the details of the input and output, so some operating systems make asynchronous
  // input and output available to them.
  //
  // Another issue for the input and output software is buffering. Often data that come off a device cannot be stored directly in their final destination.
  // For example, when a packet comes in off the network, the operating system does not know where to put it until it has stored the packet somewhere and
  // examined it. Also, some devices have severe real time constraints, so the data must be put into an output buffer in advance to decouple the rate at
  // which the buffer is filled from the rate at which it is emptied, in order to avoid buffer underruns. Buffering involves considerable copying and
  // often has a major impact on input and output performance.
  //
  // The final concept for this discussion is sharable vs dedicated devices. Some input and output devices, such as disks, can be used by many users at
  // the same time. No problems are caused by multiple users having open files on the same disk at the same time. Other devices, such as printers, have
  // to be dedicated to a single user until that user is finished, then another user can use the printer. Introducing dedicated ( unshared ) devices also
  // introduces a variety of problems, such as deadlocks. Again, the operating system must be able to handle both shared and dedicated devices in a way
  // that avoids problems.


// *********************************************************************************   Programmed input and output   ******************************************************************************** \\


  // There are three fundamentally different ways that input and output can be performed. This is the first one, the simplest form is to have the central
  // processing unit do all the work. This method is called programmed input and output.
  //
  // The essential aspect of programmed input and output, is that after outputting a character, the central processing unit continuously polls the device
  // to see if it is ready to accept another one. This behavior is often called polling or busy waiting. Programmed input and output is simple but has the
  // disadvantage of tying up the central processing unit full time until all the input and output operations are done. If the time input and output operation
  // is really short then busy waiting is find, it is also find in embedded system, where the central processing unit has nothing else to do. However, in more
  // complex systems, where the central processing unit has other work to do, busy waiting is inefficient. A better input and output method is needed


// ******************************************************************************   Interrupt driven input and output   ***************************************************************************** \\


  // In a case of printing on a printer that does not buffer characters but prints each one as it arrives. If the printer can print, say 100 characters per
  // second, each character takes 10 milli seconds to print. This means that after every character is written to the printer's data register, the central
  // processing unit will sit an idle loop for 10 milli seconds waiting to be allowed to output the next character. This is more than enough time to do a
  // context switch and run some other process for the 10 milli seconds that would otherwise be wasted.
  //
  // The way to allow the central processing unit to do something else while waiting for the printer to become ready is to use interrupts. When the system
  // call to print the string is made, the buffer is copied to kernel space, and the first character is copied to the printer as soon as it is willing to
  // accept a character. At that point the central processing unit calls the scheduler and some other process is run. The process that asked for the string
  // to be printed us blocked until the entire string has printed. When the printer has printed the character and is prepared to accept the next one, it
  // generates an interrupt. This interrupt stops the current process and saves its state. Then the printer interrupt service procedure is run. If there are
  // no more characters to print, the interrupt handler takes some action to unblock the user. Otherwise, it output the next character, acknowledges the
  // interrupt, and returns to the process that was running just before the interrupt, which continues from where it left off.


// *********************************************************************   Input and output using direct memory access ( DMA )   ******************************************************************** \\


  // An
