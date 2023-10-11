# Create a matrix
matrix_data <- matrix(1:12, nrow = 3)
print(matrix_data)
cat("\n\n")

# Apply sum() function to each row
row_sums <- apply(matrix_data, 1, sum)
print(row_sums)

cat("\n\n")

# Apply sum() function to each column and simplify the result
col_sums <- sapply(matrix_data, sum)
print(col_sums)


cat("\n\n")


scores <- c(85, 92, 78, 95, 88, 72)
subjects <- c("Math", "Science", "Math", "Science", "Math", "Science")

# Apply mean() function to scores based on subjects
mean_scores_by_subject <- tapply(scores, subjects, mean)
print(mean_scores_by_subject)