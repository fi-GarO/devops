FROM python:3.9-slim-buster

# Set the working directory
WORKDIR /app

# Copy the requirements file to the working directory
COPY requirements.txt .

# Install the required packages
RUN pip install --no-cache-dir -r requirements.txt

# Copy the application files to the working directory
COPY app.py .

# Expose port 5000 for the Flask app
EXPOSE 5000

# Set the command to start the Flask app
CMD [ "python", "app.py" ]

