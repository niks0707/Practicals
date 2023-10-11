import Pyro4

# Replace 'SERVER_URI' with the actual URI of your server
SERVER_URI = "PYRO:obj_c1aebfd1ba804d16858f3b48942e8dba@localhost:51047"

# Create a Pyro4 proxy to access the remote MathOperations object
math_operations = Pyro4.Proxy(SERVER_URI)

a = int(input("Enter the number to perform Sqrt, Sqr, Factorial : "))
b = int(input("Enter Operation: 1 - Sqrt, 2 - Sqr, 3 - Factorial : "))

if b == 1:
    result_sqrt = math_operations.calculate_square_root(a)
    print(f"Square root of ", a, "-", result_sqrt)

elif b == 2:
    result_square = math_operations.calculate_square(a)
    print(f"Square of ", a, "-", result_square)

elif b == 3:
    result_fact = math_operations.calculate_factorial(a)
    print(f"Factorial of ", a, "-", result_fact)

else:
    print("Invalid Operation.")

# Invoke remote methods
# result_sqrt = math_operations.calculate_square_root(9)
# result_square = math_operations.calculate_square(5)
# result_fact = math_operations.calculate_factorial(5)

# print(f"Square root of 9: {result_sqrt}")
# print(f"Square of 5: {result_square}")
# print(f"Factorial of 5: {result_fact}")

