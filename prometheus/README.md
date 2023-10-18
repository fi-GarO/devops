# run Prometheus
docker run -d --name prometheus -p 9090:9090 -v /home/jturyna/prometheus:/etc/prometheus prom/prometheus

docker run -d --name prometheus -p 9090:9090 -v /home/jturyna/Devops/prometheus:/etc/prometheus prom/prometheus


# run alertmanager
docker run -d --name alertmanager -p 9093:9093 -v /home/jturyna/prometheus:/etc/alertmanager prom/alertmanager
docker run -d --name alertmanager -p 9093:9093 -v /home/jturyna/Devops/prometheus:/etc/alertmanager prom/alertmanager

# remove all containers
docker rm $(docker ps -a -q)

# remove container by name
docker rm $(docker ps -a -q --filter "name=alertmanager")


# build 

docker build -t my-app .

# run
docker run -p 5000:5000 my-app 



http://localhost:9093/api/v2/alerts
curl http://localhost:9093/api/v2/alerts