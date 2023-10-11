calculate <- function(score) {
  if (score >= 95) {
    return("A+")
  } else if (score >= 90) {
    return("A")
  } else if (score >= 85) {
    return("B+")
  } else if (score >= 80) {
    return("B")
  } else if (score >= 75) {
    return("C+")
  } else if (score >= 70) {
    return("C")
  } else if (score >= 65) {
    return("D+")
  } else if (score >= 60) {
    return("D")
  } else {
    return("F")
  }
}


score <- readline(prompt = "Enter student's score: ")
score <- as.numeric(score)


if (!is.na(score)) {
  grade <- calculate(score)
  cat("Student's grade:", grade, "\n")
} else {
  cat("Invalid input. Please enter a valid number.\n")
}
