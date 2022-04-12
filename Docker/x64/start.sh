#!/bin/bash

cd ../../
make -j4
cp -f ./ft_nm Docker/x64/ft_nm
cd Docker/x64

docker build -t $(whoami)/nm_x64 .
docker run -it $(whoami)/nm_x64