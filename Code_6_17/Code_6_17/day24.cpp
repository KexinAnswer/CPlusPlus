链接：https://www.nowcoder.com/questionTerminal/72a99e28381a407991f2c96d8cb238ab
来源：牛客网

小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6 * 6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6 * 6的矩阵board，其中每个元素为对应格子的礼物价值, 左上角为[0, 0], 请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
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

链接：https://www.nowcoder.com/questionTerminal/535df0770f0940f092ab77db0907e5c9
来源：牛客网

题目标题：

迷宫问题

题目描述：

定义一个二维数组： int maze[5][5] = { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, }; 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。

输入描述：

一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。

输出描述：

左上角到右下角的最短路径，格式如样例所示。

样式输入：

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

样式输出：

<0, 0><1, 0><2, 0><2, 1><2, 2><2, 3><2, 4><3, 4><4, 4>


#include<iostream>
#include<vector>
using namespace std;
int N, M; //分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳路径
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中

	if (i == N - 1 && j == M - 1) //判断是否到达终点
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
		MazeTrack(i, j + 1);
	maze[i][j] = 0; //恢复现场，设为未走
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
		MazeTrack(0, 0);//回溯寻找迷宫最短通路
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	}
	return 0;
}