#!/bin/bash

# 遍历所有子文件夹和其中的Java文件
find . -type f -name "*.java" | while read -r file; do
    # 获取不带扩展名的文件名
    base_name=$(basename "$file" .java)

    # 使用正则表达式从文件名中提取数字
    num=$(echo $base_name | grep -o -E '[1-9][0-9]*' | tail -1)

    # 获取文件的目录路径
    dir_name=$(dirname "$file")

    # 创建相同名字但前缀为"C"和数字的C++和Python文件
    new_name="C${num}_$(echo $base_name | sed "s/Code[0-9]*_//")"
    touch "${dir_name}/${new_name}.cpp"
    touch "${dir_name}/${new_name}.rs"
    touch "${dir_name}/${new_name}.py"
done

