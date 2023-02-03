#!/usr/bin/python3

class MRUQueue:
    q = []

    def __init__(self, n: int):
        self.q.clear()
        for i in range(n):
            self.q.append(i + 1)

    def fetch(self, k: int) -> int:
        e = self.q[k - 1]
        self.q.remove(e)
        self.q.append(e)
        return e


obj = MRUQueue(3)
print(f"{obj.fetch(2)}")
print(f"{obj.fetch(1)}")
print(f"{obj.fetch(2)}")
print(f"{obj.fetch(2)}")
print(f"{obj.fetch(2)}")
print(f"{obj.fetch(3)}")
print(f"{obj.fetch(2)}")
print(f"{obj.fetch(1)}")
print(f"{obj.fetch(1)}")
print(f"{obj.fetch(2)}")
