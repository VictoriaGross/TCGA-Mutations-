import numpy as np 
import matplotlib.pyplot as plt 
import scipy.stats as sps 

def vz1(d, D, n): 
    X = np.random.rand(n, D)
    A1 = 1/np.sqrt(d) * np.random.randn(D, d)

    Y = np.matmul(X, A1)
    Z = [] 
    for i in range (n): 
        for j in range (i + 1, n): 
            Z.append(np.linalg.norm(Y[i] - Y[j])  / np.linalg.norm(X[i] - X[j]))
    return np.var(Z)
    
def vz2(d, D, n): 
    X = np.random.rand(n, D)
    A2 = 1/np.sqrt(d) * np.random.choice(np.array([-1, 0, 0, 0, 0, 1]), (D, d)) 
    
    Y = np.matmul(X, A2)
    Z = [] 
    for i in range (n): 
        for j in range (i + 1, n): 
            Z.append(np.linalg.norm(Y[i] - Y[j])  / np.linalg.norm(X[i] - X[j]))
    
    return np.var(Z)

n = 100 
D = 1000 
d = np.linspace(1, D, 1000)
Var1 = [vz1(int(i), D, n) for i in d]
Var2 = [vz2(int(i), D, n) for i in d]

plt.plot(d / D,Var1,'r',label="Loi normale")
plt.plot(d / D, Var2,"b",label="Loi discrete")
plt.xlabel("d/D")
plt.legend(loc='best')
plt.show()
