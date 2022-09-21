#include <stdio.h>

long long int KadaneAlgorithm(long long int arr[], long long int n) {
    long long int temp = arr[0];
    long long int maxSum = arr[0];

    for(long long int i=1; i<n; i++){
        if(arr[i] > arr[i] + temp){
            temp = arr[i];
        } 
        else temp += arr[i];

        if(temp >= maxSum){
            maxSum = temp;
        }
    }

    return maxSum;
}

int main() {
    long long int n;
    scanf("%lld", &n);

    long long int array[n];
    for(long long int i=0; i<n; i++){
    	scanf("%lld", &array[i]);
    }

    long long int res = KadaneAlgorithm(array, n);
    printf("%lld\n", res);

    return 0;
}
