#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/** ������������������ʵ����ĿҪ��Ĺ��� **/
/** ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^  **/
vector < int > Joint(int n, vector < vector < int > > edges) {


}

int main() {
	vector < int > res;

	int _n;
	cin >> _n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector< vector < int > > _edges;
	for (int i = 0; i < _n; ++i) {
		_edges.push_back(vector<int>());
		for (int j = 0; j < _n; ++j) {
			_edges.back().push_back(0);
		}
	}
	int _m = 0;
	cin >> _m;
	for (int i = 0; i < _m; ++i) {
		int a = 0;
		int b = 0;
		vector[a][b] = 1;
		vector[b][a] = 1;
	}

	res = Joint(_n, _edges);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << ' ';
	}
	cout << endl;

	return 0;

}