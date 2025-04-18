# Реализация двоичного дерева поиска. Уровень Junior

import random
from datetime import datetime


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        
class Tree:
    def __init__(self):
        self.root = None
    
    
    def insert(self, key, current=None):
        node = Node(key)
        if self.root == None:
            self.root = node
            return
        if current == None:
            current = self.root
        if key < current.key:
            if current.left == None:
                current.left = node
            else:
                self.insert(key, current.left)
            return
        if key > current.key:
            if current.right == None:
                current.right = node
            else:
                self.insert(key, current.right)
            return
    
    
    def print_tree(self, n):
        if n == None:
            return
        self.print_tree(n.left)
        print(f"{n} key = {n.key}, left = {n.left}, right = {n.right}")
        self.print_tree(n.right)
        return
    
    # вариант из презентации - не верен!
    # def search(self, key, node=None):
        # if self.root == None:
            # return None
        # if node == None:
            # node = self.root
        # if key == node.key:
            # return node
        # if key < node.key:
            # return self.search(key, node.left)
        # else:
            # return self.search(key, node.right)
    
    
    def search(self, key, node=None):
        if self.root == None:
            return None
        if node == None:
            node = self.root
        searched = False
        while not searched:
            if key == node.key:
                searched = True
                break
            if key < node.key:
                if node.left:
                    node = node.left
                else:
                    break
            else:
                if node.right:
                    node = node.right
                else:
                    break
        if searched:
            return node
        return None
                    
                    
    def remove(self, key):
        node = self.search(key)
        if node:
            self.remove_node(node)
        else:
            return 0
    
    
    def remove_node(self, node):
        parent = self.search_parent(node, self.root)
        if node.right == None:
            if parent != None:
                if parent.left == node:
                    parent.left = node.left
                else:
                    parent.right = node.left
            else:
                root = node.left
            return 0
        else:
            right_min = node.right
            right_min_parent = node
            while right_min.left != None:
                right_min_parent = right_min
                right_min = right_min.left
            if parent != None:
                if parent.left == node:
                    parent.left = right_min
                parent.right = right_min
            else:
                root = right_min
            if right_min != node.right:
                right_min_parent.left = right_min.right
                right_min.right = node.right
            right_min.left = node.left
            
    
    
    def search_parent(self, node, search):
        # search - узел, с которого начинаем искать родителя узла node
        if search == None:
            return None
        if node == None:
            return None
        if node.key == search.key: # у узла node нет родителя
            return None
        if search.left != None:
            if (node.key == search.left.key):
                return search
        if search.right != None:
            if node.key == search.right.key:
                return search
        if node.key < search.key:
            return self.search_parent(node, search.left)
        return self.search_parent(node, search.right)
        
        
def main():
    max_size = 100
    arr_a = [random.randint(0, 99) for i in range(0, max_size)]
    arr_b = [i for i in range(0, max_size)]
    tree1 = Tree()
    tree2 = Tree()
    for i in arr_a:
        tree1.insert(i)
    for j in arr_b:
        tree2.insert(j)
    
    keys = [random.randint(0, 99) for i in range(0, max_size//10)]
    # Поиск max_size / 10 случайных чисел
    start = datetime.now()
    for key in keys:
        node = tree1.search(key)
    end = datetime.now()
    tdelta = end - start
    print(f"Поиск {len(keys)} чисел в произвольном массиве из {max_size} элементов занял {tdelta.microseconds} мкc")  
    
    start = datetime.now()
    for key in keys:
        node = tree2.search(key)
    end = datetime.now()
    tdelta = end - start
    print(f"Поиск {max_size//10} чисел в упорядоченном массиве из {max_size} элементов занял {tdelta.microseconds} мкc")  
    
    # Удаление max_size / 10 случайных чисел
    start = datetime.now()
    for key in keys:
        tree1.remove(key)
    end = datetime.now()
    tdelta = end - start
    print(f"Удаление {len(keys)} чисел из произвольного массива из {max_size} элементов заняло {tdelta.microseconds} мкc")  
    
    start = datetime.now()
    for key in keys:
        tree2.remove(key)
    end = datetime.now()
    tdelta = end - start
    print(f"Удаление {len(keys)} чисел из упорядоченного массива из {max_size} элементов заняло {tdelta.microseconds} мкc")  
    
if __name__ == "__main__":
    main()
        
        



            



    
