import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

def graph_scatter_points(x, y):
        plt.plot(x, y, linewidth=1)


df = pd.read_csv("results.csv")
X = np.arange(10, 1000000, 1000)
Y1 = df["discrete"].to_numpy()
Y2 = df["segment"].to_numpy()
Y3 = df["set"].to_numpy()
Y4 = df["expectdiscrete"].to_numpy()
Y5 = df["expectsegment"].to_numpy()
Y6 = df["expectset"].to_numpy()
plt.xlabel('кол-во повторений', loc='right')
plt.ylabel('Экспериментальная вероятность', loc='top')
graph_scatter_points(X, Y1)
graph_scatter_points(X, Y2)
graph_scatter_points(X, Y3)
plt.show()
