DB_PATH= /home/makhtar/data/mariadb
WP_PATH = /home/makhtar/data/wordpress

all:	volume build_run

volume:
	@mkdir -p ${DB_PATH} ${WP_PATH}

build:
	@docker-compose -f ./srcs/docker-compose.yml build

run:
	@docker-compose -f ./srcs/docker-compose.yml up

build_run:
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
	@docker-compose -f ./srcs/docker-compose.yml stop

down:
	@docker-compose -f ./srcs/docker-compose.yml down

clean:
	@docker-compose -f ./srcs/docker-compose.yml down -v
	rm  -rf ${DB_PATH} ${WP_PATH}


re: clean all

fclean: clean
		docker system prune -a -f