���ӣ�https://www.nowcoder.com/questionTerminal/72a99e28381a407991f2c96d8cb238ab
��Դ��ţ����

С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6 * 6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6 * 6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ, ���Ͻ�Ϊ[0, 0], �뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int dp[6][6];
		dp[0][0] = board[0][0];

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
			{
				if (!j && !i)
					continue;
				else
					dp[i][j] = max((j == 0) ? 0 : dp[i][j - 1], (i == 0) ? 0 : dp[i - 1][j]) + board[i][j];

			}
		return dp[5][5];
	}
};

���ӣ�https://www.nowcoder.com/questionTerminal/535df0770f0940f092ab77db0907e5c9
��Դ��ţ����

��Ŀ���⣺

�Թ�����

��Ŀ������

����һ����ά���飺 int maze[5][5] = { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, }; ����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�

����������

һ��5 �� 5�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ�⡣

���������

���Ͻǵ����½ǵ����·������ʽ��������ʾ��

��ʽ���룺

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

��ʽ�����

<0, 0><1, 0><2, 0><2, 1><2, 2><2, 3><2, 4><3, 4><4, 4>


#include<iostream>
#include<vector>
using namespace std;
int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����

	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0; //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
}

int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
			for (auto &j : i)
				cin >> j;
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	return 0;
}