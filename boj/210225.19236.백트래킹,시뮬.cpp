#include <stdio.h>

struct FISH {
	int y, x;
	int dir;
};

const int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dx[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };

int ret;

void solve(int board[4][4], FISH fish[], int shark_y, int shark_x, int sum) {
	int candi_board[4][4];
	FISH candi_fish[16];
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			candi_board[y][x] = board[y][x];
		}
	}
	for (int i = 0; i < 16; ++i) {
		candi_fish[i] = fish[i];
	}

	//eat
	int fish_number = candi_board[shark_y][shark_x];
	int shark_dir = candi_fish[fish_number].dir;
	candi_fish[fish_number].y = -1;
	candi_fish[fish_number].x = -1;
	candi_fish[fish_number].dir = -1;
	candi_board[shark_y][shark_x] = -1;

	sum += (fish_number + 1);
	if (ret < sum) {
		ret = sum;
	}

	//fish move
	for (int f = 0; f < 16; ++f) {
		if (candi_fish[f].y == -1) {
			continue;
		}
		int cy = candi_fish[f].y;
		int cx = candi_fish[f].x;
		int cd = candi_fish[f].dir;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd;
		while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}

		if (candi_board[ny][nx] != -1) {
			int target = candi_board[ny][nx];
			candi_fish[target].y = cy;
			candi_fish[target].x = cx;
			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			candi_board[ny][nx] = f;
			candi_board[cy][cx] = target;
		}
		else {
			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			candi_board[ny][nx] = f;
			candi_board[cy][cx] = -1;
		}
	}

	//shark move
	for (int step = 1; step < 4; ++step) {
		int ny = shark_y + dy[shark_dir] * step;
		int nx = shark_x + dx[shark_dir] * step;
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
			break;
		}
		if (candi_board[ny][nx] != -1) {
			solve(candi_board, candi_fish, ny, nx, sum);
		}
	}
}

int main()
{
	FISH fish[16];
	int board[4][4];
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			fish[a].y = y;
			fish[a].x = x;
			fish[a].dir = b;
			board[y][x] = a;
		}
	}
	ret = 0;
	solve(board, fish, 0, 0, 0);
	printf("%d\n", ret);
	return 0;
}