# 环境安装

## 初始安装

```
sudo apt-get install update
sudo apt-get update && sudo apt-get -yqq install git
cd ~/.ssh && ssh-keygen -C gtc -f id_rsa -t rsa -N ''
cat id_rsa.pub
```

将公钥复制到 `https://github.com/settings/ssh/new`

```
git config --global user.name skyerguo97 && git config --global user.email skyerguo97@gmail.com
cd ~ && git clone git@github.com:skyerguo/EasyGraphTest.git
```

## 安装cmake

```
version=3.18
build=1
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/
./bootstrap
make -j$(nproc) && sudo make install
```

# 代码运行

## Test

### shortest_path_dijkstra

```
cd ~/EasyGraphTest/code
g++ -g -O2 -std=c++11 -o pa shortest_path_dijkstra.cpp
time ./pa ../verified_dataset/roads/a.in
```

### shortest_path_dijkstra

```
g++ -g -O2 -std=c++11 -o pa shortest_path_Spfa.cpp
time ./pa ../verified_dataset/roads/a.in
```



# igraph

## 安装

```
cd ~
sudo chown -R gtc:socnet-PG0 /usr/local/lib/ ## need this permission in CloudLAB
sudo chown -R gtc:socnet-PG0 /usr/local/include/ ## need this permission in CloudLAB
wget https://github.com/igraph/igraph/releases/download/0.10.4/igraph-0.10.4.tar.gz
tar -xzvf igraph-0.10.4.tar.gz
cd igraph-0.10.4
mkdir build && cd build
cmake ..
cmake --build .
cmake --install .
```

## 配置
```
cd ~/EasyGraphTest/igraph_test
mkdir build
```

创建CMakeLists.txt，内容如下
```
cmake_minimum_required(VERSION 3.18)
project(igraph_test)

find_package(igraph REQUIRED)

add_executable(igraph_test igraph_test.c)
target_link_libraries(igraph_test PUBLIC igraph::igraph)
```

## 编译运行

```
cd build
cmake .. && cmake --build .
cp ../../verified_dataset/roads/a.lgl ./
time ./igraph_test
```