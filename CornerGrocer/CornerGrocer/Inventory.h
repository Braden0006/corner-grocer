#include <string>
#include <vector>

using namespace std;

class Inventory
{
public:
	void InventoryList();
	void Menu();

private:
	vector<string> items;
};

