# Creating a DataFrame
data <- data.frame(
  Name = c("Stud1", "Stud2", "Stud3"),
  Age = c(25, 30, 28),
  Score = c(90, 85, 92)
)

# Accessing columns
ages <- data$Age

# Printing the DataFrame and result
print(data)
print(ages)

# Filtering rows
young_people <- data[data$Age < 30, ]
print(young_people)



# R Dataframes and Operations:
# A DataFrame is a two-dimensional tabular data structure in R, similar to a spreadsheet or a database table. It consists of rows and columns, where each column can hold data of different types. DataFrames are widely used for data manipulation, analysis, and visualization.