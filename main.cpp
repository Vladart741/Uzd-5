#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <gtest/gtest.h>

struct parametrai
{
	int kiek;
	std::vector<int>eil;
};

void remove(std::string& str, char character);
std::vector<int> eilutes_nustatymas(std::string str);

TEST(parametrai, kiekio_testas)
{
	std::map<std::string, parametrai> test;
	test["test"].kiek= 10;

	EXPECT_EQ(10, test["test"].kiek);
}

TEST(parametrai, eilutes_testas)
{
	std::map<std::string, parametrai> test;
	test["test"].eil.push_back(10);

	EXPECT_EQ(10, test["test"].eil[0]);
}

int main(int argc, char* argv[])
{
	std::vector<char>simboliai;
	{
		simboliai.push_back('.');
		simboliai.push_back(',');
		simboliai.push_back('!');
		simboliai.push_back('?');
		simboliai.push_back('=');
		simboliai.push_back('-');
		simboliai.push_back('"');
		simboliai.push_back('(');
		simboliai.push_back(')');
		simboliai.push_back('_');
		simboliai.push_back('+');
		simboliai.push_back('/');
		simboliai.push_back('*');
		simboliai.push_back('<');
		simboliai.push_back('>');
		simboliai.push_back('{');
		simboliai.push_back('}');
		simboliai.push_back('|');
		simboliai.push_back('#');
		simboliai.push_back('”');
		simboliai.push_back('“');
		simboliai.push_back('—');
		simboliai.push_back(':');
		simboliai.push_back(';');
		
	}

	std::ifstream fd("Duomenys.txt");
	if (!fd)
	{
		std::cout << "Error opening data file " << std::endl;
		return 1;
	}
	std::map<std::string, parametrai> duom;
	std::string zodis;
	while (fd >> zodis)
	{
		
		for (auto i = 0; i != simboliai.size(); i++)
		{
			remove(zodis, simboliai[i]);
		}

		std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper); // Konvertina visus simbolius i upper

		if (duom.find(zodis) != duom.end())
		{
			duom[zodis].kiek++;
			duom[zodis].eil = eilutes_nustatymas(zodis);
		}
		else
		{
			duom[zodis].kiek = 1;
		}
		
	}
	duom.erase("");

	std::ofstream fr("rez.txt");
	for (auto i : duom)
	{
		if (i.second.kiek > 1)
		{
			fr << "Zodis " <<"["<< i.first<<"]" << " pasikartoja " << i.second.kiek << " kartu siose eilutese: ";
			for (auto j = 0; j != i.second.eil.size(); j++)
			{
				fr << i.second.eil[j] << " ";
			}
			fr << std::endl;
		}
	}
	testing::InitGoogleTest(&argc, argv);

	
	return RUN_ALL_TESTS();
	system("pause");
	
	return 0;
}

void remove(std::string& str, char character)
{
	//Pasalina simbolius
	 size_t pos;
	 while ((pos = str.find(character)) != std::string::npos)
	 {
		 str.erase(pos, 1);	
	 }

}
std::vector<int> eilutes_nustatymas(std::string str)
{
	std::ifstream fd("Duomenys.txt");
	std::string zodis;
	std::vector<int>eil;
	int eilute = 1;
	while (std::getline(fd, zodis))
	{
		std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);
		if (zodis.find(str) != std::string::npos) {
			eil.push_back(eilute);
		}
		eilute++;
	}
	return eil;
}