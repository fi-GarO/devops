import json

# Read the JSON file
with open('ogalerts - thisyear.json') as file:
    data = json.load(file)

# Extract text between the second and third blank spaces
text_between_spaces = []
existing_text = set()

for entry in data:
    message = entry['Message']
    words = message.split(' ')
    if len(words) >= 4:
        text = ' '.join(words[2:3])  # Modify this line to include only the third word
        if text not in existing_text:
            text_between_spaces.append(text)
            existing_text.add(text)

text_between_spaces.sort()
# Write the extracted text to a new JSON file
with open('text_between_spaces.json', 'w') as file:
    json.dump(text_between_spaces, file, indent=4)

# Remove duplicate entries
unique_alerts = []
existing_alerts = set()

for entry in data:
    message = entry['Message']
    words = message.split(' ')
    if len(words) >= 4:
        alert = ' '.join(words[2:3])  # Modify this line to include only the third word
        if alert not in existing_alerts:
            unique_alerts.append(entry)
            existing_alerts.add(alert)

# Write the unique alerts to a new JSON file
with open('output.json', 'w') as file:
    json.dump(unique_alerts, file, indent=4)

# Count the number of entries in input and output files
input_count = len(data)
output_count = len(unique_alerts)

print("Number of entries in input file:", input_count)
print("Number of entries in output file:", output_count)
