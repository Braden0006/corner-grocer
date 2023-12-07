#include <string>
#include <unordered_map>

using namespace std;

class Inventory
{
public:
	void MenuOne();
	void MenuTwo();
	void MenuThree();
	void UserInputFile();
	void Menu();

private:
	unordered_map<string, int> itemFrequency;
	unordered_map<string, string> histogramFrequency;

	string userFile;
};

