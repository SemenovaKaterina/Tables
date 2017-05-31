#include "THashTable.h"

unsigned long THashTable::HashFunc(TKey key)
{
	unsigned long hashval = 0;
	for (unsigned int i = 0; i < key.length(); i++)
		hashval = (hashval << 3) + key[i];
	return hashval;
}
