# Description
### 目的: 了解遠程命令持續運行的機器, 並更改其狀態
在前面的套件包中, 通訊的架構皆屬於伺服-客戶型的溝通,<br>
雖然能夠從回覆中了解發出訊息的問題, 但請求時的阻塞模<br>
式反而會阻礙對於高頻率溝通的需求, 並且不是所有的溝通<br>
都需要回覆.

對於前者, 若不需要即時性的回覆, 則可考慮非同步性的請<br>
求; 而後者則更簡單, 只需不斷把資訊傳給目標即可, 此狀<br>
況在感測器資訊的收集較為常見, 且不合理的資訊通常也由<br>
目標機器選擇性忽略.

此套件透過模擬無人機系統, 以呈現感測器整合的概念, 而<br>
非同步請求則因作者尚未學過, 恕無法提供, 請再於網路上再了解.

在程式上, 由於重點是在通訊架構, 因此drone.cpp的無人<br>
機系統會簡化成只控制x, y, z位置, 朝向方向則固定, 並<br>
假設無人機在速度控制的響應為一階系統(等效於RC串聯電路).

感測器則有gps.cpp與height_sensor.cpp兩個, 負責接<br>
收drone.cpp發出的無人機位置, 並人為添加雜訊後, 由<br>
controller.cpp接收.

controller.cpp除了接收感測器資訊, 也會接收remote_commander.cpp<br>
的位置命令, 隨後將這些資訊透過PID運算得到無人機的速度<br>
命令, 最後傳給drone.cpp, 達成資訊流動的迴路.

# Execution
### Terminal 1
`source /opt/ros/noetic/setup.bash`<br>
`roscore`

### Terminal 2
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rospack list | grep -i control_system  # check if the package exists`<br>
`roslaunch control_system dron_system.launch`<br>
等待Terminal3執行好後, 即可按提示輸入位置命令<br>
結束程式需使用Control-D, 而非Control-C.

### Terminal 3
`source /opt/ros/noetic/setup.bash`<br>
`rqt_plot`<br>
於Topic欄位輸入`/drone_attitude/position/x`並按旁邊的+號來觀察x方向的位置
