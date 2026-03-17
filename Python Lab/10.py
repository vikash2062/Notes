import pandas as pd
from sklearn.preprocessing import StandardScaler

# Load the dataset
df = pd.read_csv('sales_data.csv')

# Check original values
print("Original:\n", df[['Revenue', 'Profit']].head())

# Create a StandardScaler object
scaler = StandardScaler()

# Apply Z-score standardization
df[['Revenue', 'Profit']] = scaler.fit_transform(df[['Revenue', 'Profit']])

# Check the transformed values
print("\nAfter Z-Score Standardization:\n", df[['Revenue', 'Profit']].head())
