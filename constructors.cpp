#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    string name;
    int stamina;

    Player(string n, int s)
        : name(n),stamina(s) {}

    Player(const Player& other)
        {
            name = other.name;
            stamina = other.stamina;
            cout << "copy constructor called\n";
        }
};

int main(){
    Player p1("Messi", 20);
    Player p2 = p1;
    cout << p2.name << " " << p2.stamina << endl;
}

