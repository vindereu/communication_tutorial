# Dependencies
- ROS noetic
- roscpp

# Packages
詳細資訊看各Package的README.md

- msg_serialize: 用於了解ROS訊息的變數序列化
- send_then_result: 使用ROS Topics運行簡易的四則運算計算機, 以了解命令型訊息的收發與分類
- state_machine: 使用ROS Service運行簡易的狀態機, 以了解遠程命令持續運行的機器, 並更改其狀態

### 製作中
- control_system: 使用ROS Topics模擬一台機器接收感測器的情景, 了解基本的多訊息整合

# Build
更新ROS環境<br>
`source /opt/ros/noetic/setup.bash`<br>
建置工作空間<br>
`cd <path-to-commute_ws>`<br>
`catkin_make`
