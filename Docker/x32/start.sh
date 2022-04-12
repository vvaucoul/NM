#!/bin/bash

cd ../../
make -j4
cp -f ./ft_nm Docker/x32/ft_nm
cd Docker/x32

docker build -t $(whoami)/nm_x32 .
docker run -it $(whoami)/nm_x32