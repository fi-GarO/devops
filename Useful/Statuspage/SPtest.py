import json

with open('spData.json', "r") as f: 
    data = json.loads(f.read())


print(' Component name:', data['name'], '\n Uptime:', data['uptime_percentage'], '\n Start Date:', data['range_start'], '\n End Date:', data['range_end'])