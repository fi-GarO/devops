from Flask import Flask, make_response
import os
import pythonping

app = Flask(__name__)

# Define the target server's IP address or hostname
target_server = "google.com"

@app.route('/metrics')
def metrics():
    # Send an ICMP ping request to the target server
    response = pythonping.ping(target_server, count=1)

    # Extract the round-trip time (ping time) from the response
    ping_time = response.rtt_avg if response.rtt_avg is not None else 0

    # Build the metric with the ping time
    metric = 'ping_time{{server="{server}"}} {ping_time}'.format(server=target_server, ping_time=ping_time)

    # Build the response with the metric
    response = make_response(metric)
    response.headers['Content-Type'] = 'text/plain'

    return response

@app.route('/')
def home():
    return "I'm working!"

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)

