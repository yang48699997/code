from collections import defaultdict, deque


class MaxFlow:
    def __init__(self, n):
        self.size = n
        self.graph = defaultdict(list)
        self.capacity = {}

    def add_edge(self, u, v, cap):
        self.graph[u].append(v)
        self.graph[v].append(u)
        self.capacity[(u, v)] = cap
        self.capacity[(v, u)] = 0

    def bfs(self, source, sink, parent):
        visited = [False] * self.size
        queue = deque([source])
        visited[source] = True

        while queue:
            u = queue.popleft()

            for v in self.graph[u]:
                if not visited[v] and self.capacity[(u, v)] > 0:
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u
                    if v == sink:
                        return True
        return False

    def edmonds_karp(self, source, sink):
        parent = [-1] * self.size
        max_flow = 0

        while self.bfs(source, sink, parent):
            path_flow = float('Inf')
            s = sink

            while s != source:
                path_flow = min(path_flow, self.capacity[(parent[s], s)])
                s = parent[s]

            v = sink
            while v != source:
                u = parent[v]
                self.capacity[(u, v)] -= path_flow
                self.capacity[(v, u)] += path_flow
                v = parent[v]

            max_flow += path_flow

        return max_flow


def max_party_value(n, k, tree1, tree2, cats):
    # 构建最大流图
    total_nodes = 2 * n + 2
    source = 0
    sink = total_nodes - 1

    max_flow = MaxFlow(total_nodes)

    # 超级源和狂欢猫之间的边
    for cat in cats:
        max_flow.add_edge(source, cat, 1)

    # 树1中的节点和超级汇之间的边
    for node in range(1, n + 1):
        max_flow.add_edge(node + n, sink, 1)

    # 树2中的节点和超级汇之间的边
    for node in range(1, n + 1):
        max_flow.add_edge(node + 2 * n, sink, 1)

    # 树1中的边
    for u, v, val in tree1:
        max_flow.add_edge(u, v, val)
        max_flow.add_edge(v, u, val)

    # 树2中的边
    for u, v, val in tree2:
        max_flow.add_edge(u + n, v + n, val)
        max_flow.add_edge(v + n, u + n, val)

    # 计算最大狂欢值
    return max_flow.edmonds_karp(source, sink)


# 示例输入
n = 4
k = 3
cats = [1, 2, 3]
tree1 = [(1, 2, 1), (2, 3, 2), (2, 4, 1)]
tree2 = [(2, 4, 1), (2, 3, 5), (1, 4, 1)]

# 计算最大狂欢值
result = max_party_value(n, k, tree1, tree2, cats)
print(result)  # 输出最大狂欢值
