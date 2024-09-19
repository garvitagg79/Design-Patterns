#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;
};

class PlaylistIterator : public Iterator
{
    vector<string> songs;
    int position;

public:
    PlaylistIterator(const vector<string> &playlist) : songs(playlist), position(0) {}

    bool hasNext() override
    {
        return position < songs.size();
    }

    string next() override
    {
        if (hasNext())
        {
            return songs[position++];
        }

        return "";
    }
};

class Playlist
{
public:
    virtual Iterator *createIterator() = 0;
};

class SpotifyPlaylist : public Playlist
{
    vector<string> songs;

public:
    Iterator *createIterator() override
    {
        return new PlaylistIterator(songs);
    }

    void addSong(const string &song)
    {
        songs.push_back(song);
    }

    vector<string> getSongs()
    {
        return songs;
    }
};

int main()
{
    SpotifyPlaylist playlist;
    int numberOfSongs;

    cout << "Enter number of songs: ";
    cin >> numberOfSongs;

    vector<string> songs;

    for (int i = 0; i < numberOfSongs; i++)
    {
        string song;
        cout << "Enter song " << i + 1 << ": ";
        cin >> song;
        playlist.addSong(song);
    }

    Iterator *iterator = playlist.createIterator();

    cout << "Songs in the Spotify Playlist:\n";

    while (iterator->hasNext())
    {
        cout << iterator->next() << endl;
    }

    delete iterator;

    return 0;
}
