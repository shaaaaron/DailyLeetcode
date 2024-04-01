#!/bin/bash

# 检查参数数量
# if [ "$#" -ne 1 ]; then
#     echo "Usage: $0 <directory>"
#     exit 1
# fi
# directory=$(realpath "$1")
directory=$(realpath "./")

outputFile="folder_tree.txt"

# 函数：递归地计算每个目录下的文件数量并返回目录树信息
count_files() {
    local dir=$1
    local indent=$2
    local count=0
    local subdir_info=""

    # 计算当前目录（非递归）下的直接文件数量
    for file in "$dir"/*; do
        if [ -f "$file" ]; then
            ((count++))
        elif [ -d "$file" ]; then
            # 递归获取子目录信息
            subdir_result=$(count_files "$file" "$indent    ")
            subdir_count=$(echo "$subdir_result" | head -n 1)
            ((count += subdir_count))
            subdir_info+=$(echo "$subdir_result" | tail -n +2)$'\n'
        fi
    done

    # 构建当前目录的信息字符串
    local dir_info="$indent- $(basename "$dir") ($count)"
    # 将当前目录信息和子目录信息合并
    echo -e "$count\n$dir_info\n$subdir_info"
}

# 主逻辑
echo "Generating folder tree with file counts..."
# 清空输出文件
> "$outputFile"
# 计算文件数并获取目录信息，然后将结果写入文件（跳过第一行，因为它是总数）
count_files "$directory" "" | tail -n +2 > "$outputFile"
echo "Folder tree with file counts has been generated in $outputFile."


readmeFile="README.md" # README 文件的路径

# 将目录树信息追加到 README 文件中
append_to_readme() {
    local readme="$1"
    local output="$2"
    local separator="------------------------"
    
    # 检查 README 文件中是否存在分隔符
    if grep -q -- "$separator" "$readme"; then
        # 存在分隔符，覆盖这一行之后的内容
        # 先获取分隔符之前的内容（包括分隔符）
        sed -i '' "/^$separator/,\$d" "$readme"
        echo "$separator" >> "$readme"
        echo "下面是文件树内容" >> "$readme"
        echo "$separator" >> "$readme"
    else
        # 不存在分隔符，直接追加分隔符和新的目录树信息
        echo "$separator" >> "$readme"
    fi
    # 追加新的目录树信息
    cat "$output" >> "$readme"
}

# 主逻辑
echo "Appending folder tree to $readmeFile..."
append_to_readme "$readmeFile" "$outputFile"
rm "$outputFile"
echo "Folder tree has been appended to $readmeFile."
# sleep 5