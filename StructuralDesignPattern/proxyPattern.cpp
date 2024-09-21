#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Song
{
public:
    virtual void play() = 0;
    virtual ~Song() {}
};

class RealSong : public Song
{
private:
    string title;

public:
    RealSong(const string &title) : title(title)
    {
        loadFromSpotify(title);
    }

    void loadFromSpotify(const string &title)
    {
        cout << "Loading song '" << title << "' from Spotify server...\n";
    }

    void play() override
    {
        cout << "Playing song: " << title << " (streaming from server)\n";
    }
};

class SongProxy : public Song
{
private:
    string title;
    RealSong *realSong;
    static unordered_map<string, RealSong *> songCache;

public:
    SongProxy(const string &title) : title(title), realSong(nullptr) {}

    void play() override
    {
        if (songCache.find(title) != songCache.end())
        {
            realSong = songCache[title];
            cout << "Playing cached version of: " << title << "\n";
        }
        else
        {
            realSong = new RealSong(title);
            songCache[title] = realSong;
            realSong->play();
        }
    }

    ~SongProxy()
    {
        delete realSong;
    }
};

unordered_map<string, RealSong *> SongProxy::songCache;

int main()
{
    Song *song1 = new SongProxy("Shape of You");
    Song *song2 = new SongProxy("Blinding Lights");

    song1->play();

    cout << endl;

    song1->play();

    cout << endl;

    song2->play();

    delete song1;
    delete song2;

    return 0;
}
