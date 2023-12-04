#include <string>
#include <unordered_map>

using namespace std;

class Inventory
{
public:
	void MenuTwo();
	void Menu();

private:
	unordered_map<string, int> itemFrequency;
};

