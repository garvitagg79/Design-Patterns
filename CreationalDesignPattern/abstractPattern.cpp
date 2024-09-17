#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    virtual void PlaySong() = 0;
    virtual ~Song() {}
};

class Lover : public Song
{
public:
    void PlaySong() override
    {
        cout << "Lover song playing \n";
    }
};

class KinniKinni : public Song
{
public:
    void PlaySong() override
    {
        cout << "KinniKinni song playing \n";
    }
};

class Fortnight : public Song
{
public:
    void PlaySong() override
    {
        cout << "Fortnight song playing \n";
    }
};

class AntiHero : public Song
{
public:
    void PlaySong() override
    {
        cout << "AntiHero song playing \n";
    }
};

class Espresso : public Song
{
public:
    void PlaySong() override
    {
        cout << "Espresso song playing \n";
    }
};

class PleasePlease : public Song
{
public:
    void PlaySong() override
    {
        cout << "PleasePlease song playing \n";
    }
};

class Artist
{
public:
    virtual Song *getSongType(string type) = 0;
    virtual ~Artist() {}
};

class DiljitDosanjh : public Artist
{
public:
    Song *getSongType(string type) override
    {
        if (type == "Lover")
            return new Lover();
        else if (type == "KinniKinni")
            return new KinniKinni();
        return nullptr;
    }
};

class TaylorSwift : public Artist
{
public:
    Song *getSongType(string type) override
    {
        if (type == "AntiHero")
            return new AntiHero();
        else if (type == "Fortnight")
            return new Fortnight();
        return nullptr;
    }
};

class SabrinaCarpenter : public Artist
{
public:
    Song *getSongType(string type) override
    {
        if (type == "PleasePlease")
            return new PleasePlease();
        else if (type == "Espresso")
            return new Espresso();
        return nullptr;
    }
};

class BestOf2024
{
public:
    Artist *getArtistType(string artistName)
    {
        if (artistName == "Diljit")
            return new DiljitDosanjh();
        else if (artistName == "Taylor")
            return new TaylorSwift();
        else if (artistName == "Sabrina")
            return new SabrinaCarpenter();
        return nullptr;
    }
};

int main()
{
    int user = 1;
    string artistName, songName;

    do
    {
        cout << "Enter artist name: ";
        cin >> artistName;

        BestOf2024 section;
        Artist *artist = section.getArtistType(artistName);

        if (artist)
        {
            int playMore = 1;
            do
            {
                cout << "Enter song name: ";
                cin >> songName;

                Song *song = artist->getSongType(songName);

                if (song)
                {
                    song->PlaySong();
                    delete song;
                }
                else
                {
                    cout << "Invalid song name entered.\n";
                }

                cout << "Want to play another song from the same artist? (1 for Yes, 0 for No): ";
                cin >> playMore;

            } while (playMore == 1);

            delete artist;
        }
        else
        {
            cout << "Invalid artist entered.\n";
        }

        cout << "Want to add more? (1 for Yes, 0 for No): ";
        cin >> user;

    } while (user == 1);

    return 0;
}
