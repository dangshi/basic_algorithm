#! /usr/bin/env python3
# -*- coding:utf-8 -*-
import numpy as np
from sklearn import datasets
import numpy as np
import matplotlib.pyplot as plt

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

class LogisticRegression():
    def __init__(self, learing_rate=0.1, n_iter=1000):
        self.learning_rate = learing_rate
        self.n_iter = n_iter

    def init_weights(self, n_features):
        limit = np.sqrt(1 / n_features)
        w = np.random.uniform(-limit, limit, (n_features, 1))
        b = 0
        self.w = np.insert(w, 0, b, axis=0)
    
    def fit(self, X, y):
        m_samples, n_features = X.shape
        self.init_weights(n_features)

        # 为X增加一列特征x1，x1 = 0
        X = np.insert(X, 0, 1, axis=1)
        y = np.reshape(y, (m_samples, 1))

        for _ in range(self.n_iter):
            hx = X.dot(self.w)
            y_pred = sigmoid(hx)
            w_grad = X.T.dot(y_pred - y)
            self.w = self.w - self.learning_rate * w_grad
    
    def predict(self, X):
        X = np.insert(X, 0, 1, axis=1)
        h_x = X.dot(self.w)
        y_pred = np.round(sigmoid(h_x))
        return y_pred.astype(int)

