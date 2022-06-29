class auto:
    __q=[]
    __abc=[]
    __q0=None
    __f=[]
    __delta=[]
    __condition=None
    
    def __init__(self,Q,ABC,DELTA,Q0,F):
        self.__q=Q
        self.__abc=ABC
        self.__delta=DELTA
        self.__q0=Q0
        self.__f=F
        self.__condition=Q0
    def get_q(self):
        return self.__q
    def get_abc(self):
        return self.__abc
    def get_q0(self):
        return self.__q0
    def get_f(self):
        return self.__f
    def get_delta(self):
        return self.__delta
    def get_condition(self):
        return self.__condition
    
    def work(self,L):
        self.__condition=self.__q0
        for i in L:
            if not(i in self.__abc):
                print("Строка содержит недопустимый символ алфавита: "+i)
                return False
            p=False
            for j in self.__delta:
                if (self.__condition==j[0]) & (i == j[1]):
                    self.__condition=j[2]
                    p=True
                    break
            if not(p):
                print("Для символа "+i+" подходящее правило не найдено")
                return False
        if self.__condition in self.__f:
            return True
        else:
            return False