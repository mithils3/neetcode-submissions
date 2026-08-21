class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        self.clones = {}
        return self.dfs(node)

    def dfs(self, node):
        if node in self.clones:          # ← the missing base case
            return self.clones[node]
        copy = Node(val=node.val)
        self.clones[node] = copy         # register BEFORE recursing
        for n in node.neighbors:
            copy.neighbors.append(self.dfs(n))
        return copy