#include<iostream>
#include<vector>
#include<algorithm>
int row, col;
double **mat;
using namespace std;

void print()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col+1; j++) {
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "---------" << endl;

	bool check = false;
	bool check2 = false;
	bool check3 = false;
	bool su = false;
	int *coll = new int[col + 1];
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + 1; j++) {
			if (mat[i][j] == 1) {
				coll[j + 1] = 1;
				count++;
				break;
			}
		}
	}
	vector<int> v;
	vector<int>v2;
	char al = 'a';
	char al2 = 'a';
	char al3 = 'a';
	for (int j = 0; j < col + 1; j++) {
		if (coll[j + 1] != 1)
			v.push_back(j + 1);
		if (coll[j + 1] == 1)
			v2.push_back(j + 1);
	}

	if (row < col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (mat[i][j] == 0 && mat[i][j + 1] == 0) {
					check = true;
					check2 = true;
				}
				else if (mat[i][j] == 0 && mat[i][j + 1] != 0) {
					check = true;
					check2 = false;
				}
				else if (mat[i][j] == 1) {
					check3 = true;
				}
				else if (mat[i][j] != 0) {
					check = false;
				}
			}

			if (check == true && check2 == false && check3 == false) {
				cout << "해가 없음" << endl;
				su = true;
				break;
			}
			else if(check == true && check2 == true && check3 == false) {
				cout << "해가 무수히 많음." << endl;
				for (int i = 0; i < v2.size(); i++) {
					cout << "x" << v2[i] << ": " << mat[i][col];
					for (int j = 0; j < v.size() - 1; j++) {
						if ((-1 * mat[i][v[j] - 1]) > 0)
							cout << "+" << -1 * mat[i][v[j] - 1] << al;
						else if ((-1 * mat[i][v[j] - 1]) < 0)
							cout << -1 * mat[i][v[j] - 1] << al;
						else
							continue;
						al++;
					}
					al3 = max(al3, al);
					al = 'a';
					cout << endl;
				}
				for (int i = 0; i < v.size() - 1; i++) {
					cout << "x" << v[i] << ": " << al2 << endl;
					if (al3 == al2)
						break;
					al2++;
				}
			}
			check = false;
			check2 = false;
			check3 = false;
		}
		
	}
	else if (row > col) {
		if (v2.size() < col) {
			cout << "해가 무수히 많습니다" << endl;
			su = true;
			for (int i = 0; i < v2.size(); i++) {
				cout << "x" << v2[i] << ": " << mat[i][col];
				for (int j = 0; j < v.size() - 1; j++) {
					if ((-1 * mat[i][v[j] - 1]) > 0)
						cout << "+" << -1 * mat[i][v[j] - 1] << al;
					else if ((-1 * mat[i][v[j] - 1]) < 0)
						cout << -1 * mat[i][v[j] - 1] << al;
					else
						continue;
					al++;
				}
				al3 = max(al3, al);
				al = 'a';
				cout << endl;
			}
			for (int i = 0; i < v.size() - 1; i++) {
				cout << "x" << v[i] << ": " << al2 << endl;
				if (al3 == al2)
					break;
				al2++;
			}
		}
		else {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (mat[i][j] == 0 && mat[i][j + 1] == 0) {
						check = true;
						check2 = true;
					}
					else if (mat[i][j] == 0 && mat[i][j + 1] != 0) {
						check = true;
						check2 = false;
					}
					else if (mat[i][j] == 1) {
						check3 = true;
					}
					else if (mat[i][j] != 0) {
						check = false;
					}
				}
				if (check == true && check2 == false && check3 == false) {
					cout << "해가 없음" << endl;
					su = true;
					break;
				}
				check = false;
				check2 = false;
				check3 = false;
			}

			if (su == false) {
				cout << "유일해를 가짐." << endl;
				for (int i = 0; i < col; i++) {
					cout << "x" << i + 1 << ": " << mat[i][col] << endl;
				}
			}
		}
	}
	else {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (mat[i][j] == 0 && mat[i][j + 1] == 0) {
					check = true;
					check2 = true;
				}
				else if (mat[i][j] == 0 && mat[i][j + 1] != 0) {
					check = true;
					check2 = false;
				}
				else if (mat[i][j] == 1) {
					check3 = true;
				}
				else if (mat[i][j] != 0) {
					check = false;
				}
			}
			if (check == true && check2 == true && check3 == false) {
				cout << "해가 무수히 많습니다" << endl;
				su = true;
				for (int i = 0; i < v2.size(); i++) {
					cout << "x" << v2[i] << ": " << mat[i][col];
					for (int j = 0; j < v.size() - 1; j++) {
						if ((-1 * mat[i][v[j] - 1]) > 0)
							cout << "+" << -1 * mat[i][v[j] - 1] << al;
						else if ((-1 * mat[i][v[j] - 1]) < 0)
							cout << -1 * mat[i][v[j] - 1] << al;
						else
							continue;
						al++;
					}
					al3 = max(al3, al);
					al = 'a';
					cout << endl;
				}
				for (int i = 0; i < v.size() - 1; i++) {
					cout << "x" << v[i] << ": " << al2 << endl;
					if (al3 == al2)
						break;
					al2++;
				}
				break;
			}
			else if (check == true && check2 == false && check3 == false) {
				cout << "해가 없음" << endl;
				su = true;
				break;
			}
			check = false;
			check2 = false;
			check3 = false;
		}
		if (su == false) {
			cout << "유일해를 가짐." << endl;
			for (int i = 0; i < row; i++) {
				cout << "x" << i + 1 << ": " << mat[i][col] << endl;
			}
		}
	}
}

void swap_row(int a, int b)
{
	double t;
	for (int i = 0; i < col+1; i++) {
		t = mat[a][i];
		mat[a][i] = mat[b][i];
		mat[b][i] = t;
	}
}

void make_one(int x, int y) {
	double va = mat[x][y];
	for (int i = 0; i < col+1; i++) {
		if (mat[x][i] == 0) continue;
		mat[x][i] /= va;
	}

	for (int i = 0; i < row; i++) {
		if (i == x) continue;
		double multi = mat[i][y] / mat[x][y];
		for (int j = 0; j < col+1; j++) {
			mat[i][j] -= multi * mat[x][j];
		}
	}
}
int main() {
	cout << "연립방정식의 갯수를 입력하시오: ";
	cin >> row;
	cout << "변수의 갯수를 입력하시오: ";
	cin>> col;
	mat = new double*[row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new double[col+1];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col+1; j++) {
			cin >> mat[i][j];
		}
	}
	//행렬 생성
	// (0,0)을 1로 만든다.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col+1; j++) {
			if (mat[i][j] != 0) {
				make_one(i, j);
				break;
			}
		}
	}
	int line = 0;
	int min = row < col+1 ? row : col+1; // row, col+1중 작은 값이 min

	for (int i = 0; i < min; i++) {
		if (mat[line][i] != 1) {
			int here = -1;
			// 같은 || 에서 다른 1찾기
			for (int j = line; j < row; j++) {
				if (mat[j][i] == 1) {
					here = j;
					break;
				}
			}
			if (here != -1) {
				swap_row(i, here);
				line++;
			}
		}
		else line++;
	}
	print();
}