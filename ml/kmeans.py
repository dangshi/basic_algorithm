#! /usr/bin/env python3
# -*- coding:utf-8 -*-

import numpy as np
import time
import matplotlib.pyplot as plt

def euclDistance(va, vb):
    return np.sqrt(sum(np.power(va - vb, 2)))

def initCentroids(dataset, k):
    n_samples, dim = dataset.shape
    centro_ids = dataset[np.random.choice(n_samples, k)]
    return centro_ids

def kmeans(dataset, k):
    n_samples = dataset.shape[0]
    # first column stores which cluster this sample belongs to,
	# second column stores the error or distance between this sample and its centroid
    cluster_assign = np.mat(np.zeros((n_samples, 2)))
    cluster_changed = True

    centro_ids = initCentroids(dataset, k)
    while cluster_changed:
        cluster_changed = False
        for i in range(n_samples):
            min_dis = 1e9
            min_idx = -1
            for j in range(k):
                distance = euclDistance(centro_ids[j, :], dataset[i, :])
                if distance < min_dis:
                    min_dis = distance
                    min_idx = j
            
            if cluster_assign[i, 0] != min_idx:
                cluster_changed = True
                cluster_assign[i, :] =  min_idx, min_dis**2
            
        for j in range(k):
            points_cluster = dataset[cluster_assign[:, 0] == j]
            centro_ids[j, :] np.mean(points_cluster, axis=0)
        
        print('Congratulations, cluster complete!')
	    return centroids, clusterAssment
