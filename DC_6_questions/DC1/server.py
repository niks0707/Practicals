import Pyro4

@Pyro4.expose
class MathOperations:
    def calculate_square_root(self, x):
        return x**0.5

    def calculate_square(self, x):
        return x**2

    def calculate_factorial(self, x):
        if x == 0:
            return 1
        else:
            return x * self.calculate_factorial(x-1)

# Create a Pyro4 daemon and register the MathOperations class
daemon = Pyro4.Daemon()
uri = daemon.register(MathOperations)

# Start the server
print("Server URI:", uri)
daemon.requestLoop()
