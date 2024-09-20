#include <bits/stdc++.h>
using namespace std;

class PlaybackStrategy
{
public:
    virtual void play(vector<string> &songs) = 0;
};

class PlayInOrder : public PlaybackStrategy
{
public:
    void play(vector<string> &songs) override
    {
        cout << "Playing songs in order:\n";
        for (const auto &song : songs)
        {
            cout << song << endl;
        }
    }
};

class ShufflePlay : public PlaybackStrategy
{
public:
    void play(vector<string> &songs) override
    {
        cout << "Shuffling songs and playing:\n";
        random_shuffle(songs.begin(), songs.end());
        for (const auto &song : songs)
        {
            cout << song << endl;
        }
    }
};

class RepeatSong : public PlaybackStrategy
{
    string songToRepeat;

public:
    RepeatSong(const string &song)
    {
        songToRepeat = song;
    }

    void play(vector<string> &songs) override
    {
        cout << "Playing " << songToRepeat << " on a loop\n";
    }
};

class SpotifyPlayer
{
    PlaybackStrategy *playbackStrategy;
    vector<string> songs;

public:
    SpotifyPlayer()
    {
        playbackStrategy = nullptr;
    }

    void setPlaybackStrategy(PlaybackStrategy *strategy)
    {
        playbackStrategy = strategy;
    }

    void addSong(const string &song)
    {
        songs.push_back(song);
    }

    void playSong()
    {
        if (playbackStrategy)
        {
            playbackStrategy->play(songs);
        }
        else
        {
            cout << "Choose a player to play song\n";
        }
    }
};

int main()
{
    SpotifyPlayer player;

    char choice = 'y';

    do
    {
        string song;
        cout << "Enter song: ";
        getline(cin, song);
        player.addSong(song);

        cout << "Do you want to add another song? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    int mode;
    char ch = 'y';

    do
    {
        cout << "\nChoose playback mode:\n";
        cout << "1. Play in order\n";
        cout << "2. Shuffle play\n";
        cout << "3. Repeat a specific song\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> mode;

        switch (mode)
        {
        case 1:
        {
            PlayInOrder inOrder;
            player.setPlaybackStrategy(&inOrder);
            player.playSong();
            break;
        }
        case 2:
        {
            ShufflePlay shuffle;
            player.setPlaybackStrategy(&shuffle);
            player.playSong();
            break;
        }
        case 3:
        {
            string repeatSong;
            cout << "Enter the song to repeat: ";
            cin.ignore();
            getline(cin, repeatSong);
            RepeatSong repeat(repeatSong);
            player.setPlaybackStrategy(&repeat);
            player.playSong();
            break;
        }
        default:
            cout << "Invalid choice! Exiting...\n";
            break;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}