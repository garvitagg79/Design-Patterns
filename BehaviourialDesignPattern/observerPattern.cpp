#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Follower
{
public:
    virtual void update(const string &album) = 0;
};

class Creator
{
    string album;
    vector<Follower *> followers;

public:
    void uploadNewAlbum(const string &latestAlbum)
    {
        album = latestAlbum;
        cout << "You uploaded a new album: " << album << endl;
        notifyFollowers();
    }

    void addFollower(Follower *follower)
    {
        followers.push_back(follower);
    }

    void removeFollower(Follower *follower)
    {
        followers.erase(remove(followers.begin(), followers.end(), follower), followers.end());
    }

    void notifyFollowers()
    {
        for (auto follower : followers)
        {
            follower->update(album);
        }
    }
};

class Fan : public Follower
{
    string name;

public:
    Fan(const string &fanName)
    {
        name = fanName;
    }

    void update(const string &album) override
    {
        cout << name << " have you heard about the new Taylor Swift's album: " << album << "?" << endl;
    }
};

int main()
{
    Creator TaylorSwift;

    Fan fan1("Jake");
    Fan fan2("Harry");
    Fan fan3("Tom");

    TaylorSwift.addFollower(&fan1);
    TaylorSwift.addFollower(&fan2);
    TaylorSwift.addFollower(&fan3);

    char choice = 'y';

    do
    {
        string latestAlbum;
        cout << "Enter the latest album Taylor: ";
        cin >> latestAlbum;

        TaylorSwift.uploadNewAlbum(latestAlbum);

        cout << "Do you want to upload another album? (y/n): ";
        cin >> choice;

        TaylorSwift.removeFollower(&fan3);

    } while (choice == 'y');

    return 0;
}