import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv("D:/diabetes.csv")
print(df.fillna(0))
print(df.fillna(method="pad"))
print(df.fillna(method='bfill'))
#df["gender"] = np.nan   # create a new column
#df["gender"].fillna("No Gender", inplace=True)
#print(df.head())
print(df["gender"].fillna("No gender",inplace=True))
print(df.replace(to_replace=np.nan,value=-99))
print(df.dropna())
print(df.dropna(how='all'))
print(df.dropna(axis=1))
