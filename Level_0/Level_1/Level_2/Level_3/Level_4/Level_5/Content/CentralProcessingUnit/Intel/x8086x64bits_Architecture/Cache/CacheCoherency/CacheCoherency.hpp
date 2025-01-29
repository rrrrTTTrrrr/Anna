//****************************************************************************************************************************************************************************\\
//****************************************************************************************************************************************************************************\\
//**                                                                                                                                                                        **\\
//**                                                                                    CACHE                                                                               **\\
//**                                                                                                                                                                        **\\
//****************************************************************************************************************************************************************************\\
//****************************************************************************************************************************************************************************\\




//****************************************************************************************************************************************************************************\\
//**                                                                              Cache Coherence                                                                           **\\
//****************************************************************************************************************************************************************************\\




//*******************************************************************************   Overview   *******************************************************************************\\



// Cache coherence is the uniformity of shared resource data that ends up stored in multiple local caches. When clients in a system maintain caches of a
// common memory resource, problems may arise with incoherent data, which is particularly the case with CPU's in a multiprocessing system.
//
// In the illustration on the right, consider both the clients have a cached copy of a particular memory block from a previous read. Suppose the client
// on the bottom updates/changes that memory block, the client on the top could be left with an invalid cache of memory without any notification of the change.
// Cache coherence is intended to manage such conflicts by maintaining a coherent view of the data values in multiple caches!
//
// Multiprocessing system :
//
//                                                  ++++++++++                   +++++++++
//                                                  | CLIENT |      ---->        | CACHE |          ---------------------
//                                                  ++++++++++                   +++++++++                              |
//                                                                                   |                                  |
//                                                                                   |                              ++++++++++
//                                                                               coherency                          | Memory |
//                                                                                   |                              ++++++++++
//                                                                                   |                                  |
//                                                  ++++++++++                   +++++++++                              |
//                                                  | CLIENT |      ---->        | CACHE |          ---------------------
//                                                  ++++++++++                   +++++++++
//
//
// In a shared memory multiprocessor system with a separate cache memory for each processor, it is possible ti have many copies of shared data. One copy in the
// main memory and one in the local cache of each processor that requested it. When one of the copies of data is changes, the other copies must reflect that change.
// Cache coherent is the discipline which ensures that the changes in the values of shared data are propagated throughout the system in a timely fashion. The
// following are the requirements for cache coherence :
//
//    1. Write Propagation - Changes to data in any cache must be propagated to other copies ( of that cache line ) in the peer caches.
//    2. Transaction Serialization - Read/Writes to a single memory location must be seen by all processors in the same order
//
// Coherence defines the behavior of reads and writes to a single address location. In a multiprocessor system, consider that more than one processor has cached
// a copy of the memory location X. The following conditions are necessary to achieve cache coherence :
//
//    1. In a read made by a processor P to a location X that follows a write by the same processor P to X, with no writes to X by another processor occurring between
//       the write and the read instructions made by P, X must always return the value written by P
//    2. In a read made by a processor P1 to location X that follows a write by another processor P2 to X, with no other writes to X made by any processor occurring
//       between the two accesses and with the read and write being sufficiently separated, X must always return the value written by P2. This condition defines the
//       concept of coherent view of memory. Propagating the writes to the shared memory location ensures that all the caches have a coherent view of the memory. If
//       processor P1 reads the old value of X, even after the write by P2, the memory is incoherent!
//
// The above conditions satisfy the write propagation criteria required for cache coherence. However, they are not sufficient as they do not satisfy the transaction
// serialization condition. In order to satisfy transaction serialization, and hence achieve cache coherence, the following condition is added :
//
//    3. Write to the same location must be sequenced. In other words, if location X received two different values A and B, in this order, from any two processors,
//       the processors can never read location X as B and then read it as A. The location X must be seen with values A and B in that order


//******************************************************************************   Mechanisms   ******************************************************************************\\


// The two most common mechanisms of ensuring coherency are snooping and directory based, each having benefits and drawbacks. Snooping based protocols 
// tend to be faster, if enough bandwidth is available, since all transactions re a request/response seen by all processors. The drawback is that 
// snooping isn't scalable. Every request must be broadcast to all nodes in a system, meaning that as the system gets larger, the size of the physical 
// bus and the bandwidth it provides must grow. Directories, on the other hand, tend to have longer latencies but use much less bandwidth since messages 
// are point to point and not broadcast. For this reason, many of the larger systems ( larger then 64 processors ) use this type of cache coherence.
//
// 1. Bus snooping :
//
// A scheme that a coherency controller ( snooper ) in a cache monitors or snoops the bus transactions, and its goal is to maintain a cache coherency in 
// distributed shared memory systems. A cache that has a coherency controller inside is called as snoopy cache. When specific data is shared by several 
// caches and processor modifies the value of the shared data, the change must be propagated to all other caches which have the same copy of the data. 
// Otherwise, it may violate a cache coherency. The notification of data change can be done by bus snooping. All the snoopers monitor every transaction 
// on a bus. If a transaction modifying a shared cache block appears on a bus, all the snoopers check whether their caches have the same copy of the 
// shared block. If a cache has the copy of the shared block, the corresponding snooper performs an action to ensure cache coherency. The action can be 
// flush or an invalidation of the cache block. It also involves a change of cache block status depending on the cache coherence protocol!
//
// There are two kinds of snooping protocols depending on the way to manage a local copy of a write operation :
//
//   1. Write-Invalidate - when a processor writes on a shared cache block, all the shared copies in the other caches are invalidated through bus 
// 		snooping. This method ensures that only one copy of a datum can be exclusively read and written by a processor. All the other copies in other 
//		caches are invalidated. This is the most commonly used snooping protocol. MSI, MOSI, MOESI and MESIF protocols belong to this category.
//
//   2. Write-Update - when a processor writes on a shared cache block, all the shared copies of the other caches are updated through bus snooping. 
//		This method broadcasts a write data to all caches throughout a bus. It incurs larger bus traffic than write invalidate protocol. That is why 
//		this method is uncommon. Dragon and firefly protocols belong to this category.
//
// Possible implementation :
//
// The cache would have three extra bits :
//
//    1. Valid bit
//    2. Dirty bit - signifies that data in the cache is not the same as in memory
//    3. Shared bit
//
// Each cache line is in one of the following states - "dirty", "valid", "invalid" or "shared". A cache line contains a value, and it can be read or 
// written. Writing on a cache line changes the value. Each value is either in main memory, or in one or more local caches. When a block is first 
// loaded into the cache, it is marked as "valid". On a read miss to the local cache, the read request is broadcast on the bus. All cache controllers
// monitor the bus. If one has cached that address and it is in the state "dirty", it changes the state to "valid" and sends the copy to requesting node.
// The "valid" state means that the cache line is current. On a local write miss, bus snooping ensures that any copies in other caches are set to "invalid".
// "invalid" means that a copy used to exist in the cache, but it is no longer current.
//
// The caching logic monitors the bus detects if any cached memory is requested. If the cache is dirty and shared and the bus requests that memory, the 
// snooping elements will supply the value from the cache then notify every unit that needs that memory, that the memory was updated. When the other
// units are notified of the updated cache, they will turn off the valid bit for their cache of that variable. Thus only cache will be marked as 
// exclusive. When invalidating an address marked as dirty ( one cache would have a dirty address and the other cache is writing ) then the cache will
// ignore that request. The cache that the value is written in will be marked as dirty, valid and exclusive and that cache will now take responsibility
// for the address!
//
// 2. Directory based :
//
// A type of cache coherence mechanism, where directories are used to manage caches in place of snoopy methods due to their scalablility. Snoopy bus based
// methods scale poorly due to the use of broadcasting. These methods can be used to target both performance and scalability of directory systems. 
//
// In the full bit vector format, for each possible cache line in memory, a bit is used to track whether every individual processor has that line stored
// in its cache. The full bit vector format is the simplest structure to implement, but the least scalable.
//
// In a directory based system, the data being shared is placed in a common directory that maintains the coherence between caches. The directory acts as
// a filter through which the processor must ask permission to load an entry from the primary memory to its caches. When an entry is changed, the directory
// either updates or invalidates the othe caches with that entry


//******************************************************************************   MSI Protocol   ****************************************************************************\\


// The MSI protocol - a basic cache coherence protocol - operates in multiprocessor systems. As with other cache coherency protocols, the letters of the
// protocol name identify the possible states in which a cache line can be. In MSI, each block contained inside a cache can have one of three possible states :
//
//    1. Modified - the block has been modified in the cache. The data in the cache is then inconsistent with the backing store ( usually means RAM ). A cache
//                  with a block in the modified state has the responsibility to write the block to the backing store when it is evicted
//    2. Shared - this block is unmodified and exists in read only state in at least one cache. The cache can evict the data without writing it to the backing store
//    3. Invalid - this block is either not present in the current cache or has been invalidated by a bus request, and must be fetched from memory or another cache
//                 if the block is to be stored in this cache
//
// These coherency states are maintained through communication between the caches and the backing store. The caches have different responsibilities when blocks are
// read or written, or when they learn of other caches issuing reads or writes for a block.
//
// When a read request arrives at a cache for a block in the modified or shared states, the cache supplies the data. If the block is not in the cache, in the invalid
// state, it must verify that the line is not in the modified state in any other cache. Different caching architectures handle this differently. For example, bus
// architectures often perform snooping, or cache directories. If another cache has the block in the modified state, it must write back the data to the backing store
// and go to the shared or invalid state. Once any modified line is written back, the cache obtains the block from either the backing store, or another cache with the
// data in the shared state. The cache can then supply the data to the requester. After supplying the data, the cache block is in the shared state.
//
// When a write request arrives at a cache for a block in the modified state, the cache modifies the data locally. If the block is in the shared state, the cache must
// notify any other caches that might contain the block in the shared state that they must evict the block. The notification is done via snooping or cache directories.
// Then the data may be locally modified. If the block is in the invalid state, the cache must notify any other caches that might contain the block in the shared or
// modified states that they must evict the block. If the block is in in another cache in the modified state, that cache must either write the data to the backing store
// or supply it to the requesting cache. If at this point the cache does not yet have the block locally, the block is read from the backing store before being modifies
// in the cache . After the data is modified, the cache block is in the modified state!
//
// For any given pair of caches, the permitted states of a given cache line are as follows :
//
//                Modified  Shared  Invalid
//    Modified       x        x        o
//    Shared         x        o        o
//    Invalid        o        o        o
//
// Processor requests to the cache include :
//
//    1. ProcessorRead - processor request to read a cache block
//    2. ProcessorWrite - processor request to write a cache block
//
// In addition, there are bus side requests. These include :
//
//    1. BusRead - when a read miss occurs in a processor's cache, it sends a bus read request on the bus and expects to receive the cache block in return
//    2. BusReadX - when a write miss occurs in a processor's cache, it sends a bus read X request on the bus which returns the cache block and invalidates the block
//                  in the caches of other processors
//    3. BusUpgrade - when there's a write hit in a processor's cache, it sends a bus upgrade request on the bus to invalidate the block in the caches of other processors
//    4. Flush - a request that indicates that a whole cache block is being written back to the memory
//
// State transitions :
//
//  Invalid :
//
//    1. On a ProcessorRead, a BusRead is issued and state changes to shared
//    2. On a ProcessorWrite, a BusReadX is issued and state changes to modified
//    3. On a BusRead, a BusReadX and BusUpgrade an invalid block remains invalid
//
//  Shared :
//
//    1. On a ProcessorRead, the block remains in the shared state
//    2. On a ProcessorWrite, a BusUpgrade is issued and state changes to modified
//    3. On a BusRead, the block remains in the shared state
//    4. On a BusReadX or BusUpgrade, the block transitions to invalid
//
//  Modified :
//
//    1. On a ProcessorRead or ProcessorWrite, the block remains in the modified state
//    2. On a BusRead, the cache block is flushed onto the bus and state changes to shared
//    3. On a BusReadX, the cache block is flushed onto the bus and state changes to invalid


//******************************************************************************   MESI Protocol   *****************************************************************************


// The MESI protocol is an invalidate based cache coherence protocol, and is one of the most common protocols which support write back caches. Write
// back caches can save a lot on bandwidth that is generally wasted on a write through cache. There is always a dirty state present in write back caches
// which indicates that the data in the cache is different from that in main memory. The protocol requires cache to cache transfer on a miss if the block
// resides in another cache. This protocol reduces the number of main memory transactions compared to the MSI protocol. This makes a significant improvement
// in the performance.
//
// The letters in the acronym MESI represent four states that a cache line can be marked with :
//
//    1. Modified - the cache line is present only in the current cache, and is dirty ( dirty means the value in the cache is more updated then the value in
//                  main memory ). The cache is required to write the data back to main memory at some time in the future, before permitting any other read
//                  of the no longer valid main memory sate. The write back changes the line to the shared state
//    2. Exclusive - the cache line is present in the current cache, but is clean - it matches main memory. It may be changed to the shared state at any time,
//                   in response to a read request. Alternatively, it may be changed to the modified state when writing to it
//    3. Shared - indicates that this cache line may be stored in other caches of the machine and is clean - it matches the main memory. The line may be
//                invalidated at any time
//    4. Invalid - indicates that this cache line should not be used in its current form
//
// For any given pair of caches, the permitted states of a given cache line are as follows :
//
//                Modified  Exclusive  Shared  Invalid
//    Modified       x         x         x        o
//    Exclusive      x         x         x        o
//    Shared         x         x         o        o
//    Invalid        o         o         o        o
//
// Processor requests to the cache include :
//
//    1. ProcessorRead - processor request to read a cache block
//    2. ProcessorWrite - processor request to write a cache block
//
// In addition, there are bus side requests. These include :
//
//    1. BusRead - snooped request that indicates there is a read request to a cache block made by another processor
//    2. BusReadX - snooped request that indicates there is a write request to a cache block made by another processor which doesn't already have the block
//                  in the caches of other processors
//    3. BusUpgrade - snooped request that indicates that there is a write request to a cache block made by another processor but that processor already has
//                    that cache block resident in its cache
//    4. Flush - snooped request that indicates that a whole cache block is being written back to the memory by another processor
//    5. FlushOperation - snooped request that indicates that an entire cache block is posted on the bus in order to supply it to another processor ( cache
//                        to cache transfers )
