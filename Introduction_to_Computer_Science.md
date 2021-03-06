Introduction to NTUST CSIE
===

Professors
---

- About 20 members
- [資訊工程系 專任師資](https://www.csie.ntust.edu.tw/p/412-1038-1815.php)
- 洪西進
    - 專長多
    - 和大陸有合作
- 陳錫明
    - IEEE fellow（系上僅 2 位）
- 李漢銘
    - 國安會資安諮詢委員
    - 資安老師
- 黃元欣
    - iOS 老師
- 戴文凱
    - 前東華教授
    - 鈊象公司獨立董事
- 鮑興國
    - 系主任
- 鄧惟中
    - NCC 委員
- 花凱龍
    - 實驗室和鈊象有合作
    - 以廣告對付機器人玩家
    - [臺科大人工智慧研究中心](https://ai.ntust.edu.tw/)
- 賴祐吉
    - 和鈊象有合作
- 項天瑞
    - 理論老師
- 姚智原
    - 和很多遊戲公司有合作
- 鄭欣明
    - 資安老師

> 台大資安較弱，低於台科。

合作公司
---

- 利凌
    - 監視器公司
    - 堅持不用大陸元件，中美貿易戰後翻身
    - EPS 超過 25（[ref.](https://www.cmoney.tw/notes/note-detail.aspx?nid=7095)）
    - 和 Intel 有合作
- 研揚
    - 和 Intel 有合作

Compare to NCTU
---

- 師資小輸
    - 國內
        - 台清交
    - 國外
        - Top 20
- 整體小輸
    - 經費
    - 師資（比例）
    - **學生素質** (most important)
- 個別小贏
    - 地理優勢（在台北）

課程發展方向
---

> 系上學程制度不存在

Why NTUST CSIE ?
---

- 近年新創多與資訊技術相關
  - 初始成本低
- 多業界合作機會
  - Nokia 專案
    - 學長曾幫 Nokia 做過雙平台 APP

***

How to make a coffee
---

Input: 咖啡豆
=>
Hardware: 磨豆機
=>
Algorithm: 步驟
=>
Program: 店員
=>
Output: 咖啡

> That is PROGRAMMING.

> That is LIFE.

Center of Computer Science
- Computer Science/Computer Engineering studies **algorithms** and **programming**.

Sabbatical Year
- 休息年
- 每工作六年，可以休息一年
- 教授可以去業界工作或去其他學校服務
- 學校仍然支薪
- 在美國，助理教授即享有資格
- 在台灣，僅正教授有資格

**Homework 1: What's your dream ?**
- 花點時間想想，你的 **夢想**、**目標** 是甚麼？

***

傅立葉轉換
===

- Fourier transform
    - $\begin{aligned}
    X(f) &= \int ^\infty _{-\infty} x(t) e^{-j 2\pi ft}dt
    \end{aligned}$
- Inverse Fourier transform
    - $\begin{aligned}
    x(t) &= \int ^\infty _{-\infty} X(f) e^{j 2\pi ft}df
    \end{aligned}$
- Laplace transform
    - $\begin{aligned}
    X(S) &= \int ^\infty _0 x(t) e^{-St}dt
    \end{aligned}$

取樣與量化
---

- 取樣（Sampling）
    - 訊號的垂直切割
    - Steps
        1. 依取樣頻率取得離散點訊號（取樣頻率至少為最高原始頻率的兩倍（$f_s \ge 2f_{max}$），若令 $X(f<0)=0$，則取樣頻率至少為最高原始頻率（$f_s \ge f_{max}$））
        2. 做傅立葉轉換（變成週期性函數，週期為兩倍取樣頻率，波形為原始訊號的傅立葉轉換結果）
        3. 過低通濾波器留下一個波
        4. 做反傅立葉轉換還原原始訊號
- 量化（Quantization）
    - 訊號的水平切割
    - 會造成訊號失真

***

DRAM vs. SRAM
===

|             | DRAM | SRAM |
| ----------- | ---- | ---- |
| Performance |      | Win  |
| Layout size | Win  |      |

Why use R, G, and B ?
===

因為人類肉眼感光細胞有三種，分別對紅、綠、藍光最敏感。

***

浮點數（Floating-point）表示法
===

- Sign bit
  - 正負號
- Exponent
  - 指數（表示小數點偏移量）
  - 常用 2 補數表示法（不一定）
- Mantissa
  - 原始數值去掉小數點
  - 空間有限，會捨棄後面超出長度的資料

Why not use 2'補數 in sign bit 
---

- 其實也可以
  - 歷史因素

運算
---

> not sure

- 保留重要的
  - 和比較大的對齊

編碼
===

- Morse code
  - 出現頻率越高，位元數越少
- Huffman code
  - Huffman 修課時發明
  - 不等長度編碼
  - 出現機率越小，編碼越長
  - 找出最小兩組，機率相加
  - 一個字的編碼不可以是另一個字的碼的前段（prefix）
- 錯誤偵測碼（parity bit）
  - 受到干擾，造成資料出錯
  - 多傳錯誤檢查碼

作業
===

1. Given *a* as a floating-point represented number.
2. *a* /= 3
3. *a* \*= 3
4. Does *a* equal 1 ? Why ?

***

Entropy
===

- $H(a)=-\sum _{i=1} ^n P(A _i) \log _2 P(A _i)$
- $H(a) \le Huffman\ Average\ Length \le H(a)+1$

JPEG
---

> A standard last 28 years without be modified

- Why?
  - low cost of eletricity

***

AI 研究中心系列講座
===

講師
---

- 翁竟智博士
  - Stripe 亞太區 CTO
  - 加州理工大學博士
- 蕭文翔
  - 哥倫比亞大學電機碩士
  - Touch of Modern 增長產品經理
- 何婕
- 張伯群
- 陳俊仰博士
  - 教授老同學
  - Grindr CTO/President
  - 台科大工智慧研究中心執行長
  - 加州理工大學電機博士

細節
---

- 資料會上 Moodle
- 10:30 開始，10:20 前到

網路
===

Scope
---

- LAN
- MAN
  - 城市網路
- WAN
  - 整個網路世界

Ownership
---

- Close: 軍網、企業內網

CSMA
---

- Carrier Sense Multiple Access
- 載波偵聽多路存取
- 使用最適合的頻率
- CD
  - Collision Detection
  - 發生碰撞後等待隨機長度時間再重新發送
- CA
  - Collision Avoidance
  - Use in Wi-Fi
  - The hidden terminal problem
    - 監聽對象被擋住，誤以為沒人在傳訊息
  - 等待隨機時間
  - 確認連線(handshake)
  - if no reponse
    - 再等待隨機時間後重送
    - 每次的隨機時間會拉長

Inter-process Communication
---

- Clien/Server
- Peer-to-peer (P2P)
  - 如何穿透 NAT
    - 由 Server 提供連線

The Internet
---
- 商機
  - IP 太難記
  - Domain name 出現
  - [Top expansive domain](https://www.godaddy.com/garage/the-top-20-most-expensive-domain-names/)

FDMA、TDMA、CDMA
---

- 底層無線技術
- **F**requency **D**ivision **M**ultiple **A**ccess
  - 依頻帶分隔流量
- **T**ime **D**ivision **M**ultiple **A**ccess
  - 依時間分隔流量（輪流使用）
- **C**ode **D**ivision **M**ultiple **A**ccess
  - 依編碼方式分隔流量
  - 軍事上可以防止竊聽（不知道編碼無法解譯）
  - 3G 後主要使用此種模式

***

研揚電腦
===

- 專做工業電腦
- ASUS 是大股東
- 計畫提供技術出租平台給客戶使用
  - 接觸到更多終端客戶

***

交換制度
===

- [姊妹校列表](https://www.oia.ntust.edu.tw/files/14-1017-62105,r995-1.php?Lang=zh-tw)
- 交換到外國學校，付本國學校學費

***

一些小雜談
===

- 系上明年開始會往邊緣運算方向發展課程
- 碩士學分
  - 畢業學分：24
  - 大學時期在台科先修的碩士學分可以抵免
  - 其他學校的學分則視學校排名、學生成績評估

簽章
===

- 最早的簽章：浮水印
- 針對音訊加簽：傅立葉轉換後在高頻帶加簽

演算法複雜度
===

- 舉例：`1 + 2 + ... + n`
  - 公式解
  - 迴圈
  - 遞迴
  - 建表

期中形式
===

- 前幾題選擇題
- 後面是簡答題
- 英文出題，可以中文作答

蕭文翔冷知識
===

- 期中前不甩老師複習，坐最後一排桌子向後轉自己讀自己的
- 很負責，自我規劃進度還超前
- 知道自己在幹嘛，有毅力且有決心
- [講座筆記](https://hackmd.io/U8Aosd1eSbStHxJg__ATow)

***

期中複習
===

- ICANN
    - https://ithelp.ithome.com.tw/articles/10239485
- ISP 
    - https://ithelp.ithome.com.tw/articles/10240232
- [從傳紙條輕鬆學習基本網路概念
](https://hulitw.medium.com/learning-tcp-ip-http-via-sending-letter-5d3299203660)
- ![](https://i.imgur.com/yVvsOVc.jpg)
- ![](https://i.imgur.com/ZXjjRqL.png)

***

Anomaly Detection (Auto-Encoder)
===

- Probably problem
    - Lack of problem sample
- Solution
    - How Stanford collect samples
        - randomly collect from Internet
        - cloud sourcing
    - problem
        - 人工智慧描述（reconstruct）出 NG 的樣本（無中生有），導致比對時比不出差異，無法檢測出錯誤。
        - 做太好取代人工，導致失業率提高
- Adventage
    - Same standards
    - Won't be tired
