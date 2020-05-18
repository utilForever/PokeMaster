#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t utilforever/pokemaster .
else
    docker build -f $1 -t utilforever/pokemaster:$2 .
fi
docker run utilforever/pokemaster