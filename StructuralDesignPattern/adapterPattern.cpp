#include <iostream>
#include <string>

using namespace std;

class DesktopMenu
{
public:
    virtual void showFullMenu()
    {
        cout << "Showing full expanded menu for desktop view." << endl;
    }
};

class MobileMenu
{
public:
    void showCollapsedMenu()
    {
        cout << "Showing collapsed hamburger menu for mobile view." << endl;
    }
};

class MobileMenuAdapter : public DesktopMenu
{
private:
    MobileMenu *mobileMenu;

public:
    MobileMenuAdapter(MobileMenu *menu) : mobileMenu(menu) {}

    void showFullMenu() override
    {
        mobileMenu->showCollapsedMenu();
    }
};

int main()
{
    string deviceType;
    cout << "Are you using Desktop or Mobile? Enter 'desktop' or 'mobile': ";
    cin >> deviceType;

    if (deviceType == "desktop")
    {
        DesktopMenu desktopMenu;
        desktopMenu.showFullMenu();
    }
    else if (deviceType == "mobile")
    {
        MobileMenu mobileMenu;
        MobileMenuAdapter adapter(&mobileMenu);
        adapter.showFullMenu();
    }
    else
    {
        cout << "Invalid input! Please enter 'desktop' or 'mobile'." << endl;
    }

    return 0;
}
