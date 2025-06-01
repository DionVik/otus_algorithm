# Определение минимального остовного дерева - Алгоритм Краскала
class Edge:
    def __init__(self, begin:int, end: int, weight: int):
        self.begin = begin
        self.end = end
        self.weight = weight


def cruscal(vector: list):
    edges = []
    parent = []
    result = []
    size = len(vector)
    for i in range(0, size):
        for j in range(0, len(vector[i])):
            if vector[i][j] == '-':
                continue
            else:
                item = vector[i][j]
                edge = Edge(begin=i, end=item[0], weight=item[1])
                edges.append(edge)
    sort_edges(edges)
    for i in range(0, size):
        parent.append(i)
    for edge in edges:
        begin_parent = get_parent(parent, edge.begin)
        end_parent = get_parent(parent, edge.end)
        if begin_parent == end_parent:
            continue
        result.append(edge)
        parent[end_parent] = begin_parent
    return result


def sort_edges(edges: list):
    size = len(edges)
    for i in range(0, size):
        pos_min = i
        for j in range(i + 1, size):
            if edges[j].weight < edges[pos_min].weight:
                pos_min = j
        edges[i], edges[pos_min] = edges[pos_min], edges[i]


def get_parent(parent: list, v: int):
    if parent[v] == v:
        return v
    return get_parent(parent, parent[v])


def main():
    vector = [
        [(1, 2), (2, 2), (4, 1)],
        [(0, 2), (2, 3), (3, 3)],
        [(0, 2), (1, 3), '-'],
        [(1, 3), (4, 2), '-'],
        [(0, 1), (3, 2), (5, 4)],
        [(4, 4), (6, 2), '-'],
        [(0, 3), (5, 2), '-']
    ]
    result = cruscal(vector)
    min_weight = 0
    for i in result:
        print(f"{i.begin} - {i.end}: {i.weight}")
        min_weight = min_weight + i.weight
    print(f"Вес рёбер минимального остовного дерева: {min_weight}")
    
if __name__ == "__main__":
    main()
