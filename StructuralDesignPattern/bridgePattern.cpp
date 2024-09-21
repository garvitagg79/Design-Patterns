#include <iostream>
#include <string>
using namespace std;

class PlaybackRestrictions
{
public:
    virtual void play() = 0;
};

class AdsPlayback : public PlaybackRestrictions
{
public:
    void play() override
    {
        cout << "Playing with ads." << endl;
    }
};

class NoAdsPlayback : public PlaybackRestrictions
{
public:
    void play() override
    {
        cout << "Playing without ads." << endl;
    }
};

class Account
{
protected:
    PlaybackRestrictions *playbackRestrictions;

public:
    Account(PlaybackRestrictions *restrictions) : playbackRestrictions(restrictions) {}

    virtual void display() = 0;

    void play()
    {
        playbackRestrictions->play();
    }
};

class FreeAccount : public Account
{
public:
    FreeAccount(PlaybackRestrictions *restrictions) : Account(restrictions) {}

    void display() override
    {
        cout << "Free Account: " << endl;
        play();
    }
};

class PremiumAccount : public Account
{
public:
    PremiumAccount(PlaybackRestrictions *restrictions) : Account(restrictions) {}

    void display() override
    {
        cout << "Premium Account: " << endl;
        play();
    }
};

int main()
{
    PlaybackRestrictions *adsPlayback = new AdsPlayback();
    PlaybackRestrictions *noAdsPlayback = new NoAdsPlayback();

    Account *freeAccount = new FreeAccount(adsPlayback);
    Account *premiumAccount = new PremiumAccount(noAdsPlayback);

    freeAccount->display();
    premiumAccount->display();

    return 0;
}
