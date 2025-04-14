#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names;
    names.push_back("daniel");
    
    for(int i = 0; i < names.size(); i++) {
        cout<<names[i];
    }
}