from flask import Flask, make_response
import time

app = Flask(__name__)

@app.route('/metrics')
def metrics():
    # Rotate between 200, 210, and 220 status codes every 5 seconds
    values = [200, 210, 220]
    value = values[int(time.time()) % len(values)]
    
    # Update the metric with the current value
    metric = 'my_metric{{value="{value}"}} 1'.format(value=value)
    
    # Build the response with the metric
    response = make_response(metric)
    response.headers['Content-Type'] = 'text/plain'
    
    return response

@app.route('/')
def home():
    return "I'm working!"

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
