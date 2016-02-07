#ifndef TARGET_H
#define TARGET_H
#include "../Main.h"

class Target
{
    public:
        Target();

        virtual void receveoirdegat(int degats);

        bool isDead();

        virtual ~Target();
    protected:
        int vie;
        bool dead;
    private:

};

#endif // TARGET_H
