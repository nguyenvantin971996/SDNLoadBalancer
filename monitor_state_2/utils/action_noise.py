import numpy as np

class OUActionNoise(object):
    """
    Python implementation of Ornstein-Uhlenbeck process for random noise generation
    """
    def __init__(self, mu, sigma = 0.1, theta=0.25, dt=1e-2, x_0 = None):
        self.theta = theta
        self.mu = mu
        self.sigma = np.ones(1) * sigma
        self.dt = dt
        self.x_p = np.zeros_like(self.mu) if x_0 is None else x_0

    def __call__(self):
        x = (self.x_p + self.theta * (self.mu - self.x_p) * self.dt
            + self.sigma * np.sqrt(self.dt) * np.random.normal(size=self.mu.shape))
        # noise dependent on past iterations
        self.x_p = x
        return x
    
class Add_Noise(object):
    """
    Python implementation of Ornstein-Uhlenbeck process for random noise generation
    """
    def __init__(self, mu, alpha=0.99, beta=1):
        self.mu = mu
        self.alpha = alpha
        self.beta = beta

    def __call__(self):
        coff = max(self.beta,0.1)
        x = coff*np.random.normal(0,0.1,size=self.mu.shape)
        # noise dependent on past iterations
        self.beta = self.alpha*self.beta
        return x
# noise = Add_Noise(mu=np.zeros(5))
# for i in range(1000):
#     print(noise())