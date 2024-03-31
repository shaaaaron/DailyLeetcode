#!/bin/bash

# 检查是否提供了正确数量的参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <prefix>"
    exit 1
fi

# 赋值参数
prefix=$1

count=$(find "$1" -type f | wc -l)
echo "File count: $count"

sleep 1