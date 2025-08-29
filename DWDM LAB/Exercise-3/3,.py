import pandas as pd
df=pd.read_csv("D:\diabetes.csv")
print(df.describe())
print(df.head(10))