# -*- coding: utf-8 -*-
"""
Created on Sat Aug 23 21:16:13 2025

@author: Ameer Basha Shaik
"""

import numpy as np 
import pandas as pd 
import seaborn as sns 
import matplotlib.pyplot as plt 
df = pd.read_csv("D:/diabetes.csv") 
# filling missing value using fillna()   
print(df.fillna(0)) 
 # filling a missing value with previous value  
print(df.fillna(method ='pad'))  
#Filling null value with the next ones  
print(df.fillna(method ='bfill'))  
# filling a null values using fillna() 
df["gender"] = np.nan   # create a new column
df["gender"].fillna("No Gender", inplace=True)
print(df.head())
#print(df["gender"].fillna("No Gender", inplace = True))  
# will replace Nan value in dataframe with value -99  
print(df.replace(to_replace = np.nan, value = -99)) 
# using dropna() function to remove rows having one Nan  
print(df.dropna())  
# using dropna() function to remove rows with all Nan  
print(df.dropna(how = 'all'))  
# using dropna() function to remove column having one Nan  
print(df.dropna(axis = 1)) 
print(df["Age"].fillna(df["Age"].mean())) 