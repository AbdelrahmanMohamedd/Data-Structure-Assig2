#include <iostream>
#include <map>
#include <string>

using namespace std;
void print_map(map<string, int> temp)
{
	map<string, int> ::iterator itr;
	for (itr = temp.begin(); itr != temp.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}
int main()
{
	map<string, int> map1;
	//Input Words.
	while (true)
	{
		string input;
		cout << "Enter A Word :";
		cin >> input;
		if (input == "Done" || input == "done")
		{
			break;
		}
		map<string, int> ::iterator itr;
		itr = map1.find(input);
		if (itr == map1.end())
		{
			map1.insert(pair<string, int>(input, 1));
		}
		else
		{
			map1[input]++;
		}
	}
	cout << "Words Followed By #Of Repetition." << endl;
	print_map(map1);

	map<string, int> ::iterator i = map1.begin();
	while(i != map1.end())
	{
		string temp = i->first;
		if (temp[0] == 'a' || temp[0] == 'A')
		{
			i = map1.erase(i);
		}

		else
		{
			i++;
		}
	}
	cout << "Words Without (a) character." << endl;
	print_map(map1);
	system("Pause");
	return 0;
}