#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PlaylistComponent
{
public:
    virtual void play() = 0;
    virtual ~PlaylistComponent() {}
};

class Song : public PlaylistComponent
{
private:
    string title;

public:
    Song(const string &title) : title(title) {}

    void play() override
    {
        cout << "Playing song: " << title << endl;
    }
};

class Playlist : public PlaylistComponent
{
private:
    string name;
    vector<PlaylistComponent *> components;

public:
    Playlist(const string &name) : name(name) {}

    void add(PlaylistComponent *component)
    {
        components.push_back(component);
    }

    void remove(PlaylistComponent *component)
    {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    void play() override
    {
        cout << "Playing playlist: " << name << endl;
        for (auto &component : components)
        {
            component->play();
        }

        cout << endl;
    }

    ~Playlist()
    {
        for (auto component : components)
        {
            delete component;
        }
    }
};

int main()
{
    PlaylistComponent *song1 = new Song("Blank Space");
    PlaylistComponent *song2 = new Song("Style");
    PlaylistComponent *song3 = new Song("Shake It Off");
    PlaylistComponent *song4 = new Song("Lover");

    Playlist *playlist1 = new Playlist("Best of Taylor Swift");

    playlist1->add(song1);
    playlist1->add(song2);
    playlist1->add(song3);
    playlist1->add(song4);

    Playlist *mainPlaylist = new Playlist("Taylor Swift");

    PlaylistComponent *song5 = new Song("Welcome to New York");
    PlaylistComponent *song6 = new Song("Fortnight");

    mainPlaylist->add(playlist1);
    mainPlaylist->add(song5);
    mainPlaylist->add(song6);
    mainPlaylist->add(song4);

    mainPlaylist->play();

    playlist1->remove(song3);
    cout << "\nAfter removing Lover from 'Best of Taylor Swift':" << endl;
    mainPlaylist->play();

    delete mainPlaylist;

    return 0;
}
