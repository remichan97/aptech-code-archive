#include <stdio.h>

int main() {
    int cho, ga;
    for (cho = 1; cho <= 36; cho++)
    {
        for (ga = 1; ga <= 36; ga++)
        {
            if ((ga * 2 + cho * 4 == 100) && (ga + cho == 36))
            {
                printf("\nCo %d con ga, co %d con cho.", ga, cho);
            }
            
        }
        
    }
    
    return 0;
}