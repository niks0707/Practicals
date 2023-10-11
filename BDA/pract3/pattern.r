n <- 5  # Number of rows

for (i in 1:n) {
  cat(paste(rep("*", i), collapse = " "), "\n")
}


cat("\n\n\n")



rows <- 5
cols <- 8

for (i in 1:rows) {
  if (i == 1 || i == rows) {
    cat(rep("*", cols), "\n")
  } else {
    cat("*", rep(" ", cols - 2), "*", "\n")
  }
}
