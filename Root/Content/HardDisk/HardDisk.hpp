


                                                                          // ********************************************* //
                                                                          // ********************************************* //
                                                                          // **                                         ** //
                                                                          // **                HARD DISK                ** //
                                                                          // **                                         ** //
                                                                          // ********************************************* //
                                                                          // ********************************************* //








********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************
**                                                                                                                                                                                                    **
**                                                                                             OVERVIEW                                                                                               **
**                                                                                                                                                                                                    **
********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************




Hard disk drives are accessed over one of a number of bus types, including parallel ATA ( PATA, also called IDE or EIDE ), serial ATA ( SATA ), SCSI, Serial Attached SCSI ( SAS ),
and Fibre channel. Bridge circuitry is sometimes used to connect hard disk drives to buses with which they cannot communicate natively, such as IEEE 1394, USB, SCSI and
Thunderbolt.

Disk interfaces families :

Disk drive interfaces have evolved from simple interfaces requiring complex controllers to attach to a computer into high level interfaces that present a consistent interface to a
computer system regardless of the internal technology of the hard disk drive. The following table lists some common hard disk interfaces in chronological order :

  1. Storage Module Device ( SMD ) - bit serial data interface introduced by CDC, standard interface for many mini computers in the 1970's and 1980's
  2. Shugart Associates System Interface ( SASI ) - Word serial interface introduced by Shugart associates circa 1978, evolved by ANSI into SCSI ( SASI is a compatible subset of
     the first version of SCSI )
  3. Small computer system interface ( ST-506, ST-412, ST-412RLL ) - word serial interface sponsored by ANSI and introduced in mid 1980's. Standard interfaces for most small HDDs
     in the the 1980s and early 1990s
  4. Small Computer System Interface ( SCSI ) - word serial interface sponsored by ANSI and introduced in mid 1980s. Standard interfaces for most enterprise HDDs in this century,
     superseded by SCSI
  5. Enhanced Small Disk Interface ( ESDI ) - Bit serial data interface sponsored by ANSI and first introduced by Maxtor in late 1980s. A higher data rate follow on the to the
     ST-506 family into the mid 1990s, superseded by SCSI
  6. Parallel AT attachment ( PATA ) - Word serial interface introduced in late 1980s by conner peripherals and subsequently sponsored by ANSI, successor to ST-412/506/ESDI.
     Standard HDD interface on other than enterprise HDDs into this century, superseded by SATA
  7. Serial ATA ( SATA ) - Bit serial interface successor to PATA sponsored by ANSI and introduced in 2003, most common interface for all but enterprise HDDs
  8. Serial Attached SCSI ( SAS ) - Bit serial interface successor to SCSI sponsored by ANSI and introduced in 2004. Most common interface for enterprise HDDs



********************************************************************************************************************************************************************************************************
**                                                                                         Early Interfaces                                                                                           **
********************************************************************************************************************************************************************************************************



The earliest hard disk drive interfaces were bit serial data interfaces that connected an hard disk drive to a controller with two cables, one for control and one for data. An
additional cable was used for power, initially frequently AC but later usually connected directly to a DC power supply unit. The controller provided significant functions such as
serial/parallel conversion, data seperation and track formatting. It required matching to the drive ( after formatting ) in order to assure reliability. Each control cable could
serve two or more drives, while a dedicated and smaller data cable served each drive.

Many early IBM drive had such an interface. Examples of such early interfaces include :

  1. The SMD interface was popular on minicomputers in the 1970s
  2. ST-506 used Modified Frequency Modulation ( MFM ) for the data encoding method
  3. ST412 an ST-506 variant was available in wither MFM or Run Length Limited ( RLL ) encoding variants
  4. Enhanced small disk interface ( ESDI ) was an industry standard interface similar to ST412 supporting higher data rates between the processor and the disk drive

In bit serial data interfaces the data frequency, data encoding scheme as written to the disk surface and error detection all influenced the design of the of the supporting
controller. Encoding schemes used included frequency modulation ( FM ), modified frequency modulation ( MFM ) and RLL encoding at frequencies for example ranging from 0.156
MHz ( FM on 2311 ) to 7.5 MHz ( RLL on ST412 ). Thus each time the internal technology advanced there was a necessary delay as controllers were designed or redesigned to
accommodate the advancement. This along with the code of controller development led to the introduction of Word serial interfaces.

Enhanced small disk interface ( ESDI ) was an attempt to minimize controller design time by supporting multiple data rates with a standard data encoding scheme. This was
usually negotiated automatically by the disk drive and controller, most of the time, however 15 or 20 megabit ESDI disk drives were not downward compatible, a 15 or 20 megabit
disk drive would not run on a 10 megabit controller. ESDI disk drives typically also had jumpers to set the number of sectors per track and sector size.



********************************************************************************************************************************************************************************************************
**                                                                                      Word Serial Interfaces                                                                                        **
********************************************************************************************************************************************************************************************************



Historical word serial interfaces connect a hard disk drive to a bus adapter with one cable for combined data/control. As for all early interfaces above, each drive also has an
additional power cable, usually direct to the power supply unit. The earliest versions of these interfaces typically has an 8 bit parallel data transfer to/from the drive, but
16 bit versions became much more common, and there are 32 bit versions. The word nature of data transfer makes the design of a host bus adapter significantly simpler then that
of the precursor hard disk drive controller.

  1. Controller Interface ( CTL-I ) - was an 8 bit word serial interface introduced by IBM for its mainframe hard disk drives beginning with the 3333 in 1972. The 3333 was the
     first unit in a string of up to eight 3330 type hard disk drives, it contained a CTL-I controller and two 3330 type disk drives. Subsequently, the first drive in a string
     of drives was designated by IBM as an A unit. The drives within an A unit and all other drives in a string had interfaces similar to the early interfaces, above. A units
     connected to IBM directors or integrated attachments.
  2. Small Computer System Interface ( SCSI ) - originally named SASI for Shugart associates system interface, is an early industry standard interface explicitly deployed to
     minimize system integration efforts. SCSI disks became standard on servers and workstations. Commodore Amiga and Apple Macintosh deployed SCSI drive through the mid 1990s,
     by which time most models had been transitioned to ATA ( and later SATA ) family disks. Only in 2005 did the capacity of SCSI disks fall behind ATA disk technology, though
     the highest performance disks are still available in SCSI, SAS and Fibre channel only. The range limitations of the data cable allows for external SCSI devices. Originally
     SCSI data cables used single ended ( common mode ) data transmission, but server class SCSI could use differential transmission, either low voltage differential ( LVD )
     or high voltage differential ( HVD ).
  3. Parallel ATA - originally IDE and then standardized under the name AT Attachment, with the alias 'PATA' retroactively added upon introduction of the new variant serial ATA.
     The original name reflected the integration of the controller with the hard drive itself. Moving the hard disk drive controller from the interface card to the disk drive
     helped to standardize the host/controller interface, reduce the programming complexity in the host device driver, and reduced system cost and complexity. The 40 pin IDE/ATA
     connection transfers 16 bits of data at a time on the data cable. The data cable was originally 40 conductor, but later higher speed requirements for data transfer to and
     from the hard drive led to an "ultra DMA" mode, known as UDMA. Progressively swifter versions of this standard ultimately added the requirement for an 80 conductor variant
     of the same cable, where half of the conductors provides grounding necessary for enhanced high speed signal quality by reducing cross talk. The interface for 80 conductor
     only has 39 pins, the missing pin acting as a key to prevent incorrect insertion of the connector to an incompatible socket, a common cause of disk and controller damage.



********************************************************************************************************************************************************************************************************
**                                                                                      Bit Serial Interfaces                                                                                         **
********************************************************************************************************************************************************************************************************



Modern bit serial interfaces connect a hard disk drive to a host bus interface adapter ( today in a PC typically integrated into the "south bridge" ) with one data/control cable.
Each drive also has an additional power cable, usually direct to the power supply unit.

  1. DECs Standard Disk Interconnect ( SDI ) - was an early example of a modern bit serial interface
  2. Fibre Channel ( FC ) - is a successor to parallel SCSI interface on enterprise market. It is a serial protocol. In disk drives usually the Fibre Channel Arbitrated Loop ( FC-AL )
     connection topology is used. Fibre channel has much broader usage them mere disk interfaces, and it is the cornerstone of storage area networks ( SANs ). Recently other
     protocols for this field, like iSCSI and ATA over Ethernet have been developed as well. Confusingly, drives usually use copper twisted pair cables for Fibre channel, not
     fibre optics. The latter are traditionally reserved for larger devices, such as servers or disk array controllers.
  3. Serial ATA ( SATA ) - the serial ATA cable has one data pair for differential transmission of data to the device, and one pair for differential receiving from the device, just
     like EIA-422. That requires that data be transmitted serially. A similar differential signaling system is used in RS485, LocalTalk, USB, Firewire and differential SCSI
  4. Serial Attached SCSI ( SAS ) - is a new generation serial communication protocol for devices designed to allow for much higher speed data transfers and is compatible with
     SATA. SAS uses a mechanically identical data and power connector to standard 3.5 inch SATA1/SATA2 hard disk drives, and many server oriented SAS RAID controllers are also
     capable of addressing SATA hard drives. SAS used serial communication instead of the parallel method found in traditional SCSI devices but still uses SCSI commands
