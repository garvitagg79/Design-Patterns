#include <iostream>
#include <string>
using namespace std;

class SongType
{
public:
    virtual void PlaySong() = 0;
    virtual ~SongType() {}
};

class Romantic : public SongType
{
public:
    void PlaySong() override
    {
        cout << "Romantic song playing \n";
    }
};

class Sad : public SongType
{
public:
    void PlaySong() override
    {
        cout << "Sad song playing \n";
    }
};

class BGM : public SongType
{
public:
    void PlaySong() override
    {
        cout << "BGM song playing \n";
    }
};

class SongFactory
{
public:
    SongType *getSongType(string type)
    {
        if (type == "Romantic")
            return new Romantic();
        else if (type == "Sad")
            return new Sad();
        else if (type == "BGM")
            return new BGM();
        return nullptr;
    }
};

int main()
{
    int user = 1;
    string type;

    do
    {
        cout << "Enter song type (Romantic/Sad/BGM): ";
        cin >> type;

        SongFactory factory;
        SongType *song = factory.getSongType(type);

        if (song)
        {
            song->PlaySong();
            delete song;
        }
        else
        {
            cout << "Invalid song type entered.\n";
        }

        cout << "Want to add more? (1 for Yes, 0 for No): ";
        cin >> user;
    } while (user == 1);

    return 0;
}
