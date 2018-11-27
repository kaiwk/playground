#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// struct Con {
//     int luck;
//     int imp;
//     Con(int l, int i):luck(l), imp(i) {}
//     bool operator<(const Con &con) const {
// 	return this->luck > con.luck;
//     }
// };

// int L, K;
// vector<Con> vec;

// int main() {
//     freopen("input", "r", stdin);

//     cin >> L >> K;

//     int luck, imp;
//     for(int i = 0; i < L; ++i){
// 	cin >> luck >> imp;
// 	vec.push_back(Con(luck, imp));
//     }
//     sort(vec.begin(), vec.end());

//     int savedLuck = 0;
//     int loseImp = 0;
//     for(int i = 0; i < L; ++i) {
// 	if ((vec[i].imp == 1 && loseImp < K) || vec[i].imp == 0) savedLuck += vec[i].luck;
// 	if(vec[i].imp == 1 && loseImp >= K) savedLuck -= vec[i].luck;
// 	if (vec[i].imp == 1) ++loseImp;
//     }

//     cout << savedLuck << endl;

//     return 0;
// }

int L, K;
vector<pair<int, int> > vec;
int main() {
    freopen("input", "r", stdin);
    cin >> L >> K;
    int luck, imp;
    for (int i = 0; i < L; ++i){
	cin >> luck >> imp;
	vec.push_back(make_pair(luck, imp));
    }
    sort(vec.begin(), vec.end(), greater<pair<int,int> >());

    int savedLuck = 0;
    int loseImp = 0;
    for (int i = 0; i < L; ++i) {
	if((vec[i].second == 1 && loseImp < K) || vec[i].second == 0) savedLuck += vec[i].first;
	if(vec[i].second == 1 && loseImp >= K) savedLuck -= vec[i].first;
	if(vec[i].second == 1) ++loseImp;
    }
    cout << savedLuck << endl;
}
