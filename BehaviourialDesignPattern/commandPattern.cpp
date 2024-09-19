#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class SpotifyPlayer
{
    string currentSong;
    deque<string> songHistory;

public:
    void play(const string &song)
    {
        if (!currentSong.empty())
        {
            songHistory.push_front(currentSong);
        }
        currentSong = song;
        cout << "Playing song: " << currentSong << endl;
    }

    void pause()
    {
        cout << "Pausing song: " << currentSong << endl;
    }

    void previous()
    {
        if (!songHistory.empty())
        {
            currentSong = songHistory.front();
            songHistory.pop_front();
            cout << "Playing previous song: " << currentSong << endl;
        }
        else
        {
            cout << "No previous song in history." << endl;
        }
    }

    void loop()
    {
        cout << "Looping current song." << endl;
    }
};

class PlayCommand : public Command
{
    SpotifyPlayer *player;
    string song;

public:
    PlayCommand(SpotifyPlayer *p, const string &s)
    {
        player = p;
        song = s;
    }

    void execute() override
    {
        player->play(song);
    }
};

class PauseCommand : public Command
{
    SpotifyPlayer *player;

public:
    PauseCommand(SpotifyPlayer *p)
    {
        player = p;
    }

    void execute() override
    {
        player->pause();
    }
};

class PreviousCommand : public Command
{
    SpotifyPlayer *player;

public:
    PreviousCommand(SpotifyPlayer *p)
    {
        player = p;
    }

    void execute() override
    {
        player->previous();
    }
};

class LoopCommand : public Command
{
    SpotifyPlayer *player;

public:
    LoopCommand(SpotifyPlayer *p)
    {
        player = p;
    }

    void execute() override
    {
        player->loop();
    }
};

class Button
{
    Command *command;

public:
    void setCommand(Command *c)
    {
        command = c;
    }

    void pressButton()
    {
        if (command)
        {
            command->execute();
        }
    }
};

int main()
{
    SpotifyPlayer player;

    char choice = 'y';

    do
    {
        string cmd;
        cout << "Enter command: ";
        cin >> cmd;

        Button button;

        if (cmd == "play")
        {
            string song;
            cout << "\nEnter song name: ";
            cin >> song;
            PlayCommand play(&player, song);

            button.setCommand(&play);
            button.pressButton();
        }
        else if (cmd == "pause")
        {
            PauseCommand pause(&player);
            button.setCommand(&pause);
            button.pressButton();
        }
        else if (cmd == "previous")
        {
            PreviousCommand previous(&player);
            button.setCommand(&previous);
            button.pressButton();
        }
        else if (cmd == "loop")
        {
            LoopCommand loop(&player);
            button.setCommand(&loop);
            button.pressButton();
        }
        else
        {
            cout << "Command not exist\n";
        }

        cout << "Want to add another command? (y/n) ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
