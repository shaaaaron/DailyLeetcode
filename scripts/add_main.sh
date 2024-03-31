#!/bin/bash

# 检查是否提供了正确数量的参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <prefix>"
    exit 1
fi

# 赋值参数
prefix=$1

# 查找当前目录下所有以特定前缀开头的文件
for file in "${prefix}."*; do
    if [ -f "$file" ]; then # 确保是文件
        case $file in
            *.py)
                echo -e "\nif __name__ == \"__main__\":" >> "$file"
                echo "    # TODO: Write your Python code here" >> "$file"
                echo "    pass" >> "$file"
                ;;
            *.cpp)
                echo -e "\nint main() {" >> "$file"
                echo "    // TODO: Write your C++ code here" >> "$file"
                echo "    return 0;" >> "$file"
                echo "}" >> "$file"
                ;;
        esac
        echo "Appended content to $file based on its file extension."
    fi
done

sleep 1