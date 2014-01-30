import argparse
import os

def sample(args):
    if args.be == 'bohrium':
        import bohrium as np
    elif args.be == 'numpy':
        import numpy as np

    """
    #a = np.arange(sum(args.shape), dtype=np.float32)
    #a = np.random.random(args.shape, dtype=np.float32)
    a = np.ones(args.shape, dtype=np.float32)
    for _ in range(args.iterations[0]):
        b = np.sin(a)
        c = np.cos(b)
        d = np.absolute(c)
    print d
    #return d
    """
    a = np.arange(np.prod(args.shape)).reshape(args.shape)

    b = np.sum(a[::2])

    return a, b

def main():
    p = argparse.ArgumentParser('Run a dummy program')
    p.add_argument(
        'shape', metavar='N', type=int,
        nargs='+', help="Shape of the input."
    )
    p.add_argument(
        'iterations', metavar='I', type=int,
        nargs=1, help="Number of iterations to run."
    )
    p.add_argument(
        '--be', choices=['bohrium', 'numpy'], default='bohrium',
        help="The backend to use"
    )
    args = p.parse_args()

    print sample(args)

if __name__ == "__main__":
    main()
