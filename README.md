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

### 1️⃣ Time Series Generator (`TimeSeriesGenerator`)  
A base class that defines:  
- `seed (int)`: Controls random number generation.  
- `generateTimeSeries(int)`: A pure virtual function for generating time series.  
- `printTimeSeries(vector<double>)`: A static function to display a time series.  

### 2️⃣ Gaussian Generator (`GaussianGenerator`)  
Generates time series following a **Gaussian distribution**, using the **Box-Muller transform**.  
- Attributes:  
  - `mean (double)`  
  - `standard deviation (double)`  

### 3️⃣ Step Function Generator (`StepGenerator`)  
Generates a **step function time series** where values randomly change or stay constant.  

- 50% probability of changing to a **random value (0-100)**.  
- 50% probability of keeping the previous value.  

### 4️⃣ Sinusoidal Generator (`SinWaveGenerator`)  
Generates **sinusoidal time series** based on the equation:  
\[
f(x) = A \cdot \sin(\omega \cdot x + \phi)
\]
- `A (Amplitude)`  
- `ω (Frequency)`  
- `ϕ (Phase Shift)`  

### 5️⃣ Time Series Dataset (`TimeSeriesDataset`)  
Manages time series data for training and testing.  
- **Normalization (`Z-Normalization`)** ensures all series have the same scale.  
- Stores **samples** and **labels** for classification.  

### 6️⃣ Similarity Measures  

#### 📏 Euclidean Distance  
Measures the straight-line distance between two time series:  
\[
ED(x, y) = \sqrt{\sum_{i=0}^{N-1} (x[i] - y[i])^2}
\]  

#### ⏳ Dynamic Time Warping (DTW)  
Handles **time misalignment** by finding the best matching path between sequences:  
\[
DTW(x, y) = \min_{\pi} \sqrt{\sum_{(i,j) \in \pi} (x[i] - y[j])^2}
\]  

DTW allows sequences to be **stretched or compressed** to match similar patterns.

---

## 🤖 Implementing K-Nearest Neighbors (KNN)  

A **KNN classifier** is used for time series classification.  
- `K (int)`: Number of neighbors to consider.  
- `similarityMeasure (string)`: Chooses **DTW or Euclidean Distance**.  
- **Classification Strategy**:  
  - If **k = 1**, assign the label of the closest time series.  
  - If **k > 1**, assign the most frequent label among the `k` nearest neighbors.  

Computes **accuracy** using:  
\[
accuracy = \frac{1}{N} \sum_{i=0}^{N-1} (y_{pred}[i] == y_{true}[i])
\]  

