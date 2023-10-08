Любое целое число можно можно представить в виде многочлена.

$$
\large a \normalsize= \sum_{i=0}^t a_{i}p^i \quad
\begin{matrix}
p \text{ осонование системы счисления} \\
a_{i} \text{ цифра числа $a$ с индексом $i$} \\
t \text{ количество цифр в числе $a$}
\end{matrix}
$$

Пример

$$
\begin{matrix}
a=678&=&8\cdot 10^0&+&7\cdot 10^1&+&6\cdot 10^2 \\
&&a_{0}\cdot 10^0&+&a_{1}\cdot 10^1&+&a_{2}\cdot 10^2
\end{matrix}
$$

### Идея.
Число можно разбить пополам.

$$
a=\underbracket{578}_{c}\underbracket{277}_{d}=c\cdot 10^3+d
$$

В общем виде. Число $a$ с разрядностью $n=2k \quad k \in \mathbb{N}$
Можно записать как

$$
a= c\cdot p^{n/2}+d
$$

Попробуем перемножить два числа $u$, $v$.

$$
\begin{align}
\Large u\cdot v\normalsize= (u_{0}\cdot p^{n/2}+u_{1}) \cdot (v_{0}\cdot p^{n/2}+v_{1})= \\
= u_{0}v_{0}\cdot p^n+(u_{0}v_{1} \cdot p^{n/2} +u_{1}v_{0}\cdot p^{n/2})+u_{1}v_{1}= \\
=u_{0}v_{0}\cdot p^n +  p^{n/2}\cdot(\;\boxed{u_{0}v_{1} + u_{1}v_{0}}\;) + u_{1}v_{1}
\end{align}
$$

Теперь обозначим

$$
\begin{matrix}
x=u_{0}\cdot v_{0} \\
y=u_{1}\cdot v_{1} \\
z=(u_{0}+u_{1})(v_{0}+v_{1})
\end{matrix}
$$

Заметим, что $z-x-y=\underbracket{u_{0}v_{0}+u_{0}v_{1}+u_{1}v_{0}+u_{1}v_{1}}_{z}-\underbracket{u_{0}v_{0}}_{x}-\underbracket{u_{1}v_{1}}_{y}=\boxed{u_{0}v_{1}+u_{1}v_{0}}$  
т.е

$$
\Large u \cdot v\normalsize= x\cdot p^{n}
+p^{n/2}\cdot(z-x-y)+y
$$
