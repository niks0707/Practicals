num <- 2

while (num <= 100) {
  is_prime <- TRUE
  
  if (num > 2) {
    for (i in 2:(sqrt(num))) {
      if (num %% i == 0) {
        is_prime <- FALSE
        break
      }
    }
  }
  
  if (is_prime) {
    cat(num, " ")
  }
  
  num <- num + 1
}
