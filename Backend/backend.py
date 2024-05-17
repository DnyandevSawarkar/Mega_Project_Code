import requests
from flask import Flask, request
import os

# Dictionary mapping actions to keys
action_map = {
    'Arm Forward Steps'         : 'wwwwwwwwwwwwwwwww',
    'Arm Backward Steps'        : 'qqqqqqqqqqqqqqqqq',
    'Body Forward Steps'        : 'sssssssssssssssss',
    'Body Backward Steps'       : 'aaaaaaaaaaaaaaaaa',
    'Rotate Left Steps'         : 'zzzzzzzzzzzzzzzzz',
    'Rotate Right Steps'        : 'xxxxxxxxxxxxxxxxx',
    'Gripper Upward Degrees'    : 'e',
    'Gripper Downward Degrees'  : 'c',
    'Gripper Close Degrees'     : 'd',
    'Gripper Open Degrees'      : 'p'
}

def send_file_content():
    filename = os.path.join(os.path.dirname(__file__), "text.txt")
    esp_ip = "192.168.4.1"  # Hardcoded IP address for ESP-01 in SoftAP mode
    esp_port = "80"
    try:
        with open(filename, 'r') as file:
            content = file.read()
            url = f"http://{esp_ip}:{esp_port}/receive"
            response = requests.post(url, data={'content': content})
            if response.status_code == 200:
                print("File content sent successfully to ESP-01.")
            else:
                print("Failed to send file content to ESP-01.")
    except Exception as e:
        print(f"Error: {e}")

app = Flask(__name__)

@app.route('/submit', methods=['POST'])
def submit():
    filename = os.path.join(os.path.dirname(__file__), "text.txt")
    block_data = request.form['block_data']
    # Map action names to keys
    for action, key in action_map.items():
        block_data = block_data.replace(action, key)
    # Remove newline characters
    block_data = block_data.replace('\n', '')
    # print(block_data)
    with open(filename, 'w') as file:
        file.write(block_data)
    send_file_content()
    return 'Data saved successfully!'


if __name__ == '__main__':
    app.run(host='127.0.0.1',port=5000, debug=True)  # Run the Flask application on port 5000
