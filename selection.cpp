#include <stdexcept>
#include "selection.h"

using namespace std;

int select(size_t k, const int* list, size_t N) {
    if((k>N)||(k<1)){
        throw std::invalid_argument("k is out of bounds");
    }
    else{
        int* arr = new int[N];
        int ret;//value that will be returned
        for(size_t i=0; i<N; i+= 1){//copy original list into array
            arr[i]=list[i];
        }
        for(size_t i=0; i<N-1; i+= 1){//bubble sort
            for(size_t j=0; j<N-i-1; j+= 1){
                if(arr[j]<arr[j+1]){
                    arr[j]=arr[j]+arr[j+1];
                    arr[j+1]=arr[j]-arr[j+1];
                    arr[j]=arr[j]-arr[j+1];
                }
            }
        }
        ret = arr[k-1];//saves kth smallest number
        delete [] arr;
        return ret;
    }
}
