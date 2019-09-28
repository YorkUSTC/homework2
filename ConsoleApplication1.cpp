#include<regex>
#include <iostream>
#include <fstream>
using namespace std;

int get_word(string temp)
{
	int word_num = 1;
	int char_exit = 0;
	for (int i = 0; i < 26; i++)
		char_exit += count(temp.begin(), temp.end(), 'a' + i);
	if (char_exit)
		word_num += count(temp.begin(), temp.end(), ' ');
	else
		word_num = 0;
	return word_num;
}

bool is_note(string temp)
{
	string note1 = "//";
	string note2 = "}//";
	if (temp.find(note1, 0) == -1 && temp.find(note2, 0) == -1)
		return false;
	else
		return true;
}

void basic(int argc, char* argv[])
{
	ifstream inFile;
	int line_num = 0;
	int char_num = 0;
	int word_num = 0;
	int null_num = 0;
	int code_num = 0;
	int note_num = 0;
	string temp;
	char* filename;
	filename = argv[argc - 1];
	inFile.open(filename, ios::in);
	if (inFile)
	{
		while (getline(inFile, temp))
		{
			line_num++;
			char_num += temp.length();
			word_num += get_word(temp);
			if (get_word(temp) == 0)
			{
				if (is_note(temp))
					note_num++;
				else
					null_num++;
			}
			else
				code_num++;
		}
		inFile.close();
		for (int i = 1; i < argc - 1; i++)
		{
			if (argv[i][0] == '-')
			{
				switch (argv[i][1])
				{
				case 'c':
					cout << "char number:" << char_num << endl;
					break;
				case 'w':
					cout << "word number:" << word_num << endl;
					break;
				case 'l':
					cout << "line number:" << line_num << endl;
				case 'a':
					cout << "empty line number:" << null_num << endl;
					cout << "code line number:" << code_num << endl;
					cout << "note line number:" << note_num << endl;
					break;
				default:
					break;
				}
			}
		}
	}
	else
		cout << "test.txt doesn't exist" << endl;
}


int main(int argc, char* argv[])
{
	basic(argc, argv);
	return 0;
}
