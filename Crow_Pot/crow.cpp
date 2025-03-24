/*
There are N pots. Every pots has some water in it. They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required 
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    int stones = 0;

    cout<<"Enter the no.of pots available: ";
    cin>>N; cout<<endl;

    int *overflow = new int[N];

    for(int i = 0; i < N; i++) {
        cin>> overflow[i];
    }

    cout<< "Enter the no.of pots to be overflown: ";
    cin>>K; cout<<endl;

    sort(overflow, overflow + N);

    for(int i = N - 1; i > 0; i--) {
        overflow[i] = max(0, overflow[i] - overflow[i - 1]);
    }

    for(int i = 0; i < K; i++){
        stones = stones + overflow[i] * (N-i);
    }

    cout<<endl<<"Total Stones used: "<<stones;
    return 0;

}