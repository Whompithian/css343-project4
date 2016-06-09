#include <string>

using namespace std;

class Merch
{
public:
	Merch();
	~Merch();
	Merch(const Merch& copy);
	string getDescription()const;

private:
	string description; // might not be implemented
	void changeDescription();
};
