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
---

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