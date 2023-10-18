# Access container /bin/bash (Dockerfile has to contain RUN apk update && apk add bash)

- docker exec -it <containerid> /bin/bash
- apk add ...

# Docker Images
## Create Image s názvem "jirituryna/docker-products" (spouští dockerfile a ukládá na loclahost docker image)

- docker build -t jirituryna/docker-products .

## Run docker image s published portem 8080:8080 (v main appce router.Run(":8080"), v Dockerfile EXPOSE 8080)
- docker run -d -p 8080:8080 jirituryna/docker-products

## Přehled všech uložených imagů na localu
- docker image ls

## Přehled všech currently running containerů
- docker ps

## Fix permissions
- sudo chmod 666 /var/run/docker.sock



# Docker hub
- create account, create repo 
- name your container image in this format:  dockerid/repository -> jirituryna/docker-products
- docker tag <previosu-docker-image-name> jirituryna/docker-products
- docker push jirituryna/docker-products

## Run image on new instance
- docker run -d -p 8080:8080 jirituryna/docker-products
- docker run -d -p 8080:8080 -v test-db:/test.db jirituryna/docker-products
- docker run -d -p 8080:8080 -v test-db:/app/test.db jirituryna/docker-products
- docker run -d -p 8080:8080 --mount source=test-db,destination=/test.db jirituryna/docker-products


# Databases
## Create Network
- docker network create products-app

## Run mysql container assigned to network, password = "secret" and database "products"
- docker run -d      --network products-app --network-alias mysql      -v todo-mysql-data:/var/lib/mysql      -e MYSQL_ROOT_PASSWORD=secret      -e MYSQL_DATABASE=products      mysql:5.7

## Check insides of the mysql container - password = "secret"
- docker exec -it <mysql-container-id> mysql -u root -p
- SHOW DATABASES;

docker run -dp 8080:8080 \
   -w /app -v "$(pwd):/test.db" \
   --network products-app \
   -e MYSQL_HOST=mysql \
   -e MYSQL_USER=root \
   -e MYSQL_PASSWORD=secret \
   -e MYSQL_DB=products \
   jirituryna/docker-products
¨
./ctcgrpc client -e localhost:8080 get a

sudo apt install protobuf-compiler
export PATH=$PATH:$GOPATH/bin
export GOPATH=$HOME/go

# Good to know
docker run -t -d -p 8080:8080 python:3.7-alpine3.9

docker exec -it e45b6d9bce2f /bin/sh

docker cp chnmt_notify.py e45b6d9bce2f:chnmt-notify/chnmt_notify.py

apk update && apk add bash

docker exec -it e45b6d9bce2f /bin/bash


# app.run(host='localhost', port=5000)
- This runs the app only inside the container. Not accessible from main machine.	
# app.run(host='0.0.0.0', port=5000)
- This makes the app accessible from main machine.


# follow logs
docker logs --follow a2880223db1a