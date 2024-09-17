#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrototypePlaylist
{
public:
    virtual PrototypePlaylist *clone() = 0;
    virtual ~PrototypePlaylist() {}
};

class Playlist : public PrototypePlaylist
{
    string name, description, coverImage;
    vector<string> songs;

public:
    Playlist()
    {
        name = "Taylor Swift Songs";
        description = "This is the Taylor Swift songs playlist";
        coverImage = "Taylor Swift Image";
        songs.push_back("AntiHero");
        songs.push_back("Lover");
        songs.push_back("Fortnight");
    }

    void showPlaylist()
    {
        cout << "Playlist Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Cover Image: " << coverImage << endl;
        cout << "Song List: \n";
        for (const auto &song : songs)
        {
            cout << "- " << song << endl;
        }
        cout << endl;
    }

    PrototypePlaylist *clone() override
    {
        return new Playlist(*this);
    }
};

int main()
{
    int user = 1;

    do
    {
        Playlist orgPlaylist;

        orgPlaylist.showPlaylist();

        int numberOfClones;

        cout << "Enter number of clones to make: ";
        cin >> numberOfClones;

        cout << "Here are your clones:\n";

        while (numberOfClones > 0)
        {
            Playlist *clone = static_cast<Playlist *>(orgPlaylist.clone());
            clone->showPlaylist();

            delete clone;
            numberOfClones--;
        }

        cout << "Want to add more? Press 1 to continue, 0 to exit: ";
        cin >> user;
    } while (user == 1);

    return 0;
}
