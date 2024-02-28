import streamlit as st
import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
df = pd.read_csv('Crop_recommendation.csv')
X = df.iloc[:, :-1].values
y = df.iloc[:, -1].values
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
classifier = RandomForestClassifier(n_estimators=100, random_state=0)
classifier.fit(X_train, y_train)
st.title('Crop Recommendation System')

st.write('Please enter the following details to get a crop recommendation :')

n = st.number_input('Please enter N value',format="%.2f")
p = st.number_input("Please enter P value",format="%.2f")
k = st.number_input('Please enter K value',format='%.2f')
temperature = st.number_input('please enter temperature value',format='%.2f')
rainfall = st.number_input('Please enter rainfal value',format='%.2f')
humidity = st.number_input('Please enter humidity value',format='%.2f')
ph=st.number_input('please enter Ph value',format='%.2f')
data = np.array([[n,p,k,temperature,humidity,ph,rainfall]])

if st.button('Get Recommendation'):
    prediction = classifier.predict(data)
    st.write('The recommended crop is :', prediction[0])
