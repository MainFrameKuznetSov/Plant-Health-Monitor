# 🌱 Plant Health Monitor  

An Arduino-based IoT system that monitors plant health by tracking **soil moisture, temperature, and humidity** in real-time. The project leverages **DHT-22** and **analog soil moisture sensors** to collect environmental data with high accuracy, processes it into structured formats, and visualizes insights via a **JavaScript dashboard**.  

## 🚀 Features  
- 🌡️ **Temperature & Humidity Tracking**: Uses DHT-22 sensor for accurate readings.  
- 💧 **Soil Moisture Monitoring**: Calibrated analog moisture sensors to evaluate hydration consistency.  
- 📊 **Real-Time Dashboard**: JavaScript-based interface with live graphs and computed plant health scores.  
- 🔄 **Live Data Logging**: Sensor readings processed into JSON format for reliable storage and visualization.  
- ⚡ **High Accuracy**: Achieved ~95% accuracy in sensor monitoring after calibration.  

## 🛠️ Tech Stack  
- **Hardware**: Arduino UNO R3, DHT-22, Soil Moisture Sensors  
- **Programming**: C++ (Arduino), JavaScript  
- **Visualization**: Dynamic web dashboard with real-time graphs  
- **Data Handling**: JSON over COM Port  

## ⚙️ System Workflow  
1. Arduino collects readings from **DHT-22** and **moisture sensors**.  
2. Data is processed and structured into **JSON format**.  
3. Data is logged via **COM Port 7** and parsed for consistency.  
4. A **JavaScript dashboard** dynamically updates with graphs and computes a **plant health score**.  


## 🚀 Getting Started  

### Prerequisites  
- Arduino IDE installed  
- Node.js & npm (for dashboard)  
- Sensors connected properly (DHT-22 + soil moisture sensors)  

### Setup Instructions  
1. Clone the repository:  
   ```bash
   git clone https://github.com/MainFrameKuznetSov/Plant-Health-Monitor.git
   ```
2. Upload Arduino code to Arduino UNO via Arduino IDE.
3. Connect Arduino to system (ensure COM Port 7 is available).
4. Run the dashboard
```bash
  cd dashboard
  npm install
  npm start
```
