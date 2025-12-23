/*Given a File of N employee records with a set K of Keys(4-digit) which
uniquely determine the records in file F.
Assume that file F is maintained in memory by a Hash Table (HT) of m
memory locations with L as the set of memory addresses (2-digit) of
locations in HT.
Let the keys in K and addresses in L are integers.
Design and develop a Program in C that uses Hash function H: K -&gt; L as
H(K)=K mod m (remainder method), and implement hashing technique to
map a given key K to the address space L.
Resolve the collision (if any) using linear probing.*/

#include <stdio.h>
#define EMPTY -1   
int main() {
    int n, m, i, key, index;
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    int HT[m];  
    for (i = 0; i < m; i++) {
        HT[i] = EMPTY;   
    }
    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % m;  
        while (HT[index] != EMPTY) {
            index = (index + 1) % m;
        }
        HT[index] = key;
    }
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        if (HT[i] == EMPTY)
            printf("index %d: EMPTY\n", i);
        else
            printf("index %d: Key=%d\n", i, HT[i]);
    }
    return 0;
}