#include <iostream>
#include <string>

using namespace std;

int checkIfIdIsAuthorized(int id, int allowedIds[], int allowedIdsLength)
{
	int firstIdsIndex = 0;
	int lastIdsIndex = allowedIdsLength;
	int halfIdsIndex = (firstIdsIndex + lastIdsIndex) / 2;

	while (firstIdsIndex <= lastIdsIndex)
	{
		if (allowedIds[halfIdsIndex] == id)
		{
			return halfIdsIndex;
		}
		else
		{
			if (id > allowedIds[halfIdsIndex])
			{
				firstIdsIndex = halfIdsIndex + 1;
				halfIdsIndex = (firstIdsIndex + lastIdsIndex) / 2;
			}
			else
			{
				lastIdsIndex = halfIdsIndex - 1;
				halfIdsIndex = (firstIdsIndex + lastIdsIndex) / 2;
			}
		}
	}

	return -1;
}

int main()
{
	int maxIds = 20;
	int allowedIds[maxIds];
	int currentId = 0;
	int allowedIdsLength = 0;

	for (int i = 0; i < maxIds; i++)
	{
		cin >> currentId;
		if (currentId == -1)
		{
			break;
		}
		allowedIds[i] = currentId;
		allowedIdsLength++;
	}

	int idToBeChecked;
	cin >> idToBeChecked;

	int indexOfIdToBeChecked = checkIfIdIsAuthorized(idToBeChecked, allowedIds, allowedIdsLength);

	if (indexOfIdToBeChecked != -1)
		cout << "Possui acesso" << endl;
	else
		cout << "Nao possui acesso" << endl;

	return 0;
}