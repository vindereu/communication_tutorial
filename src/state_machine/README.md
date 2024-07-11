# Description
### 目的: 了解遠程命令持續運行的機器, 並更改其狀態
除了從服務端獲取運算結果外, 若服務端屬於自行運行的機器,<br>
則也可以透過命令改變機器的行為.
此套件透過擁有開關機概念的上下數機器呈現上述概念<br>
程式上透過commander.cpp將使用者輸入的命令傳給machine_resp_command.cpp,<br>
後者根據當前狀態與收到的命令決定是否執行, 並回覆決策給commander.cpp<br>
回傳的內容則由commander.cpp呈現.<br>
另外, 此套件以ROS Service實現, 若要了解背後的概念, 可見send_then_result套件.

### 製作中
machine_resp_process: 多一個Topic以發送目前上下數數值

# Execution
### Terminal 1
`source /opt/ros/noetic/setup.bash`<br>
`roscore`

### Terminal 2
建議將此Terminal放在其中一側.<br>
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun state_machine machine_cpp`

### Terminal 3
建議將此Terminal放在另一側<br>
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun state_machine commander_cpp`<br>
根據提示輸入命令(0~4), 觀察[Out]的內容以及Terminal 2的機器狀態.<br>
結束commander_cpp需使用Control-D, 而非Control-C.