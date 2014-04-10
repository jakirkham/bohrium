import util
if util.Benchmark().bohrium:
    import bohrium as np
else:
    import numpy as np
from bohrium.stdviews import D2P8, no_border

def jacobi_init(size):

    v    = np.arange(size)
    data = (v*(v[np.newaxis,:].T+2)+2)/size

    return data

def jacobi_fixed(data, iterations):

    active  = no_border(data, 1)
    g       = grid(data, 1)
    d       = diagonals(data, 1)
    fak     = 1./20

    for _ in xrange(iterations):
        active[:] = (4*sum(g) + sum(d))*fak

    return data

if __name__ == "__main__":
    """
    """
    B = util.Benchmark()
    (N, I) = B.size
    data = jacobi_init(N)
    data + 1   # Ensure that data is in the correct space.
    B.start()
    result = jacobi(data I)
    B.stop()
    B.pprint()
