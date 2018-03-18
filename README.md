# thermodynamic-solubility
A software implementation of a couple of my easily iterable solubility equations.

###### My first equation
It's very specific. It's to be used for water 1+1 cation-anion solutions and 1+1 cation-anion solute without the common ion effect. I made it for quick calculator usage requiring just the ans function.
Using a fuller expression of the... median activity method was it called? might be more useful.

![1+1 solution 1+1 solute](https://i.imgur.com/mLRAyL4.png)

Where:
* *C* stands for solution concentration in Molarity
* *Kps* stands for thermodynamic solubility constant, not solubility constant (e.g: Kps = activity1 \* activity2 = α1[c1] * α2*[c2])

###### Common-ion effect
This effect adds a little bit of complexity but comes from almost the same three equations. Its processed form is as follows:

![This is an image. It's the resolvent for second grade equations where A equals 1 , B equals the solution concentration and C equals Kps divided by ten to the minus 1,02 multiplied by the square root of the addition between the previous solubility and the solution's concentration](https://i.imgur.com/94ouT7g.png)
