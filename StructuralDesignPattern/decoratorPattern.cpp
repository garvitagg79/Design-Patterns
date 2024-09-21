#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    virtual void play() = 0; // Corrected pure virtual function declaration
    virtual ~Song() {}
};

class BasicSong : public Song
{
public:
    void play() override
    {
        cout << "Playing basic song." << endl;
    }
};

class SongDecorator : public Song
{
protected:
    Song *wrappedSong;

public:
    SongDecorator(Song *song) : wrappedSong(song) {}

    void play() override
    {
        wrappedSong->play();
    }
};

class QualityDecorator : public SongDecorator
{
public:
    QualityDecorator(Song *song) : SongDecorator(song) {}

    void play() override
    {
        SongDecorator::play();
        enhanceQuality();
    }

    void enhanceQuality()
    {
        cout << "Enhanced audio quality to high-resolution." << endl;
    }
};

class LyricsDecorator : public SongDecorator
{
public:
    LyricsDecorator(Song *song) : SongDecorator(song) {}

    void play() override
    {
        SongDecorator::play();
        displayLyrics();
    }

    void displayLyrics()
    {
        cout << "Displaying synchronized lyrics on screen." << endl;
    }
};

class KaraokeDecorator : public SongDecorator
{
public:
    KaraokeDecorator(Song *song) : SongDecorator(song) {}

    void play() override
    {
        SongDecorator::play();
        enableKaraokeMode();
    }

    void enableKaraokeMode()
    {
        cout << "Karaoke mode enabled with vocal reduction." << endl;
    }
};

int main()
{
    Song *basicSong = new BasicSong();

    Song *songWithQuality = new QualityDecorator(basicSong);

    Song *songWithLyrics = new LyricsDecorator(songWithQuality);

    Song *fullFeaturedSong = new KaraokeDecorator(songWithLyrics);

    fullFeaturedSong->play();

    // Clean up
    delete fullFeaturedSong;
    delete songWithLyrics;
    delete songWithQuality;
    delete basicSong;

    return 0;
}
