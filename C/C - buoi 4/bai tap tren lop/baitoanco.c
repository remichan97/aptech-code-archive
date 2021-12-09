#include <stdio.h>

int main() {
    int traudung, traunam, traugia;
    for (traudung = 1; traudung <= 100; traudung++)
    {
        for (traunam = 1; traunam <= 100; traunam++)
        {
            for (traugia = 1; traugia <= 100; traugia++)
            {
                if ((5 * traudung + 3* traunam + traugia /3 == 100) && (traugia % 3 == 0) && (traudung + traunam + traugia == 100) )
            {
                printf("\nTrau dung %d con, Trau nam %d con, Trau gia %d con", traudung, traunam, traugia);
            }
            }
        }
    }
    return 0;
}