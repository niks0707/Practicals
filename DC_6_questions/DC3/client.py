import Pyro4

# Replace 'SERVER_URI' with the actual URI of your server
SERVER_URI = "PYRO:obj_25d9ce8116854d1caafff212a7a62ddf@localhost:50968"

# Create a Pyro4 proxy to access the remote MathOperations object
string_operations = Pyro4.Proxy(SERVER_URI)

print("What you Want to do?")
print("1 for String Comparison, 2 for String Length :", end = " ")
a = int(input())

if(a == 1):
    str1 = input("Enter String 1 : ")
    str2 = input("Enter String 2 : ")
    print("String comparison is : ", string_operations.compare_strings(str1, str2))
elif(a == 2):
    str3 = input("Enter String : ")
    print("String Length is : ", string_operations.count_characters(str3))
else:
    print("Invalid Choice.")





# if __name__ == "__main__":
#     with Pyro4.Proxy("PYRO:StringOperations@localhost:50000") as string_operations:
#         str1 = "Hello, World!"
#         str2 = "Hello, Python!"
#         result = string_operations.compare_strings(str1, str2)
#         print(f"Are the strings equal? {result}")

#         string = "Distributed Computing"
#         count = string_operations.count_characters(string)
#         print(f"Character count in '{string}': {count}")
