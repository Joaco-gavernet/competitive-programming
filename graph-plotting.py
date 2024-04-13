import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

# Create a graph
adjacency_list = [
    [1, 6],
    [1, 7],
    [5, 3],
    [3, 6],
    [7, 3],
    [3, 2],
    [2, 4],
    [8, 2],
    [8, 4],
]
A = np.matrix(adjacency_list)
G = nx.from_numpy_matrix(A)

# Draw the graph
nx.draw(G)
plt.show()
