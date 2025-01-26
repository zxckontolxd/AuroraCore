#include "state/istate.h"

class MainWindowState : public IState
{
private:

public:
    MainWindowState();
    ~MainWindowState();

    void update() override;
};
