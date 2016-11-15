#include <iostream>

// We'll store the relation in an array;
// The first element of each pair in the relation will be placed at every even index
// The second element of each pair will be stored at every odd index
// In other words, if i-th pair in the relation is (x, y) then array[2 * i] == x && array[2 * i + 1] == y
// For example the relation R = { (1, 2), (3, 4) } will be stored in the array { 1, 2, 3, 4 }
const int MaxRelationSize = 2 * 100; // We only accept relations with up to 100 elements
int relationElements[MaxRelationSize];

bool IsRelationReflexive(int n, int pairCount)
{
	// Check if each pair of (i, i) is present in the relation
	for (int i = 0; i < n; ++i)
	{
		bool isCurrentPairReflexive = false;
		for (int j = 0; j < 2 * pairCount; j += 2)
		{
			if (relationElements[j] == i && relationElements[j + 1] == i)
			{
				// Hooray, we found (i, i)
				isCurrentPairReflexive = true;
				break;
			}
		}
		if (!isCurrentPairReflexive)
		{
			// At least one pair is not in relation -> the relation is not reflexive
			return false;
		}
	}
	// If we've reached this point, we are sure that all pairs are present
	return true;
}

bool IsRelationSymmetric(int pairCount)
{
	// Check whether for every (x, y) it's also true that (y, x) is in the relation
	for (int i = 0; i < 2 * pairCount; i += 2)
	{
		int x = relationElements[i];
		int y = relationElements[i + 1];
		bool isCurrentPairSymmetrical = false;
		for (int j = 0; j < 2 * pairCount; j += 2)
		{
			if (relationElements[j] == y && relationElements[j + 1] == x)
			{
				// Hooray, we've found (y, x)
				isCurrentPairSymmetrical = true;
				break;
			}
		}
		if (!isCurrentPairSymmetrical)
		{
			// At least one pair is not symmetrical -> the relation isn't symmetrical
			return false;
		}
	}
	return true;
}

bool IsRelationTransitive(int pairCount)
{
	// Check whether for every (x, y) & (y, z) it's also true that (x, z) is in the relation
	for (int i = 0; i < 2 * pairCount; i += 2)
	{
		int x = relationElements[i];
		int y = relationElements[i + 1];
		for (int j = 0; j < 2 * pairCount; j += 2)
		{
			if (relationElements[j] == y)
			{
				// We've found (y, z)!
				int z = relationElements[j + 1];
				// Now it's time to search for the pair (x, z) if one exists
				bool isTripletTransitive = false;
				for (int k = 0; k < 2 * pairCount; k += 2)
				{
					if (relationElements[k] == x && relationElements[k + 1] == z)
					{
						// Hooray, we've found (x, z)!
						isTripletTransitive = true;
						break;
					}
				}
				if (!isTripletTransitive)
				{
					// At least one triple x, y, z is not transitive -> the entire relation isn't transitive
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int n;
	std::cin >> n;
	int pairCount;
	std::cin >> pairCount;
	for (int i = 0; i < 2 * pairCount; ++i)
	{
		std::cin >> relationElements[i];
	}
	bool isReflexive = IsRelationReflexive(n, pairCount);
	bool isSymmetrical = IsRelationSymmetric(pairCount);
	bool isTransitive = IsRelationTransitive(pairCount);
	bool isEquivalence = isReflexive && isSymmetrical && isTransitive;
	std::cout << "Reflexive? " << isReflexive << std::endl;
	std::cout << "Symmetrical? " << isSymmetrical << std::endl;
	std::cout << "Transitive? " << isTransitive << std::endl;
	std::cout << "Equivalence? " << isEquivalence << std::endl;

	return 0;
}