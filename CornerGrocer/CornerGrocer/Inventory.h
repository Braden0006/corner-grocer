#include <string>
#include <unordered_map>

using namespace std;

class Inventory
{
public:
	void MenuTwo();
	void UserInputFile();
	void Menu();

private:
	unordered_map<string, int> itemFrequency;
	string userFile;
};

