#include <iostream>
#include <vector>


bool checkWon(std::vector<std::vector<int> > board) {
	// write code here
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][0] == board[i][1] == board[i][2] == 1
			|| board[0][i] == board[1][i] == board[2][i] == 1)
		{
			return true;
		}
	}

	if (board[0][0] == board[1][1] == board[2][2] == 1
		|| board[0][2] == board[1][1] == board[2][0] == 1)
		return true;
	return false;

}

int main()
{

	std::vector<std::vector<int> > board;
	board.resize(3);
	board[0].resize(3);
	board[1].resize(3);
	board[2].resize(3);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cin >> board[i][j];
		}
	}

	std::cout << checkWon(board) << std::endl;

	return 0;
}