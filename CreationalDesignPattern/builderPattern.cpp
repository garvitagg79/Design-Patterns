#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Playlist
{
public:
    string name;
    string description;
    string coverImage;
    vector<string> songs;

    void showDetails()
    {
        cout << "Playlist name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Cover Image: " << coverImage << endl;
        cout << "Songs: " << endl;
        for (const auto &song : songs)
        {
            cout << "- " << song << endl;
        }
    }
};

class PlaylistBuilder
{
public:
    virtual void setName(const string &name) = 0;
    virtual void setDescription(const string &description) = 0;
    virtual void setCoverImage(const string &coverImage) = 0;
    virtual void setSongs(const vector<string> &songs) = 0;
    virtual Playlist *getPlaylist() = 0;
    virtual ~PlaylistBuilder() {}
};

class Downloads : public PlaylistBuilder
{
    Playlist *playlist;

public:
    Downloads()
    {
        playlist = new Playlist();
    }

    void setName(const string &name) override
    {
        playlist->name = "Downloads";
    }

    void setDescription(const string &description) override
    {
        playlist->description = description;
    }

    void setCoverImage(const string &coverImage) override
    {
        playlist->coverImage = "Download Image";
    }

    void setSongs(const vector<string> &songs) override
    {
        playlist->songs = songs;
    }

    Playlist *getPlaylist() override
    {
        return playlist;
    }

    ~Downloads()
    {
        delete playlist;
    }
};

class CustomPlaylist : public PlaylistBuilder
{
    Playlist *playlist;

public:
    CustomPlaylist()
    {
        playlist = new Playlist();
    }

    void setName(const string &name) override
    {
        playlist->name = name;
    }

    void setDescription(const string &description) override
    {
        playlist->description = description;
    }

    void setCoverImage(const string &coverImage) override
    {
        playlist->coverImage = coverImage;
    }

    void setSongs(const vector<string> &songs) override
    {
        playlist->songs = songs;
    }

    Playlist *getPlaylist() override
    {
        return playlist;
    }

    ~CustomPlaylist()
    {
        delete playlist;
    }
};

class LikedSongs : public PlaylistBuilder
{
    Playlist *playlist;

public:
    LikedSongs()
    {
        playlist = new Playlist();
    }

    void setName(const string &name) override
    {
        playlist->name = "Liked Songs";
    }

    void setDescription(const string &description) override
    {
        playlist->description = description;
    }

    void setCoverImage(const string &coverImage) override
    {
        playlist->coverImage = "Liked Song Image";
    }

    void setSongs(const vector<string> &songs) override
    {
        playlist->songs = songs;
    }

    Playlist *getPlaylist() override
    {
        return playlist;
    }

    ~LikedSongs()
    {
        delete playlist;
    }
};

class YourLibrary
{
    PlaylistBuilder *builder;

public:
    void setBuilderType(PlaylistBuilder *b)
    {
        builder = b;
    }

    Playlist *createPlaylist(const string &name, const string &description, const string &coverImage, const vector<string> &songs)
    {
        builder->setName(name);
        builder->setDescription(description);
        builder->setCoverImage(coverImage);
        builder->setSongs(songs);
        return builder->getPlaylist();
    }

    ~YourLibrary()
    {
        delete builder;
    }
};

int main()
{
    int user = 1;

    do
    {
        string type;
        YourLibrary library;
        cout << "Enter type of Playlist: ";
        cin >> type;
        cin.ignore();

        int totalSongs;
        string name, description, coverImage;
        vector<string> songList;

        PlaylistBuilder *builder = nullptr;

        if (type == "Downloads")
        {
            name = "Downloads";
            coverImage = "Download Image";

            cout << "Enter playlist description: ";
            getline(cin, description);

            cout << "Enter number of songs to add: ";
            cin >> totalSongs;

            songList.resize(totalSongs);
            cout << "Enter song names: " << endl;
            cin.ignore();
            for (int i = 0; i < totalSongs; i++)
            {
                cout << "Song " << i + 1 << ": ";
                getline(cin, songList[i]);
            }

            builder = new Downloads();
        }
        else if (type == "Custom")
        {
            cout << "Enter Playlist name: ";
            getline(cin, name);

            cout << "Enter Playlist description: ";
            getline(cin, description);

            cout << "Enter cover image: ";
            getline(cin, coverImage);

            cout << "Enter number of songs to add: ";
            cin >> totalSongs;

            songList.resize(totalSongs);
            cout << "Enter song names: " << endl;
            cin.ignore();
            for (int i = 0; i < totalSongs; i++)
            {
                cout << "Song " << i + 1 << ": ";
                getline(cin, songList[i]);
            }

            builder = new CustomPlaylist();
        }
        else if (type == "LikedSongs")
        {
            name = "Liked Songs";
            coverImage = "Liked Song Image";

            cout << "Enter playlist description: ";
            getline(cin, description);

            cout << "Enter number of songs to add: ";
            cin >> totalSongs;

            songList.resize(totalSongs);
            cout << "Enter song names: " << endl;
            cin.ignore();
            for (int i = 0; i < totalSongs; i++)
            {
                cout << "Song " << i + 1 << ": ";
                getline(cin, songList[i]);
            }

            builder = new LikedSongs();
        }
        else
        {
            cout << "Playlist type doesn't exist." << endl;
            continue;
        }

        library.setBuilderType(builder);

        Playlist *playlist = library.createPlaylist(name, description, coverImage, songList);
        playlist->showDetails();

        cout << "Do you want to continue? (1: Yes, 0: No): ";
        cin >> user;
        cin.ignore();

        delete playlist;

    } while (user != 0);

    return 0;
}
