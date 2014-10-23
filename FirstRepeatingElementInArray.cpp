#include <map>
#include <iostream>
#include <utility>
#include <climits>

using namespace std;

int main(){
  map<int,int> hash;
  int arr[] = {10, 5, 3, 4, 3, 5, 6};
  int res = 0;
  int index = INT_MAX;
  int len = sizeof(arr)/sizeof(arr[0]);
  for(int i =0; i < len; i++) {
    if(hash.find(arr[i]) != hash.end()){
      if(hash[arr[i]] < index) {
        index = hash[arr[i]];
        res = arr[i];
      }
      continue;
    }
    else{
      hash.insert(make_pair(arr[i],i));
    }
  }
  cout<<"The element is "<<res<<endl;
}
