# Description
### 目的: 了解命令型訊息的收發與分類
在雙方成功連線後, 基本上就能夠收發想要的資料,<br>
但如何處理收到的資料將是另一個需要面對的問題.<br>
此套件用簡易的四則運算計算機嘗試呈現其中一種,<br>
即客戶端提供數據與操作命令, 而服務端將運算結果回傳.<br>
程式上則透過calculator.cpp將使用者輸入的算式傳給result.cpp,<br>
而後者再根據運算符號與數值決定回傳的內容,<br>
回傳的內容則由calculator.cpp呈現.<br>
另外, 為能夠了解service類型溝通背後的處理概念(不是所有平台都內建service功能),<br>
在此使用ROS Topic實現.

# Execution
### Terminal 1
`source /opt/ros/noetic/setup.bash`<br>
`roscore`

### Terminal 2
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun send_then_result result_cpp`

### Terminal 3
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun send_then_result calculator_cpp`<br>
根據提示輸入算式, 可用的運算符號為+, -, *和/.<br>
結束calculator_cpp需使用Control-D, 而非Control-C.