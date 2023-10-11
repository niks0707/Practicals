# Simple Calculator in R

# Function to perform addition
add <- function(a, b) {
  return(a + b)
}

# Function to perform subtraction
subtract <- function(a, b) {
  return(a - b)
}

# Function to perform multiplication
multiply <- function(a, b) {
  return(a * b)
}

# Function to perform division
divide <- function(a, b) {
  if (b != 0) {
    return(a / b)
  } else {
    return("Cannot divide by zero!")
  }
}

# Main calculator function
calculator <- function() {
  cat("Simple Calculator\n")
  cat("1. Addition\n")
  cat("2. Subtraction\n")
  cat("3. Multiplication\n")
  cat("4. Division\n")
  
  choice <- as.integer(readline("Enter your choice (1/2/3/4): "))
  
  if (choice >= 1 && choice <= 4) {
    num1 <- as.numeric(readline("Enter first number: "))
    num2 <- as.numeric(readline("Enter second number: "))
    
    result <- switch(
      choice,
      "1" = add(num1, num2),
      "2" = subtract(num1, num2),
      "3" = multiply(num1, num2),
      "4" = divide(num1, num2)
    )
    
    cat("Result: ", result, "\n")
  } else {
    cat("Invalid choice!\n")
  }
}

# Run the calculator
calculator()

