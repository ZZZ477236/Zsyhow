import numpy as np
from features import prepare_for_training

class LinearRegression:
    """
    数据预处理
    得到所有参数个数
    初始化参数矩阵
    """
    def init(self,data,labels,polynomial_degree=0,sinusoid_degree=0,normalize_data=0):
        (data_processed,features_mean,features_deviation)=prepare_for_training(data,polynomial_degree,sinusoid_degree,normalize_data) 
        self.data=data_processed
        self.labels=labels
        self.features_mean=features_mean
        self.features_deviation=features_deviation
        self.polynomial_degree=polynomial_degree
        self.sinusoid_degree=sinusoid_degree
        self.normalize_data=normalize_data
        num_features=data_processed.shape[1]
        self.theta=np.zeros((num_features,1))

    def train(self,alpha,num_iterations=500):
        cost_history=self.gradient_decent(alpha,num_iterations)
        return self.theta,cost_history


    def gradient_decent   (self,alpha,num_iterations=500):
        cost_history=[]
        for i in range(num_iterations):
            self.gradient_step(alpha) 
            cost_history.append(self.cost_function(self.data,self.labels))  
        return cost_history
    
    def cost_function(self,data,labels):
        delta=LinearRegression.hypothesis(self.theta,data)-labels
        cost=np.dot(delta.T,delta)/(2*data.shape[0])
        return cost[0][0]
    

    def gradient_step(self,alpha):
            """
            梯度下降
            """
            num_examples=self.data.shape[0]
            predictions=LinearRegression.hypothesis(self.theta,self.data)
            delta=predictions-self.labels
            theta=self.theta
            theta=theta-alpha*(np.dot(delta.T,self.data)).T
            self.theta=theta


    @staticmethod
    def hypothesis(theta,data):
        return np.dot(data,theta) 
    
    def get_cost(self,data,labels):
         data_processed=prepare_for_training(data,polynomial_degree=0,sinusoid_degree=0,normalize_data=0) [0]
         return self.cost_function(data_processed,labels)

    def predict(self,data):
        data_processed=prepare_for_training(data,polynomial_degree=0,sinusoid_degree=0,normalize_data=0) [0]
        return LinearRegression.hypothesis(self.theta,data_processed)
    