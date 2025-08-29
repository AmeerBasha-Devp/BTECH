import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
df=pd.read_csv("D:/diabetes.csv")
print(df.describe())
print(df.head(10))
print(df.isnull())