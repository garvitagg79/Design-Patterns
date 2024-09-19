#include <iostream>
using namespace std;

class Handler
{
public:
    virtual Handler *setNext(Handler *handler) = 0;
    virtual void handle(bool isAuthenticated, int speed) = 0;
};

class PlayerHandler : public Handler
{
    Handler *nextHandler;

public:
    PlayerHandler()
    {
        nextHandler = nullptr;
    }

    Handler *setNext(Handler *handler) override
    {
        this->nextHandler = handler;
        return handler;
    }

    void handle(bool isAuthenticated, int speed) override
    {
        if (this->nextHandler)
            this->nextHandler->handle(isAuthenticated, speed);
    }
};

class AuthenticationHandler : public PlayerHandler
{
public:
    void handle(bool isAuthenticated, int speed) override
    {
        if (speed >= 200)
        {
            if (isAuthenticated)
            {
                cout << "Authentication check successful" << endl;
                PlayerHandler::handle(isAuthenticated, speed);
            }
            else
            {
                cout << "Authentication failed" << endl;
            }
        }
        else
        {
            cout << "Please check your internet connection" << endl;
        }
    }
};

class ConnectionHandler : public PlayerHandler
{
public:
    void handle(bool isAuthenticated, int speed) override
    {
        if (speed >= 2400)
        {
            cout << "Playing Song in 320kbps" << endl;
            PlayerHandler::handle(isAuthenticated, speed);
        }
        else if (speed > 200 && speed < 2400)
        {
            cout << "Playing Song in 160kbps" << endl;
            PlayerHandler::handle(isAuthenticated, speed);
        }
        else
        {
            cout << "Please check your internet connection" << endl;
        }
    }
};

class PlaySong
{
    Handler *handle;

public:
    PlaySong(Handler *h)
    {
        handle = h;
    }

    void playSong(bool isAuthenticated, int speed)
    {
        cout << "Attempting to play the song...\n";
        handle->handle(isAuthenticated, speed);
    }
};

int main()
{
    AuthenticationHandler *auth = new AuthenticationHandler();
    ConnectionHandler *conn = new ConnectionHandler();

    auth->setNext(conn);

    PlaySong player(auth);

    bool isAuthenticated = false;
    int speed = 0;

    cout << "Are you authenticated? ";
    cin >> isAuthenticated;

    cout << "Enter you connection speed: ";
    cin >> speed;

    player.playSong(isAuthenticated, speed);

    return 0;
}