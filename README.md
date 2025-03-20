# 📊 Time Series Classification in C++

Welcome to the **Time Series Classification** project! 🚀  
This project implements **time series generation and classification** using **K-Nearest Neighbors (KNN)** with various similarity measures, including **Euclidean Distance** and **Dynamic Time Warping (DTW)**.  

Time series data appears in various real-world applications such as **electrocardiograms (ECG), sensor readings, financial market trends, and speech processing**. The goal is to **classify time series sequences** into predefined categories based on their patterns.  

---

## 🔬 Project Overview  

- ✅ **Generate synthetic time series data** using multiple statistical models.  
- ✅ **Normalize time series** for better classification accuracy.  
- ✅ **Implement similarity measures** for time series comparison.  
- ✅ **Classify time series using KNN** with different similarity functions.  
- ✅ **Evaluate model accuracy** using classification metrics.  

---

## 📈 What is Time Series Classification?  

A **time series** is a sequence of data points ordered in time. Examples include:  

- 📌 **ECG signals** - Distinguishing between normal and abnormal heartbeats.  
- 📌 **Stock prices** - Predicting market trends.  
- 📌 **Sensor data** - Identifying anomalies in temperature, pressure, or motion.  

The objective of **time series classification** is to assign a label to a given sequence based on its characteristics.  

### 🏥 Example: ECG Signal Classification  
We classify heart activity based on **ECG200 Dataset** (from the [UCR Archive](https://www.cs.ucr.edu/~eamonn/time_series_data_2018/)):  
- **Class 0:** Myocardial Infarction (Heart Attack)  
- **Class 1:** Normal Heartbeat  

---

## 🛠 Implementation Details  

### 1️⃣ Time Series Generator  
Defines a base class for generating synthetic time series data. Three types of generators are implemented:  

- **Gaussian Generator**: Generates time series from a normal distribution.  
- **Step Function Generator**: Generates a time series where values randomly change or remain constant.  
- **Sinusoidal Generator**: Generates time series following a sine wave equation:  

  
  $$f(x) = A \cdot \sin(\omega \cdot x + \phi)$$
  

  where:
  - $$\ A \$$ is the amplitude  
  - $$\ \omega \$$ is the frequency  
  - $$\ \phi \$$ is the phase shift  

### 2️⃣ Time Series Dataset  
Handles training and test data storage. It supports **Z-normalization**, ensuring all time series have comparable scales:  

  $$
  x' = \frac{x - \mu_x}{\sigma_x}
  $$  

  where \( \mu_x \) is the mean and \( \sigma_x \) is the standard deviation.  

---

## 📏 Similarity Measures  

### **Euclidean Distance**  
The Euclidean distance between two time series \( x \) and \( y \) is computed as:  

  $$
  ED(x, y) = \sqrt{\sum_{i=0}^{N-1} (x[i] - y[i])^2}
  $$  

This assumes the time series are perfectly aligned.  

### ⏳ **Dynamic Time Warping (DTW)**  
DTW allows measuring the similarity between time series that may be **temporally misaligned**. It finds an optimal warping path \( \pi \):  

  $$
  DTW(x, y) = \min_{\pi} \sqrt{\sum_{(i,j) \in \pi} (x[i] - y[j])^2}
  $$  

DTW is useful for applications where time series have **different speeds or shifts**.  

---

## 🤖 K-Nearest Neighbors (KNN) for Classification  

The **KNN classifier** assigns a label to an unknown time series based on its similarity to known samples.  

- If \( k = 1 \), the label of the closest neighbor is assigned.  
- If \( k > 1 \), the **majority vote** among the \( k \) nearest neighbors determines the classification.  

The **classification accuracy** is calculated as:  

  $$
  \text{accuracy} = \frac{1}{N} \sum_{i=0}^{N-1} (y_{\text{pred}}[i] == y_{\text{true}}[i])
  $$  

where \( y_{\text{pred}} \) is the predicted class and \( y_{\text{true}} \) is the ground truth label.  

---

## 📜 References  

- 🔗 **UCR Time Series Archive**: [UCR Archive](https://www.cs.ucr.edu/~eamonn/time_series_data_2018/)  
- 🔗 **Dynamic Time Warping (DTW)**: [DTW Explanation](https://en.wikipedia.org/wiki/Dynamic_time_warping)  

---

## 🔗 How to Use This Repo?  

1️⃣ Clone this repository:  
```sh
git clone https://github.com/your-username/time-series-classification.git
cd time-series-classification
