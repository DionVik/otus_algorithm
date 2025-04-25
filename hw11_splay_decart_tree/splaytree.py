# Реализация Splay дерева поиска

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
            return node
        if current == None:
            current = self.root
        if key < current.key:
            if current.left == None:
                current.left = node
            else:
                return self.insert(key, current.left)
        if key > current.key:
            if current.right == None:
                current.right = node
            else:
                return self.insert(key, current.right)
        return node
        
    def MinRightRotate(self, a):
        b = a.left
        a.left = b.right
        b.right = a
        if self.root == a:
            self.root = b
        return b
        
    def MinLeftRotate(self, a):
        b = a.right
        a.right = b.left
        b.left = a
        if self.root == a:
            self.root = b
        return b
        
    def splay_insert(self, key):
        breakpoint()
        curr = self.insert(key=key)
        parent = self.search_parent(curr, self.root)
        while parent != None:
            grand = self.search_parent(parent, self.root)
            if curr == parent.left:
                node = self.MinRightRotate(parent)
                if grand:
                    if grand.left == parent:
                        grand.left = node
                    else:
                        grand.right = node
            else:
                node = self.MinLeftRotate(parent)
                if grand:
                    if grand.left == parent:
                        grand.left = node
                    else:
                        grand.right = node
            parent = grand
            
            
    def print_tree(self, n):
        if n == None:
            return
        self.print_tree(n.left)
        print(f"{n} key = {n.key}, left = {n.left}, right = {n.right}")
        self.print_tree(n.right)
        return
    
    
    def search(self, key, node=None):
        if self.root == None:
            return None
        if node == None:
            node = self.root
        searched = False
        self.print_tree(self.root)
        while not searched:
            if key == node.key:
                searched = True
                print(f"key={key} == {node.key}")
                break
            if key < node.key:
                print(f"key={key} < {node.key}")
                if node.left:
                    node = node.left
                    print(f"node={node} = {node.left}")
                else:
                    break
            else:
                if node.right:
                    print(f"key={key} > {node.key}")
                    node = node.right
                    print(f"node={node} = {node.right}")
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
    A = [8, 16, 3, 4, 12]    
    print(A)
    tree3 = Tree()
    for i in A:
        tree3.splay_insert(i)
        tree3.print_tree(tree3.root)
    
    
if __name__ == "__main__":
    main()
        
        



            



    
