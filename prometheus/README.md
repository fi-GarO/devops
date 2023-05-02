# run Prometheus
docker run -d --name prometheus -p 9090:9090 -v /home/jturyna/prometheus:/etc/prometheus prom/prometheus

# run alertmanager
docker run -d --name alertmanager -p 9093:9093 -v /home/jturyna/prometheus:/etc/alertmanager prom/alertmanager

# remove all containers
docker rm $(docker ps -a -q)

# remove container by name
docker rm $(docker ps -a -q --filter "name=alertmanager")
