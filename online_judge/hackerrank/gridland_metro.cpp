#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void solution1() {

    long n, m;
    int k;
    long all_track = 0;

    map<int, vector<pair<long, long> > > trackMap;

    freopen("input", "r", stdin);
    cin >> n >> m >> k;
    long row = 0, c1 = 0, c2 = 0;
    for(int i = 0; i < k; ++i) {
	cin >> row >> c1 >> c2;
	map<int, vector<pair<long, long> > >::iterator tempp = trackMap.find(row);
	if (tempp != trackMap.end()) {
	    vector<pair<long, long> > &vec = tempp->second;
	    for(vector<pair<long, long> >::size_type i = 0; i < vec.size(); ++i){
		long tempc1 = vec[i].first;
		long tempc2 = vec[i].second;
		if (tempc2 < c1 || c2 < tempc1) {
		    vec.push_back(make_pair(c1, c2));
		} else {
		    vec[i].first = min(tempc1, c1);
		    vec[i].second = max(tempc2, c2);
		}
	    }
	} else {
	    vector<pair<long, long> > vec;
	    vec.push_back(make_pair(c1, c2));
	    trackMap[row] = vec;
	}
    }

    for(map<int, vector<pair<long, long> > >::iterator iter = trackMap.begin(); iter != trackMap.end(); ++iter){
	vector<pair<long, long> > vec = iter->second;
	for(vector<pair<long, long> >::iterator viter = vec.begin(); viter != vec.end(); ++viter){
	    all_track += (viter->second - viter->first + 1);
	}
    }
    long res = n * m - all_track;
    cout << res << endl;
}

// better way
void solution2() {

    freopen("input", "r", stdin);

    long n, m;
    int k;
    long all_track = 0;
    map<long, long> mp;
    vector<pair<long, long> > vec[1003];

    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
	long row, c1, c2;
	cin >> row >> c1 >> c2;
	if (mp.find(row) == mp.end())
	    mp[row] = mp.size();
	vec[mp[row]].push_back(make_pair(c1, c2));
    }

    int rsize = mp.size();
    for (int i = 1; i <= rsize; ++i)
	sort(vec[i].begin(), vec[i].end());

    for (int i = 1; i <= rsize; ++i) {
	long p = 0;
	int vsize = vec[i].size();
	for(int j = 0; j < vsize; ++j) {
	    if (vec[i][j].first <= p) {
		long temp = vec[i][j].second - p;
		if (temp > 0) all_track += temp;
	    } else {
		all_track += (vec[i][j].second - vec[i][j].first + 1);
	    }
	    p = max(p, vec[i][j].second);
	}
    }
    long res = n * m - all_track;
    cout << res << endl;
}

int main() {
    solution2();
    return 0;
}
