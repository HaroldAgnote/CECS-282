#ifndef __MEMORY_MANAGER_H__
#define __MEMORY_MANAGER_H__

namespace MemoryManager
{
	void memView( int start, int end );

	//---
	//--- CORE Functions, these will need to be completed by the applicant
	//---

	// Initialize any data needed to manage the memory pool
	void initializeMemoryManager( void );

	// Return a pointer inside the memory pool
	// If no chunk can accomodate aSize call onOutOfMemory
	void * allocate( int aSize );

	// Free up a chunk previously allocated
	void deallocate( void * aPointer );

	//---
	//--- Support Routines
	//---

	// Will scan the memory pool and return the total free space remaining
	int freeMemory( void );

	// Will scan the memory pool and return the total used memory - memory that has been deallocated
	int usedMemory( void );

	// Will scan the memory pool and return the total in use memory = memory currently used
	int inUseMemory( void );

	// Call if no space is left for the allocation request
	void onOutofMemory( void );

};

#endif // __MEMORY_MANAGER_H__