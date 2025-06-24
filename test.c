#include <stdio.h>
#include <stdlib.h>

void minimumBribes(int q[], int n) {
    int bribes = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        // Start checking from max(0, q[i] - 2)
	int c = 0;
        for (int j = (q[i] - 2 > 0 ? q[i] - 2 : 0); j < i; j++) {
	    printf("comapre %d %d\n", q[j], q[i]); 
            if (q[j] > q[i]) {
                bribes++;
		c++;
            }
        }
    	printf("%d %d\n", bribes, c);
    }
    printf("%d\n", bribes);
}

int main() {
    int q[] = {1, 2, 5, 3, 7, 8, 6, 4};
    int n = sizeof(q) / sizeof(q[0]);
    minimumBribes(q, n);
    return 0;
}
