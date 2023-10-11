# Creating a list
my_list <- list(
  Name = "Nikhil",
  Age = 22,
  Scores = c(85, 90, 78),
  Contacts = c("someone@hmail.com", "9999999999")
)

# Accessing elements
name <- my_list$Name
age <- my_list$Age
scores <- my_list$Scores

# Printing the list and elements
print(my_list)
print(name)
print(age)
print(scores)

# Adding elements
my_list$Location <- "Cityville"
print(my_list)


# Lists in R and Operations:
# A list is a versatile data structure in R that can hold elements of different types, including other lists. It is similar to a vector, but elements can be of different types and lengths. Lists are commonly used to store collections of data or objects.