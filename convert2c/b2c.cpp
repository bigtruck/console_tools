#include <iostream>
#include <fstream>

using namespace std;

#define DATA_BUFF_SIZE (1024 * 1024 * 1)
char inFileDataBuff[DATA_BUFF_SIZE];
char outFileDataBuff[DATA_BUFF_SIZE * 1];

int main(int argc, char const *argv[])
{
	cout << "!!!TOOL BY xiaoyong!!!" << endl;
	if (argc < 2)
	{
		cout << "缺少参数" << endl;
		for (int i = 1; i < argc; i++)
		{
			cout << "argv-" << i << ' ' << argv[i] << endl;
		}
		return -1;
	}
	// open in file
	cout << "input file:" << argv[1] << endl;
	ifstream infile(argv[1], ios::binary | ios::in);
	if (!infile)
	{
		cout << "cannot open " << argv[1] << endl;
	}
	else
	{
		// create out file name
		string strOutName;
		if (argc > 2)
		{
			strOutName = argv[2];
		}
		else
		{
			string strInName = argv[1];
			size_t found = strInName.find_last_of('.');
			strOutName = strInName.substr(0, found);
			strOutName += ".dat";
		}
		cout << "output file:" << strOutName << endl;
		ofstream outFile(strOutName, ios::out | ios::binary);
		if (!outFile)
		{
			cout << "create file " << strOutName << " error!" << endl;
			infile.close();
			return 0;
		}
		outFile.seekp(outFile.beg);
		uint32_t count;
		uint32_t index;
		char buffer[32];
		do
		{
			infile.read(inFileDataBuff, sizeof(inFileDataBuff));
			count = infile.gcount();
			index = 0;
			while (index < count)
			{
				int l = sprintf(buffer, "0x%02X,", (unsigned char)inFileDataBuff[index]);
				index++;
				outFile.write(buffer, l);
				if ((index % 16) == 0)
				{
					outFile.write("\r\n", 2);
				}
			}
		} while (infile.eof() == false);
		infile.close();
		outFile.close();
	}

	return 0;
}
