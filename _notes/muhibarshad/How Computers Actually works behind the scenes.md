---
title: How Computers Actually Work Behind the Scenes
tags:
  - Computer Science
slug: how-computers-actually-works-behind-the-scenes
date: 2025-05-26 21:45:00
---
In ancient times, people created a simple abacus to identify numbers and perform arithmetic operations, such as addition and subtraction. Did you know that before 1800, the term "computer" referred to a person who used any machine or performed extensive calculations on their own? Later, it came to be associated with machines that carried out mathematical operations. During World War II, handwritten square roots were used by people to calculate and launch bombs.

At some point, people began to consider the need for a machine that could perform the same mathematical operations as humans, including problem-solving and solving complex equations. They adopted the same techniques that humans used.
Suppose I give you a problem to add 2+2. What can your brain do?

Firstly, it receives the input, which is two numbers, 2 and 2, that need to be added.

Secondly, it temporarily stores this information in your brain's memory.

Thirdly, your brain processes the given input according to the standards it has been trained on.

Finally, your brain outputs the result, which is 4, based on the processed information.

This concept formed the basis for scientists to consider developing a similar machine.

The idea was eventually developed, but a challenge arose. Just as humans understand words, numbers, languages, and written scripts, how can we make a machine comprehend the meaning behind words like "2" or "5"?

During that time, when electricity was at its peak, scientists had the idea to utilize it for language processing. Although it may seem strange, it is indeed true.

They devised a binary language based on the electrical state of being either "on" or "off," represented by 0 and 1 in base 2.
Now a problem arises: they developed a language for communicating with the machine, but how will the machine understand it, make decisions based on it, and modify numbers accordingly?

They utilized circuits or the flow of current, representing "on" (1) and "off" (0). However, another issue emerged regarding how to switch these states. Manually using batteries was not a viable solution. To address this, they employed Vacuum tubes, which consisted of a cathode, grid, and anode. When a high current passed through, the cathode emitted electrons, allowing the circuit to close (1), and when a low current was present, the cathode did not move electrons, causing the circuit to open (0).

However, a new problem arose: the size of Vacuum tubes was excessively large. A single computer required multiple tubes, occupying an entire room. Furthermore, the high temperature of the cathode caused the tubes to burn out, necessitating frequent manual replacements.
The biggest revolution in history came with the invention of transistors, which are tiny semiconductor devices made of silicon (4). When a high voltage is applied to its base, current is emitted from its emitter (1), turning it into a conductor under specific conditions and an insulator (0) under specific conditions. Transistors also utilize materials such as phosphorus (5) and bismuth (3), which help control the flow of current when a low voltage is applied, creating a depletion bridge on the P-Type charge.

However, a new challenge arises: we have developed a system to represent information using binaries, but how can we modify them and obtain modified output based on the input? In other words, how can we process the data?

For processing, we can start by performing common operations such as addition, like 2 + 2, in binary and observe the results. Through these operations, we discover that the results of these calculations can be represented by logical units such as the AND gate for the carry and the XOR gate for the sum.

For example, when we add two "1" digits together, we obtain the result "2," which in binary is represented as "10." Therefore, the output for the sum becomes "0" and a carry of "1" is propagated to the next digit.
Similarly,

1 0 = 1 
0 1 = 1
1 1 = 0
0 0 = 0

For the following queries: 
1 1 = 1 
1 0 = 0
0 1 = 0
0 0 = 0

We implement these logic gates using transistors and abstract them as gates. By combining the XOR and AND gates, we can create a 2-bit adder. By joining two adders, we can develop a 4-bit adder. To create a subtractor, we take the complement of a binary number, add 1 to it, and then input it into the adder. This entire system forms the Algorithmic Logical Unit (ALU). The ALU is then connected to the Control Unit, registers, and RAM.

To execute instructions, we store them in the RAM, specifying where inputs are stored, which operations to perform, and where to store the results in the RAM. The Control Unit fetches instructions from the RAM, inputs corresponding values into its registers and the processing part of the ALU. The results from the ALU are then stored back in the appropriate location in the RAM, as specified by the instructions. This process allows us to create a simple computer.
