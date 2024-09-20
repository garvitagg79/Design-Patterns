#include <iostream>
#include <string>
using namespace std;

class DownloadProcess
{
public:
    void downloadSong(const string &song)
    {
        checkSubscription();
        connectToServer();
        download(song);
        convertFileFormat();
        finishDownload();
    }

    void connectToServer()
    {
        cout << "Connecting to the Spotify server...\n"
             << endl;
    }

    void finishDownload()
    {
        cout << "Download finished successfully!\n"
             << endl;
    }

    virtual void checkSubscription() = 0;
    virtual void download(const string &song) = 0;
    virtual void convertFileFormat() = 0;

    virtual ~DownloadProcess() {}
};

class FreeUserDownload : public DownloadProcess
{
public:
    void checkSubscription() override
    {
        cout << "Checking subscription for Free User...\n";
    }

    void download(const string &song) override
    {
        cout << "Downloading song with ads for Free User: " << song << "\n";
    }

    void convertFileFormat() override
    {
        cout << "Converting song to lower quality MP3 format for Free User...\n";
    }
};

class PremiumUserDownload : public DownloadProcess
{
public:
    void checkSubscription() override
    {
        cout << "Checking subscription for Premium User...\n";
    }

    void download(const string &song) override
    {
        cout << "Downloading song in high quality for Premium User: " << song << "\n";
    }

    void convertFileFormat() override
    {
        cout << "Converting song to high quality FLAC format for Premium User...\n";
    }
};

int main()
{
    DownloadProcess *freeUser = new FreeUserDownload();
    DownloadProcess *premiumUser = new PremiumUserDownload();

    cout << "Free User Downloading Song:\n";
    freeUser->downloadSong("Blinding Lights - The Weeknd");

    cout << "\nPremium User Downloading Song:\n";
    premiumUser->downloadSong("Levitating - Dua Lipa");

    delete freeUser;
    delete premiumUser;

    return 0;
}