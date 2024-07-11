# Description
### 目的: 用於了解ROS訊息的變數序列化<br>
不論何種型態的變數(通訊用的也是), 其背後都是由二進制組成,<br>
運行此套件的程式, 可觀察到變數實際內容與其16進制對應表示.<br>
對於含有指標的型態, 其印出來的會是指標指向的地址(等同指標的內容),<br>
因此範例的std_msgs/Int8MultiArray與geometry_msgs/Point輸出形式才會差很多,<br>
因前者在C++中是用vector實現.

# Execution
不需要ROS主機

`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun msg_serialize main`