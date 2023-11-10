#include <iostream>

class MemoryBlock
{
public:
	// Simple constructor that initialises the resource.
	MemoryBlock(int t_length = 1)
		: m_length(t_length)
		, m_buffer(new int[t_length])
	{
		for (int i = 0; i < m_length; i++)
		{
			m_buffer[i] = i;
		}
	}
	// Copy constructer
	MemoryBlock(MemoryBlock const& t_copy)
	{
		// Step 1: Allocate a new heap resource for the lhs object
		m_buffer = new int[t_copy.m_length];
		
		// Step 3: Copy the array values from rhs to lhs
		// Step 3: Using memcpy
		memcpy(m_buffer, t_copy.m_buffer, sizeof(int) * t_copy.m_length);
		// Assign m_length
		m_length = t_copy.m_length;
	
	}

	// Destructor to delete the memory resource.
	~MemoryBlock()
	{
		delete[] m_buffer;
	}

	// Implementation of the assignment operator
	// Necessary as this class has a pointer as a member variable
	// Attempt #1
	// t_rhs (rhs means Right Hand Side)
	void operator=(MemoryBlock const& t_rhs)
	{ 
		// We want to make a deep copy of the t_rhs object
		// Both objects should have their own heap resource (array)
		
		// Check for self-assignment
		// i.e. make sure both lhs and rhs objects are different 
		if (this != &t_rhs)
		{

			// Check both array lengths are not the same
			if (m_length != t_rhs.m_length)
			{
				// Step 1: Delete the existing array for this object
				delete[] m_buffer;
				// Step 2: Allocate a new heap resource for the lhs object
				m_buffer = new int[t_rhs.m_length];
			}
			// Step 3: Copy the array values from rhs to lhs
			for (int i = 0; i < t_rhs.m_length; i++)
			{
				m_buffer[i] = t_rhs.m_buffer[i];
			}

			// Step 3: Using memcpy
			memcpy(m_buffer, t_rhs.m_buffer, sizeof(int) * t_rhs.m_length);
			// Assign m_length
			m_length = t_rhs.m_length;
		}
	}

private:
	int* m_buffer; // Raw pointer to memory resource
	int m_length; // The length of the memory resource
};

void assignBlock(MemoryBlock& t_block)
{
	MemoryBlock block2(10);
	block2 = t_block;
}

void copy(MemoryBlock t_block)
{

}

int main()
{
	MemoryBlock block1(10);
	MemoryBlock block2 = block1;
	copy(block2);
	
	//assignBlock(block1);
	//MemoryBlock block2(2);

	//block2 = block1;
}