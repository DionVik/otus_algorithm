# Определение кратчайшего пути от заданной вершины - Алгоритм Дейкстры

def deikstra(vector: list, vertex):
    size = len(vector)
    max_s = len(vector[0])
    weight_full = find_max_weight(vector)
    ways = [weight_full] * size
    visited = [False] * size
    ways[vertex] = 0
    for j in range(0, size):
        min_vertex = get_min_vertex(ways, visited)
        for k in range(0, max_s):
            item = vector[min_vertex][k]
            if item == '-':
                continue
            nearby_vertex = item[0]
            edge_weight = item[1]
            if visited[nearby_vertex]:
                continue
            weight = ways[min_vertex] + edge_weight
            if weight < ways[nearby_vertex]:
                ways[nearby_vertex] = weight
        visited[min_vertex] = True
    return ways


def find_max_weight(array: list):
    w = 0
    size = len(array)
    max_s = len(array[0])
    for i in range(0, size):
        for j in range(0, max_s):
            if array[i][j] == '-':
                continue
            else:
                item = array[i][j]
                w += item[1]
    return w


def get_min_vertex(array: list, visited: list) -> int:
    min_vertex = -1
    size = len(array)
    for i in range(0, size):
        if visited[i]:
            continue
        if min_vertex == -1:
            min_vertex = i
        elif array[i] < array[min_vertex]:
            min_vertex = i
    return min_vertex


def main():
    vector = [
        [(1, 2), (2, 2), (4, 1), (6, 3)],
        [(0, 2), (2, 3), (3, 3), '-'],
        [(0, 2), (1, 3), '-', '-'],
        [(1, 3), (4, 2), '-', '-'],
        [(0, 1), (3, 2), (5, 4), '-'],
        [(4, 4), (6, 2), '-', '-'],
        [(0, 3), (5, 2), '-', '-']
    ]
    size = len(vector)
    for vertex in range(0, size):
        result = deikstra(vector, vertex)
        print(f"Минимальные пути для вершины {vertex}: {result}") 


if __name__ == "__main__":
    main()
