#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>


using namespace std;

struct IS{
    IS(){
        id = 0;
        isShown = true;
    }
    int id;
    string s;
    bool isShown;
};

int n;
IS is[1000000];

// insertion sort for 'stable sort', but low performance
void my_sort(IS is[], int n){
    IS target;
    int index;
    for(int i = 1; i < n; ++i){
        target = is[i];
        index = i;
        while(index > 0 && target.id < is[index-1].id){
            is[index] = is[index-1];
            --index;
        }
        is[index] = target;
    }
}

// sort rule
bool cmp(IS a, IS b){
    return a.id < b.id;
}

int main(){

    freopen("input", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> is[i].id >> is[i].s;
        if (i < n/2) {
            is[i].isShown = false;
        }
    }

    stable_sort(is, is+n, cmp);


    for(int i = 0; i < n; ++i){
    	if (is[i].isShown) {
    	    cout << is[i].s << " ";
    	}else{
            cout << "- ";
        }
    }

    cout << endl;

    return 0;
}
