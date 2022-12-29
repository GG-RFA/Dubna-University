import random

class gramm:
    __rules=[]

    def add_rule(self, S):
        self.__rules.append(S)

    def look(self):
        return self.__rules

    def deduct(self, L, n):
        while (n!=0):
            r=random.randint(0, len(self.__rules)-1)
            st=self.__rules[r]
            if L.find(st[0])!=-1:
                print(st)
                L=L.replace(st[0],st[1])
            n-=1
        return L

A=gramm()
A.add_rule(["Q1", "n"])
A.add_rule(["Q2", "Q1b"])
A.add_rule(["Q3", "Q1s"])
A.add_rule(["Q3", "Q2s"])
A.add_rule(["Q3", "Q3b"])
A.add_rule(["Q4", "Q2m"])
A.add_rule(["Q4", "Q3m"])
A.add_rule(["S", "Q4g"])
A.add_rule(["Q1", "Sa"])
A.add_rule(["S", ""])
A.add_rule(["Q0", "Sf"])
A.add_rule(["Q0", "Q1f"])