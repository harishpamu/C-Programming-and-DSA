#include <stdio.h>

enum State{
    IDLE,
    START,
    RUNNING,
    STOP
};

int main()
{
    enum State current = RUNNING;

    switch(current)
    {
        case IDLE:
            printf("IDLE\n");
            break;

        case START:
            printf("START\n");
            break;

        case RUNNING:
            printf("RUNNING\n");
            break;

        case STOP:
            printf("STOP\n");
            break;
    }

    return 0;
}