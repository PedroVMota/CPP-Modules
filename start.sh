

#start a docker container called cpp-valgrind-1

#if the first Paramter is "d" delete all the image and container
if [ "$1" == "d" ]; then
    docker stop $(docker ps -a -q)
    docker rm $(docker ps -a -q)
    docker rmi $(docker images -q)
fi

docker compose down 
docker compose up --build -d
docker start $(docker ps -a -q)
docker exec -it cpp-valgrind-1 /bin/bash
