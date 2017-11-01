#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

typedef struct SPRITEINFO
{
	int pos_x;
	int pos_y;
}SpriteInfo;

void main()
{
	SpriteInfo* spriteInfo;
	//Init array posSprite
	spriteInfo = new SpriteInfo[5];

	//Read file info of file
	ifstream f;
	try
	{
		f.open("sprites\\testsprite.txt");
	}
	catch (std::fstream::failure e)
	{
		//--TO DO: log failure

		return;
	}
	string line;
	int i = 0;
	while (!f.eof())
	{
		vector<string> pos;
		string split;
		getline(f, line);
		istringstream iss(line);

		while (getline(iss, split, ' '))
		{
			pos.push_back(split);
		}

		spriteInfo[i].pos_x = stoi(pos[0]);
		spriteInfo[i].pos_y = stoi(pos[1]);
		i++;
	}
	f.close();

	for (int j = 0; j < i; j++)
	{
		cout << spriteInfo[j].pos_x << " : " << spriteInfo[j].pos_y << endl;
	}
	system("pause");
}