#include <string>
#include <unordered_map>

using namespace std;

class Inventory
{
public:
	void MenuOne();
	void MenuTwo();
	void MenuThree();
	void Menu();

private:
	unordered_map<string, int> itemFrequency;
	unordered_map<string, string> histogramFrequency;

	string userFile = "CS210_Project_Three_Input_File.txt";
};

