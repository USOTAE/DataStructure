**知识点：** 分块矩阵行列式（Schur 补）、分块初等变换与分块矩阵乘法、行列式按块（Laplace）展开、逆矩阵的转置性质 $(A^{-1})^T=(A^T)^{-1}$、反对称矩阵 $A^T=-A$、标量的转置等于自身、行列式的数乘性质 $|-A|=(-1)^n|A|$

**题目：** 设 $A$ 为 $n$ 阶矩阵，$\alpha$ 为 $n$ 维列向量。已知 $|A|\neq 0$，$b\neq 0$ 且 $A^T=-A$，且

$$\begin{vmatrix} A & \alpha\\ \alpha^T & b \end{vmatrix}=c,$$

求 $|A|$。

---

# 一、前置观察：$n$ 必为偶数

由行列式转置不变与数乘性质：

$$|A|=|A^T|=|-A|=(-1)^n|A|$$

依据：$|A^T|=|A|$（行列式转置不变）；$|kA|=k^n|A|$（$n$ 阶矩阵每行提出一个 $k$，共提 $n$ 次），取 $k=-1$。

若 $n$ 为奇数，则 $|A|=-|A|$，得 $|A|=0$，与已知 $|A|\neq 0$ 矛盾。

**结论：$n$ 为偶数。**&#8203;（这一步不参与最后计算，但说明题目条件自洽，且为验算取特例做准备。）

---

# 二、用分块初等变换化简行列式（Schur 补）

**第 1 步：写出分块消元矩阵。**&#8203; 因 $|A|\neq 0$，$A$ 可逆。取分块下三角矩阵

$$P=\begin{pmatrix} I_n & 0\\ -\alpha^T A^{-1} & 1 \end{pmatrix}$$

依据：$P$ 的对角块为 $I_n$ 与 $1$，故 $\det P=\det(I_n)\times 1=1$，用它左乘不改变行列式的值（相当于对原行列式做"倍加"型初等行变换）。

**第 2 步：作分块乘法。**&#8203;

$$P\begin{pmatrix} A & \alpha\\ \alpha^T & b \end{pmatrix}=\begin{pmatrix} A & \alpha\\ -\alpha^T A^{-1}A+\alpha^T & -\alpha^T A^{-1}\alpha+b \end{pmatrix}=\begin{pmatrix} A & \alpha\\ 0 & b-\alpha^T A^{-1}\alpha \end{pmatrix}$$

依据：分块矩阵乘法规则；$-\alpha^T A^{-1}A+\alpha^T=-\alpha^T+\alpha^T=0$（$A^{-1}A=I_n$）。

**第 3 步：两边取行列式，按第一列块展开。**&#8203;

$$c=\begin{vmatrix} A & \alpha\\ 0 & b-\alpha^T A^{-1}\alpha \end{vmatrix}=|A|\cdot\left(b-\alpha^T A^{-1}\alpha\right)$$

依据：左乘 $\det P=1$ 不改变行列式；分块三角行列式 = 对角块行列式之积（按第一列展开，左下角 $0$ 块使交叉项全部为零）。

---

# 三、关键一步：证明标量 $\alpha^T A^{-1}\alpha=0$

记 $s=\alpha^T A^{-1}\alpha$。注意 $s$ 是 $1\times 1$ 的量（行向量 × 矩阵 × 列向量），**标量的转置等于它自身**：

$$s=s^T=\left(\alpha^T A^{-1}\alpha\right)^T=\alpha^T\left(A^{-1}\right)^{T}\alpha=\alpha^T\left(A^{T}\right)^{-1}\alpha$$

依据：$(ABC)^T=C^TB^TA^T$（转置反序）；$(A^{-1})^T=(A^T)^{-1}$（转置与求逆可交换次序）。

代入 $A^T=-A$：

$$s=\alpha^T(-A)^{-1}\alpha=\alpha^T\left(-A^{-1}\right)\alpha=-\alpha^TA^{-1}\alpha=-s$$

依据：$(kA)^{-1}=\dfrac{1}{k}A^{-1}$，取 $k=-1$ 得 $(-A)^{-1}=-A^{-1}$。

于是 $s=-s$，即 $2s=0$，故

$$\alpha^TA^{-1}\alpha=0$$

依据：数域上 $2s=0\Rightarrow s=0$。

> **这一步的本质：** 对反对称矩阵 $S$（$S^T=-S$），二次型 $x^TSx$ 恒等于 $0$。$A^{-1}$ 恰好也是反对称的（$\left(A^{-1}\right)^{T}=(A^T)^{-1}=(-A)^{-1}=-A^{-1}$），所以 $\alpha$ 在它上面的二次型必为零。

---

# 四、代回求出 $|A|$

把 $s=0$ 代入第二步结果：

$$c=|A|\cdot(b-0)=|A|\,b$$

又已知 $b\neq 0$，两边同除以 $b$：

$$\boxed{\ |A|=\dfrac{c}{b}\ }$$

依据：等式 $c=|A|b$ 两边同除以非零常数 $b$。

---

# 五、验算

**验算 1（$n=2$ 数值特例）：** 取 $A=\begin{pmatrix}0&1\\-1&0\end{pmatrix}$（满足 $A^T=-A$，$|A|=1\neq0$），$\alpha=\begin{pmatrix}2\\3\end{pmatrix}$，$b=5$：

$$\begin{vmatrix} 0 & 1 & 2\\ -1 & 0 & 3\\ 2 & 3 & 5 \end{vmatrix}=0\times(0\times5-3\times3)-1\times\bigl((-1)\times5-3\times2\bigr)+2\times\bigl((-1)\times3-0\times2\bigr)$$

依据：三阶行列式按第一行展开 $\det=\sum_j(-1)^{1+j}a_{1j}M_{1j}$。

$$=0-1\times(-11)+2\times(-3)=11-6=5$$

公式给 $|A|\,b=1\times5=5$，即 $c=5$，与直接展开一致 ✓

**验算 2（退化情形 $\alpha=0$）：** 行列式成为分块对角 $\begin{vmatrix}A&0\\0&b\end{vmatrix}=|A|\,b$，与 $c=|A|b$ 吻合 ✓

**验算 3（自洽性）：** 由 $c=|A|b$、$|A|\neq0$、$b\neq0$ 知 $c\neq0$；而转置法可证 $c=(-1)^n c$（对 $M^T=\begin{pmatrix}-A&\alpha\\\alpha^T&b\end{pmatrix}$ 前 $n$ 行乘 $-1$、末行末列再各乘 $-1$），$n$ 为偶数时 $c=c$ 恒成立，无矛盾 ✓

---

**一句话总结：** 条件 $A^T=-A$ 的全部威力都集中在"**&#8203;标量转置等于自身**"这一件事上——它逼出 $\alpha^TA^{-1}\alpha=0$，于是加边行列式干净地等于 $|A|\,b$，故 $|A|=\dfrac{c}{b}$。

**知识点：** 分块矩阵高斯消元（Schur 补）、分块初等变换（行变换左乘 / 列变换右乘）、维数匹配、分块三角行列式、矩阵行列式引理

**题目：** $A$ 为 $n$ 阶矩阵，$\alpha$ 为 $n$ 维列向量，$|A|\neq0$，$b\neq0$，$A^T=-A$，$\begin{vmatrix}A&\alpha\\\alpha^T&b\end{vmatrix}=c$，求 $|A|$。

---

# 一、$P$ 的正向构造思路

**类比 $2\times2$ 数字行列式的消元：**

$$\begin{vmatrix}a&c\\d&b\end{vmatrix}\xrightarrow{R_2-\frac{d}{a}R_1}\begin{vmatrix}a&c\\0&b-\frac{dc}{a}\end{vmatrix}=a\left(b-\frac{dc}{a}\right)$$

依据：倍加型行变换不变行列式；三角形行列式 = 对角元之积。

**翻译成块语言（三条）：**

| 数字情形 | 块情形 | 依据 |
|---|---|---|
| 选主元 $a$（需 $a\neq0$） | 选主元块 $A$（$|A|\neq0$） | 题给 $|A|\neq0$ 即提示以 $A$ 为主元块 |
| 消左下角 $d$ | 消左下块 $\alpha^T$ | 消掉后化为分块三角，$|A|$ 落到对角上 |
| 系数 $\dfrac{d}{a}=d\cdot a^{-1}$ | 系数 $\alpha^TA^{-1}$ | $A^{-1}A=I_n$；维数 $\alpha^T(1\times n)\cdot A^{-1}(n\times n)=1\times n$，可与第二块行相加 |

**要消左下块 ⇒ 必须左乘**（块行变换 = 左乘，$R_i\leftarrow R_i+KR_j$ 对应 $P$ 的 $(i,j)$ 块填 $K$）：

$$P=\begin{pmatrix}I_n&0\\-\alpha^TA^{-1}&1\end{pmatrix}$$

| $P$ 的块 | 取值 | 理由 |
|---|---|---|
| 左上 $I_n$ | 第一块行保持原样 | 它是主元行，不能动 |
| 右上 $0$ | 第一块行不混入第二块行 | 否则破坏已消好的结构 |
| 左下 $-\alpha^TA^{-1}$ | 消元系数（负号 = 减去） | $\alpha^T-(\alpha^TA^{-1})A=\alpha^T-\alpha^T=0$ |
| 右下 $1$ | 第二块行自身保留一份 | $P$ 为分块三角 ⇒ $\det P=\det(I_n)\cdot1=1$，左乘不改变行列式 |

**口诀：** 要消谁，就把它写成（目标块）×（主元块）$^{-1}$，加负号，填在 $P$ 的对应行块位置；对角块一律填 $I$ 和 $1$。

---

# 二、分块消元（Schur 补）

$$P\begin{pmatrix}A&\alpha\\\alpha^T&b\end{pmatrix}=\begin{pmatrix}A&\alpha\\0&b-\alpha^TA^{-1}\alpha\end{pmatrix}$$

依据：分块乘法；$\alpha^T-(\alpha^TA^{-1})A=0$。

$$c=\begin{vmatrix}A&\alpha\\0&b-\alpha^TA^{-1}\alpha\end{vmatrix}=|A|\cdot\left(b-\alpha^TA^{-1}\alpha\right)$$

依据：分块三角行列式 = 对角块行列式之积（左下为零块，交叉项全消）。

