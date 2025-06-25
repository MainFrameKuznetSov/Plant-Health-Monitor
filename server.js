const express = require("express");
const http = require("http");
const { SerialPort, ReadlineParser } = require("serialport");
const socketIo = require("socket.io");
const cors = require("cors");

const app = express();
const server = http.createServer(app);
const io = socketIo(server, {
    cors: {
        origin: "http://localhost:3000", // React frontend URL
        methods: ["GET", "POST"]
    }
});

app.use(cors());

const port = new SerialPort({
    path: "COM7", // Change for Linux/Mac: "/dev/ttyUSB0" or "/dev/ttyACM0"
    baudRate: 9600
});

const parser = new ReadlineParser();
port.pipe(parser);

parser.on("data", (data) => {
    try {
        const jsonData = JSON.parse(data);
        const timestamp = new Date().toISOString(); // Generates ISO timestamp

        const sensorData = {
            ...jsonData,
            timestamp: timestamp
        };

        console.log("Received Data:", sensorData);
        io.emit("sensorData", sensorData); // Send data with timestamp
    } catch (error) {
        console.error("Error parsing JSON:", error);
    }
});

io.on("connection", (socket) => {
    console.log("Client Connected");
    socket.on("disconnect", () => {
        console.log("Client Disconnected");
    });
});

server.listen(5000, () => {
    console.log("Server running on http://localhost:5000");
});
