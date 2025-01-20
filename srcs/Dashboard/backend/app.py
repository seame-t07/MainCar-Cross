import zmq
import threading
from flask import Flask, render_template, jsonify
from flask_socketio import SocketIO, emit
import json
import os

app = Flask(__name__, template_folder='../frontend/')
socketio = SocketIO(app)
# Create context
context = zmq.Context()

# Socket sensors (5555)
sensor_socket = context.socket(zmq.SUB)
sensor_socket.connect("tcp://localhost:5555")
sensor_socket.setsockopt_string(zmq.SUBSCRIBE, "")

# Listen for sensors
def listen_for_sensor_data():
    while True:
        # Receive data from the sensor socket
        message = sensor_socket.recv_string()
        print(f"Sensor Data: {message}")

        # Split the message into type and value
        parts = message.split(' ')

        if len(parts) != 2:
            continue  # If the message doesn't have the expected format, skip it

        sensor_type, sensor_value = parts

        # Dictionary to store sensor data
        sensor_data = {}

        # Check the sensor type and prepare the appropriate data
        if sensor_type == "speed":
            sensor_data['speed'] = sensor_value
        elif sensor_type == "is_moving":
            sensor_data['is_moving'] = sensor_value
        elif sensor_type == "distance":
            sensor_data['distance'] = sensor_value
        elif sensor_type == "battery_level":
            sensor_data['battery_level'] = sensor_value
        # Add more sensors as necessary

        # Emit the sensor data to the frontend via SocketIO
        socketio.emit('vehicle_sensors', sensor_data)


# Start thread to listen ZeroMQ data
sensor_thread = threading.Thread(target=listen_for_sensor_data, daemon=True)
sensor_thread.start()

@app.route('/')
def index():
    return render_template('index.html')  # index html template

# api vehicle info:
@app.route('/vehicle-info', methods=['GET'])
def get_vehicle_info():
    json_file_path = '../../MainCar/build/vehicle_info.json'  # Caminho para o arquivo JSON gerado
    if os.path.exists(json_file_path):
        with open(json_file_path, 'r') as file:
            data = json.load(file)
        return jsonify(data)
    else:
        return jsonify({"error": "Vehicle information not found"}), 404

if __name__ == '__main__':
    app.run(debug=True, host="0.0.0.0", port=5000)  # Flask running 5000
