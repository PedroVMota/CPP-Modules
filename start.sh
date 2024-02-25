docker compose down 
docker compose up --build -d

docker start $(docker ps -a -q)

#start a docker container called cpp-valgrind-1
docker exec -it cpp-valgrind-1 /bin/bash