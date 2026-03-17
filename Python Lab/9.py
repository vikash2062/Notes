import pandas as pd
from sklearn.preprocessing import MinMaxScaler

# Load the dataset
df = pd.read_csv('Book1.csv')

# Check original values
print("Original:\n", df[['Revenue', 'Profit']].head())

# Create a scaler object
scaler = MinMaxScaler()

# Apply Min-Max scaling
df[['Revenue', 'Profit']] = scaler.fit_transform(df[['Revenue', 'Profit']])

# Check the transformed values
print("\nAfter Min-Max Scaling:\n", df[['Revenue', 'Profit']].head())
