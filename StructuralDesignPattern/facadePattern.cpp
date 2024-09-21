#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AudioPlayer
{
public:
    void playAudio(const string &song)
    {
        cout << "Playing: " << song << endl;
    }
    void stopAudio()
    {
        cout << "Stopping audio playback." << endl;
    }
};

class NetworkManager
{
public:
    void streamSong(const string &song)
    {
        cout << "Streaming song: " << song << " over the network." << endl;
    }
};

class PlaylistManager
{
private:
    vector<string> playlist = {"Levitating", "Material Girl", "Despacito"};

public:
    string getNextSong()
    {
        if (!playlist.empty())
        {
            string nextSong = playlist.back();
            playlist.pop_back();
            return nextSong;
        }
        return "No more songs in playlist.";
    }
};

class RecommendationEngine
{
public:
    string getRecommendation()
    {
        return "Recommended Sorry";
    }
};

class SpotifyFacade
{
private:
    AudioPlayer audioPlayer;
    NetworkManager networkManager;
    PlaylistManager playlistManager;
    RecommendationEngine recommendationEngine;

public:
    void playNextSong()
    {
        string nextSong = playlistManager.getNextSong();
        if (nextSong != "No more songs in playlist.")
        {
            networkManager.streamSong(nextSong);
            audioPlayer.playAudio(nextSong);
        }
        else
        {
            cout << "Playlist is empty!" << endl;
        }
    }

    void playRecommendedSong()
    {
        string recommendation = recommendationEngine.getRecommendation();
        networkManager.streamSong(recommendation);
        audioPlayer.playAudio(recommendation);
    }

    void stopPlayback()
    {
        audioPlayer.stopAudio();
    }
};

int main()
{
    SpotifyFacade spotify;

    spotify.playNextSong();
    spotify.playNextSong();
    spotify.playRecommendedSong();
    spotify.stopPlayback();

    return 0;
}
