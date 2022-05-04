Access container /bin/bash (Dockerfile has to contain RUN apk update && apk add bash)

docker exec -it a0f354154104 /bin/bash
apk add ...

Create Image s názvem "go-docker" (spouští dockerfile a ukládá na loclahost docker image - docker image ls)

docker build -t go-docker .

Run docker image s published portem 8080:8080 (v main appce router.Run(":8080"), v Dockerfile EXPOSE 8080)
docker run -d -p 8080:8080 go-docker