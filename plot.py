import imageio
import numpy as np
import matplotlib.pyplot as plt
images = []
x=np.arange(0,1,0.01)
for i in range(200):
    eq = plt.figure()
    plt.plot(x, np.loadtxt("eq.dat")[i])
    plt.savefig("eq"+ str(i) + ".png")
    plt.close(eq)
for i in range(200):
    images.append(imageio.imread("eq"+ str(i) + ".png"))
imageio.mimsave("movie.gif", images)
