#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class PlaybackManager
{
private:
    static PlaybackManager *instance;
    static mutex mtx;
    string currentSong;

    PlaybackManager() : currentSong("No song playing") {}

public:
    static PlaybackManager *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new PlaybackManager();
            }
        }
        return instance;
    }

    void playSong(const string &song)
    {
        currentSong = song;
        cout << "Now playing: " << currentSong << endl;
    }

    string getCurrentSong()
    {
        return currentSong;
    }

    void sendCurrentSong()
    {
        cout << "Current song: " << currentSong << endl;
    }
};

PlaybackManager *PlaybackManager::instance = nullptr;
mutex PlaybackManager::mtx;

int main()
{
    PlaybackManager *manager = PlaybackManager::getInstance();

    string song;
    char choice;

    do
    {
        cout << "Enter the song you want to play: ";
        getline(cin, song);
        manager->playSong(song);

        cout << "Do you want to send the current song? (y/n): ";
        cin >> choice;
        cin.ignore();

        if (choice == 'y' || choice == 'Y')
        {
            manager->sendCurrentSong();
        }

        cout << "Do you want to play another song? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
