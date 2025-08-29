import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats
df=pd.read_csv("D:\diabetes.csv")
print(df[:10])
print(df.corr(method='pearson'))
print(df.corr(method='kendall'))
