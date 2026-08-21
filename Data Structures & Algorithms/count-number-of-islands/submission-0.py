class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.nodes = Counter()
        self.island = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    self.nodes.update([(i, j)])
        self.rows, self.cols = len(grid), len(grid[0])
        while self.nodes:
            first_key = next(iter(self.nodes))
            self.nodes.pop(first_key)
            self.bfs(first_key)
        return self.island

    def bfs(self, start):
        q = deque([start])
        seen = {start}
        while q:
            r, c = q.popleft()
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < self.rows and 0 <= nc < self.cols and (nr, nc) not in seen and (nr, nc) in self.nodes:
                    q.append((nr, nc))
                    seen.add((nr, nc))
                    self.nodes.pop((nr, nc))
        self.island += 1