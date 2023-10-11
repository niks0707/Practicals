# Install and load necessary packages if not already installed
if (!requireNamespace("readr", quietly = TRUE)) {
  install.packages("readr")
}
if (!requireNamespace("readxl", quietly = TRUE)) {
  install.packages("readxl")
}
if (!requireNamespace("haven", quietly = TRUE)) {
  install.packages("haven")
}
if (!requireNamespace("foreign", quietly = TRUE)) {
  install.packages("foreign")
}


# Load the required packages
library(readr)
library(readxl)
library(haven)
library(foreign)

# Import data from CSV
csv_data <- read_csv("data.csv")
print(csv_data)

# Import data from Excel
excel_data <- read_excel("data.xlsx")
print(excel_data)

# Import data from SPSS
spss_data <- haven::read_sav("data.sav")
print(spss_data)

# Import data from Stata
stata_data <- haven::read_dta("data.DTA")
print(stata_data)

# Import data from SAS
sas_data <- read_sas("data.sas7bdat")
print(sas_data)

# Example: Display the first few rows of each dataset
head(csv_data)
head(excel_data)
head(spss_data)
head(stata_data)
head(sas_data)



#Operations

# Load the necessary 'dplyr' package if not already installed
if (!requireNamespace("dplyr", quietly = TRUE)) {
  install.packages("dplyr")
}

filtered_data <- csv_data %>%
  filter(salary > 600)

print(filtered_data)


arranged_data <- csv_data %>%
  arrange(start_date)

print(arranged_data)


selected_data <- csv_data %>%
  select(name, dept)

print(selected_data)


