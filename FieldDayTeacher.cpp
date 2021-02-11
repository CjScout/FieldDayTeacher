#include "Headers.h"

sf::TcpSocket serverLink;
sf::Packet packet;
sf::Packet packet2;

string input;
string task;

string id = "Griffin";
string action;
int value;

sf::Uint32 grade5Score;
sf::Uint32 grade6Score;
sf::Uint32 grade7Score;
sf::Uint32 grade8Score;

int main()
{
    cout << "Press 1 and then ENTER to get a task" << endl;
    cout << "Press 2 and then ENTER to get the current score" << endl;

    cin >> input;

    if (input == "1")
    {
        serverLink.connect("10.0.0.209", 53000);

        action = "task";

        packet << id << action << value;

        serverLink.send(packet);
        
        serverLink.receive(packet2);
        
        packet2 >> task;
        
        cout << "You have been given the task: " << task << endl;
        cout << "Press 1 and then ENTER to complete the task" << endl << "Press 2 and then ENTER to skip this task" << endl;
        cin >> input;
        
        if (input == "1")
        {
            value = 1;
            packet << value;
            serverLink.send(packet);
        }
        
        if (input == "2")
        {
            value = 2;
            packet << value;
            serverLink.send(packet);
        }
    }

    if (input == "2")
    {
        serverLink.connect("10.0.0.209", 53000);

        action = "score";

        packet << id << action << value;

        serverLink.send(packet);

        serverLink.receive(packet);

        packet >> grade5Score >> grade6Score >> grade7Score >> grade8Score;

        cout << grade5Score << grade6Score << grade7Score << grade8Score;
    }
}
