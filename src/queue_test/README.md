# Description
### 目的: 了解基本的緩衝區功能與實作<br>
在其他的套件包中, 可以了解到幾種通訊的架構與流程,<br>
然而, 通訊的過程, 也可能因為接收方(通常)處理不過來,<br>
或是需要一段時間處理上個命令, 進而產生訊息丟失.<br>

對於此狀況, 其中一種方法是使用緩衝區, 並在緩衝區<br>
填滿時, 選擇如何處理新訊息, 例如忽略、回覆已滿或<br>
刪除舊訊息等等. 另外也要注意緩衝區大小不能過大,<br>
除了記憶體問題外, 主要是可能會產生訊息落後, 此狀況<br>
對需要即時訊息而非訊息紀錄的系統影響較大.

在此套件包中, 分別呈現了不同種Queue(隊列)的實作,<br>
以及緩衝區大小對ROS通訊的影響.

Queue的實作分別如下:
- 儲存單一型態內容
  - Simple queue: 填入放陣列後端, 取出拿陣列最前面的元素
  - RingQueue: 將陣列前端與後端虛擬連接, 改善Simple queue取出內容的效率
- 儲存多型態內容(在此皆為RingQueue)
  - Simple multi-type: 透過額外的動態記憶體儲存填入內容, 而陣列則填入該記憶體的描述(使用者定義ID、位元組大小、動態記憶體位置), 取出則釋放記憶體.
  - Keep buffer: 概念類似C++的vector, 相比上一個, 額外具有目前儲存大小與最大容量的概念. 填入資料的大小若超過目前最大容量, 則重新申請記憶體, 取出部份則僅有資料複製, 記憶體不釋放, 此方法可不需頻繁的申請與釋放記憶體.

在ROS緩衝區觀察的程式中, pub_node會每隔一秒傳<br>
一次訊息, 而sub_node為模擬處理時間久的情況,<br>
回調函數接收後會延遲5秒才結束. 在此設定下, 可將<br>
sub_node的緩衝區設為1~4, 並觀察訊息丟失的情況,<br>
以及pub_node提前結束時, sub_node繼續處理訊息的部份.

根據經驗, 作者認為ROS的緩衝區在填滿時的行為是丟棄<br>
最舊的訊息(緩衝區第一筆訊息), 但尚未至ROS文檔證實.

# Execution(Queue implementation)
不需要ROS主機

`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun queue_test queue_test_node`<br>
根據提示可以選擇要使用哪種Queue實做, 之後可再根據緩衝區的提示進行資料的填入、提取、清除以及觀察Queue所有儲存內容.

# Execution(ROS queue)
## Terminal 1
`source /opt/ros/noetic/setup.bash`<br>
`roscore`

## Terminal 2
建議放在一側<br>
`source <path-to-commute_ws>/devel/setup.bash`<br>
`rosrun queue_test sub_node`

## Terminal 3
建議放在另一側<br>
`source <path-commute_ws>/devel/setup.bash`<br>
`rosrun queue_test pub_node`<br>
觀察與sub_node接收訊息的差異