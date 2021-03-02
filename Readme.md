CS 402 Homework 2
================
Muhammad Umar





















#### 1.5 Consider three different processors P1, P2, and P3 executing the same instruction set. P1 has a 3 GHz clock rate and a CPI of 1.5. P2 has a 2.5 GHz clock rate and a CPI of 1.0. P3 has a 4.0 GHz clock rate and has a CPI of 2.2.

##### a. Which processor has the highest performance expressed in instructions per second?

<table class="table" style="margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Clock (GHz)

</th>

<th style="text-align:right;">

CPI

</th>

<th style="text-align:right;">

Instructions Per Second

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

3.0

</td>

<td style="text-align:right;">

1.5

</td>

<td style="text-align:right;">

2.00e+09

</td>

</tr>

<tr>

<td style="text-align:right;">

2.5

</td>

<td style="text-align:right;">

1.0

</td>

<td style="text-align:right;">

2.50e+09

</td>

</tr>

<tr>

<td style="text-align:right;">

4.0

</td>

<td style="text-align:right;">

2.2

</td>

<td style="text-align:right;">

1.82e+09

</td>

</tr>

</tbody>

</table>

Hence, P2, has the highest performance with 250 million instructions per
second.

##### b. If the processors each execute a program in 10 seconds, find the number of cycles and the number of instructions.

<table class="table" style="width: auto !important; margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Clock (GHz)

</th>

<th style="text-align:right;">

CPI

</th>

<th style="text-align:right;">

Instructions Per Second

</th>

<th style="text-align:right;">

Cycles in 10 Seconds

</th>

<th style="text-align:right;">

Instructions in 10 Seconds

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

3.0

</td>

<td style="text-align:right;">

1.5

</td>

<td style="text-align:right;">

2.00e+09

</td>

<td style="text-align:right;">

3.0e+10

</td>

<td style="text-align:right;">

2.00e+10

</td>

</tr>

<tr>

<td style="text-align:right;">

2.5

</td>

<td style="text-align:right;">

1.0

</td>

<td style="text-align:right;">

2.50e+09

</td>

<td style="text-align:right;">

2.5e+10

</td>

<td style="text-align:right;">

2.50e+10

</td>

</tr>

<tr>

<td style="text-align:right;">

4.0

</td>

<td style="text-align:right;">

2.2

</td>

<td style="text-align:right;">

1.82e+09

</td>

<td style="text-align:right;">

4.0e+10

</td>

<td style="text-align:right;">

1.82e+10

</td>

</tr>

</tbody>

</table>

##### c. We are trying to reduce the execution time by 30% but this leads to an increase of 20% in the CPI. What clock rate should we have to get this time reduction?

New Execution time = 70% of Old Execution time

Execution time = Instructions \* (CPI / Clock Rate)

Therefore,

0.7 \* Execution Time = ((1.2 \* Instructions) \* CPI) / Clock Rate
Execution Time = (1.2 \* Instructions \* CPI) / 0.7 \* Clock Rate

So, New Clock Rate = (1.2 / 0.7) \* Clock Rate New Clock Rate = 1.714
Clock Rate

Hence,

Clock Rates should be increased by 1.714

<table class="table" style="margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Old Clocks (GHz)

</th>

<th style="text-align:right;">

New Clocks (GHz)

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

3.0

</td>

<td style="text-align:right;">

5.14

</td>

</tr>

<tr>

<td style="text-align:right;">

2.5

</td>

<td style="text-align:right;">

4.29

</td>

</tr>

<tr>

<td style="text-align:right;">

4.0

</td>

<td style="text-align:right;">

6.86

</td>

</tr>

</tbody>

</table>

#### 1.6 Consider two diff erent implementations of the same instruction set architecture. The instructions can be divided into four classes according to their CPI (class A, B, C, and D). P1 with a clock rate of 2.5 GHz and CPIs of 1, 2, 3, and 3, and P2 with a clock rate of 3 GHz and CPIs of 2, 2, 2, and 2. Given a program with a dynamic instruction count of 1.0E6 instructions divided into classes as follows: 10% class A, 20% class B, 50% class C, and 20% class D, which implementation is faster?

We can compare the execution time for each implementation to find out
which is faster.

Execution time = (Instructions \* CPI)/Clock Rate

Instructions = 10^6

Lets say “Instructions” = x

Cycles for P1 = 1 \* 0.1x + 2 \* 0.2x + 3 \* 0.5x + 3 \* 0.2x = 2.6x or
2.6 \* 10^6

Cycles for P2 = 0.2x = 2 \* 0.1x + 2 \* 0.2x + 2 \* 0.5x + 2 \* 0.2x =
2x or 2 \* 10^6

Execution Time for P1 = 2.6 \* 10^6 / 2.5\*10^9 = 1.0400e-03 seconds

Execution Time for P2 = 2 \* 10^6 / 3.0 \* 10^9 = 6.6667e-04 seconds

Hence, P2 is faster

##### a. What is the global CPI for each implementation?

CPI = Time\*Clock Rate / Instructions

CPI for P1 = 0.001 \* 2.5\*10^9 / 10^6 = 2.6 CPI

CPI for P2 = 0.001 \* 3.0\*10^9 / 10^6 = 2.0 CPI

##### b. Find the clock cycles required in both cases.

Clock cycles = CPI \* Instructions

Clock cycles for P1 = 2.6 \* 10^6 cycles

Clock cycles for P2 = 2.0 \* 10^6 cycles

#### 1.7 Compilers can have a profound impact on the performance of an application. Assume that for a program, compiler A results in a dynamic instruction count of 1.0E9 and has an execution time of 1.1 s, while compiler B results in a dynamic instruction count of 1.2E9 and an execution time of 1.5 s

##### a. Find the average CPI for each program given that the processor has a clock cycle time of 1 ns

Time = Instructions \* CPI / Clock Rate or Instructions \* CPI \* Cycle
Time

CPI = Time / Instructions \* Cycle Time

CPI for Compiler A = 1.1 / ((1\* 10^9) \* 1 \* 10^-9) = 1.1 CPI CPI for
Compiler B = 1.5 / ((1.2 \* 10^9) \* 1 \* 10^-9) = 1.25 CPI

##### b. Assume the compiled programs run on two different processors. If the execution times on the two processors are the same, how much faster is the clock of the processor running compiler A’s code versus the clock of the processor running compiler B’s code?

Execution Time = Instructions \* CPI / Clock Rate

(10^9 \* 1.1)/ ClockRateA = (1.2 \* 10^9) \* 1.25 / ClockRateB

ClockRateA = 1.1 / (1.2 \* 1.25) ClockRateB

ClockRateA = 0.733 ClockRateB

Hence, processor A is actually 26.7% slower than processor B or 73.3%
the speed of processor B.

##### c. A new compiler is developed that uses only 6.0E8 instructions and has an average CPI of 1.1. What is the speedup of using this new compiler versus using compiler A or B on the original processor?

CPU Time for New Compiler = Instructions 3 \* CPI 3 / Clock Rate

CPU Time for New Compiler = 6 \* 10^8 \* 1.1 \* 10^-9 / Clock Rate

CPU Time for New Compiler = 0.66 / Clock Rate

SpeedUp Compiler C versus A = 1.1 / 0.66 = 1.67

SpeedUp Compiler C versus B = 1.5 / 0.66 = 2.27

Hence, Compiler C is 1.67 times faster than Compiler A while it is 2.27
times faster than Compiler B

#### 1.9 Assume for arithmetic, load/store, and branch instructions, a processor has CPIs of 1, 12, and 5, respectively. Also assume that on a single processor a program requires the execution of 2.56E9 arithmetic instructions, 1.28E9 load/store instructions, and 256 million branch instructions. Assume that each processor has a 2 GHz clock frequency.

#### Assume that, as the program is parallelized to run over multiple cores, the number of arithmetic and load/store instructions per processor is divided by 0.7 x p (where p is the number of processors) but the number of branch instructions per processor remains the same.

Execution time = (Instructions \* CPI)/Clock Rate or Cycles/Clock Rate

Cycles = (2.56 \* 10^9) \* 1 + (1.28 \* 10^9) \* 12 + (256 \* 10^6) \* 5

Cycles = 1.9210^{10}

Execution Time = 1.9210^{10}/2.0 GHz = 9.6 seconds

Parallel Cycles = (2.56 \* 10^9)/0.7p \* 1 + (1.28 \* 10^9)/0.7p \* 12 +
(256 \* 10^6) \* 5 \* 1

Parallel Cycles = 2.5610^{10}/p + 1.2810^{9}

Parallel execution time = ((2.5610^{10}/p) +
1.2810<sup>{9})/210</sup>{9} = 12.8/p + 0.64

##### 1.9.1 Find the total execution time for this program on 1, 2, 4, and 8 processors, and show the relative speedup of the 2, 4, and 8 processor result relative to the single processor result.

Execution Time for 1 Processor = 9.6s

Execution Time for 2 processors = 12.8/((2/2)\* 2.0) + 0.64 = 7.04s

Execution Time for 4 processors = 12.8/((4/2) \* 2.0) + 0.64 = 3.84s

Execution Time for 8 processors = 12.8/((8/2) \* 2.0) + 0.64 = 2.24s

<table class="table" style="margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Processors

</th>

<th style="text-align:right;">

Time (s)

</th>

<th style="text-align:right;">

Speed Up

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

1

</td>

<td style="text-align:right;">

9.60

</td>

<td style="text-align:right;">

1.00

</td>

</tr>

<tr>

<td style="text-align:right;">

2

</td>

<td style="text-align:right;">

7.04

</td>

<td style="text-align:right;">

1.36

</td>

</tr>

<tr>

<td style="text-align:right;">

4

</td>

<td style="text-align:right;">

3.84

</td>

<td style="text-align:right;">

2.50

</td>

</tr>

<tr>

<td style="text-align:right;">

8

</td>

<td style="text-align:right;">

2.24

</td>

<td style="text-align:right;">

4.29

</td>

</tr>

</tbody>

</table>

##### 1.9.2 If the CPI of the arithmetic instructions was doubled, what would the impact be on the execution time of the program on 1, 2, 4, or 8 processors?

Execution time = (Instructions \* CPI)/Clock Rate or Cycles/Clock Rate

Cycles = (2 \* 2.56 \* 10^9) \* 1 + (1.28 \* 10^9) \* 12 + (256 \* 10^6)
\* 5

Cycles = 2.17610^{10}

Execution Time = 2.17610^{10}/2.0 GHz = 10.88 seconds

Parallel Cycles = (2 \* 2.56 \* 10^9)/0.7p \* 1 + (1.28 \* 10^9)/0.7p \*
12 + (256 \* 10^6) \* 5 \* 1

Parallel Cycles = 2.92610^{10}/p + 1.2810^{9}

Parallel Execution Time = ((2.92610^{10}/p) +
1.2810<sup>{9})/210</sup>{9}

Parallel Execution Time = 14.629/p + 0.64

Execution Time for 1 Processor = 10.88s

Execution Time for 2 processors = 12.8/((2/2)\* 2.0) + 0.64 = 7.954

Execution Time for 4 processors = 14.629/((4/2) \* 2.0) + 0.64 = 4.297

Execution Time for 8 processors = 14.629/((8/2) \* 2.0) + 0.64 = 2.469

<table class="table" style="margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Processors

</th>

<th style="text-align:right;">

Time (s)

</th>

<th style="text-align:right;">

Speed Up

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

1

</td>

<td style="text-align:right;">

10.88

</td>

<td style="text-align:right;">

1.00

</td>

</tr>

<tr>

<td style="text-align:right;">

2

</td>

<td style="text-align:right;">

7.95

</td>

<td style="text-align:right;">

1.37

</td>

</tr>

<tr>

<td style="text-align:right;">

4

</td>

<td style="text-align:right;">

4.30

</td>

<td style="text-align:right;">

2.53

</td>

</tr>

<tr>

<td style="text-align:right;">

8

</td>

<td style="text-align:right;">

2.47

</td>

<td style="text-align:right;">

4.41

</td>

</tr>

</tbody>

</table>

Surprisingly, the impact of doubling the instructions isn’t significant
and only seems to have some impact in speedup at 8 processors.

##### 1.9.3 To what should the CPI of load/store instructions be reduced in order for a single processor to match the performance of four processors using the original CPI values?

For this to be true, we must assume the execution time of 1 processor to
be equivalent to that of 4 processors.

New Execution time for 1 processor = 3.84s

\= New Clock Cycles / 2.0 Ghz = 3.84s

\= New Clock Cycles = 7.6810^{9}

Hence,

New CPI = (2.56 \* 10^9) \* 1 + (1.28 \* 10^9) \* New CPI + (256 \*
10^6) \* 5 = 7.6810^{9} CPI

3.8410^{9} + 1.2810^{9}new CPI = 7.6810^{9}

new CPI = 3.8410^{9}/(1.28 \* 10^9)

new CPI for Load/Store = 3 CPI

Hence, the CPI for load/store should be reduced to 3 from 12 for 1
processor to match the performance of 4 processors.

#### 1.11 The results of the SPEC CPU2006 bzip2 benchmark running on an AMD Barcelona has an instruction count of 2.389E12, an execution time of 750 s, and a reference time of 9650 s.

##### 1.11.1 Find the CPI if the clock cycle time is 0.333 ns.

Execution time = (Instructions \* CPI) \* Clock Cycle or Cycles \* Clock
Cycle

CPI = Execution Time/(Clock Cycle \* Instructions)

CPI = 750 / ((0.333 \* 10^-9) \* (2.389 \* 10^12))

CPI = 0.943 CPI

##### 1.11.2 Find the SPECratio.

SPEC ratio = Reference time / Execution Time

SPEC ratio = 9650 / 750 = 12.867

##### 1.11.3 Find the increase in CPU time if the number of instructions of the benchmark is increased by 10% without affecting the CPI.

Execution Time (CPU Time) = 1.1 \* (2.389 \* 10^12) \* 0.94 \* (0.333 \*
10^-9)

Execution Time (CPU Time) = 822.585 seconds

##### 1.11.4 Find the increase in CPU time if the number of instructions of the benchmark is increased by 10% and the CPI is increased by 5%.

Execution Time (CPU Time) = 1.1 \* (2.389 \* 10^12) \* 1.05 \* 0.94 \*
(0.333 \* 10^-9)

Execution Time (CPU Time) = 863.715 seconds

##### 1.11.5 Find the change in the SPECratio for this change.

SPEC ratio = Reference time / Execution Time

New Spec Ratio = 9650 / 863.715 = 11.173

Change in Spec Ratio = 12.867 - 11.173 = 1.694

Hence the new SPEC ratio is 11.173 and the change from original SPEC
ratio is 1.694

##### 1.11.6 Suppose that we are developing a new version of the AMD Barcelona processor with a 4 GHz clock rate. We have added some additional instructions to the instruction set in such a way that the number of instructions has been reduced by 15%. Th e execution time is reduced to 700 s and the new SPECratio is 13.7. Find the new CPI.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

CPI = (Execution Time \* Clock Rate )/ Instructions

CPI = (700 \* 4 \* 10^9) / (0.85 \* 2.389 \* 10^12)

CPI = 1.379 CPI

##### 1.11.7 This CPI value is larger than obtained in 1.11.1 as the clock rate was increased from 3 GHz to 4 GHz. Determine whether the increase in the CPI is similar to that of the clock rate. If they are dissimilar, why?

Original Clock Rate = 1/0.333 \* 10^-9 = 3.00310^{9} or 3 GHz

Clock Rate Increase Ratio = 4 GHz/3 GHz = 1.333

CPI Increase ratio = 1.379 / 0.943 = 1.463

Hence, the increase in CPI is dissimilar to that of Clock Rate because
we also reduced instructions by 15% for the new CPI.

##### 1.11.8 By how much has the CPU time been reduced?

CPU Time Decrease Ratio = 700 / 750 = 0.933 or 93.3%

Hence, the CPU Time has decreased by 6.67%

##### 1.11.9 For a second benchmark, libquantum, assume an execution time of 960 ns, CPI of 1.61, and clock rate of 3 GHz. If the execution time is reduced by an additional 10% without affecting to the CPI and with a clock rate of 4 GHz, determine the number of instructions.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Instructions = (Execution Time \* Clock Rate )/ CPI

Instructions = (0.9 \* 960 \* 10^-9 \* 4 \* 10^9) / 1.61 = 2146.584

##### 1.11.10 Determine the clock rate required to give a further 10% reduction in CPU time while maintaining the number of instructions and with the CPI unchanged.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Clock Rate = (Instructions \* CPI) / Execution Time

Clock Rate = (2146.584 \* 1.61) / 0.9 \* (0.9 \* 960)

Clock Rate = 4.444 GHz

##### 1.11.11 Determine the clock rate if the CPI is reduced by 15% and the CPU time by 20% while the number of instructions is unchanged.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Clock Rate = (Instructions \* CPI) / Execution Time

Clock Rate = (2146.584 \* (0.85 \* 1.61)) / (0.8 \* (0.9 \* (0.9 \*
960))

Clock Rate = 4.722 GHz

#### 1.12 Section 1.10 cites as a pitfall the utilization of a subset of the performance equation as a performance metric. To illustrate this, consider the following two processors. P1 has a clock rate of 4 GHz, average CPI of 0.9, and requires the execution of 5.0E9 instructions. P2 has a clock rate of 3 GHz, an average CPI of 0.75, and requires the execution of 1.0E9 instructions.

##### 1.12.1 One usual fallacy is to consider the computer with the largest clock rate as having the largest performance. Check if this is true for P1 and P2.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Execution Time for P1 = (5 \* 10^9 \* 0.9) / (4.0\*10^9) = 1.125s

Execution Time for P2 = (1 \* 10^9 \* 0.75) / (3.0\*10^9) = 0.25s

This is indeed, a fallacy. P2 is quite a lot faster than P1.

##### 1.12.2 Another fallacy is to consider that the processor executing the largest number of instructions will need a larger CPU time. Considering that processor P1 is executing a sequence of 1.0E9 instructions and that the CPI of processors P1 and P2 do not change, determine the number of instructions that P2 can execute in the same time that P1 needs to execute 1.0E9 instructions.

Execution time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Execution Time for P1 = (1 \* 10^9 \* 0.9) / (4.0\*10^9) = 0.225s

Instructions for P2 with P1 execution time = (0.225 \* (3.0\*10^9))/0.75

Instructions for P2 with P1 execution time = 910^{8} instructions

##### 1.12.3 A common fallacy is to use MIPS (millions of instructions per second) to compare the performance of two different processors, and consider that the processor with the largest MIPS has the largest performance. Check if this is true for P1 and P2.

MIPS = Clock Rate / (CPI \* 10^6)

MIPS for P1 = (4 \* 10^9) / (0.9 \* 10^6) = 4444.444

MIPS for P2 = (3 \* 10^9) / (0.75 \* 10^6) = 4000

Yes, its a fallacy as P2 is faster in reality while the MIPS metric
implies that P1 is faster.

##### 1.12.4 Another common performance figure is MFLOPS (millions of floating-point operations per second), defined as MFLOPS = No. FP operations / (execution time x 1E6) but this figure has the same problems as MIPS. Assume that 40% of the instructions executed on both P1 and P2 are floating-point instructions. Find the MFLOPS figures for the programs.

MFLOPS = FLOP Instructions / (Time \* Million)

MFLOPS for P1 = (0.4 \* 5 \* 10^9) / (1.125\* 10^6) = 1777.778

MFLOPS for P2 = (0.4 \* 1 \* 10^9) / (0.25\* 10^6) = 1600

Even the MFLOPS test seems to favor P1 while P2 is actually faster,
hence MFLOPS is a fallacy.

#### 1.13 Another pitfall cited is expecting to improve the overall performance of a computer by improving only one aspect of the computer. Consider a computer running a program that requires 250 s, with 70 s spent executing FP instructions, 85 s executed L/S instructions, and 40 s spent executing branch instructions.

##### 1.13.1 By how much is the total time reduced if the time for FP operations is reduced by 20%?

Total Time reduced with 80% FP time = 70 - (0.8 \* 70) Total Time
reduced with 80% FP time = 14

Hence the total time will be reduced by 14 seconds bringing it to 236
seconds or by 5.6%.

##### 1.13.2 By how much is the time for INT operations reduced if the total time is reduced by 20%?

Total reduced by 80% = 0.8 \* 250 = 200

Assuming the remaining time after taking out FP, L/S and branch
instructions is used for INT operations, then

Old time spent on INT operations = 250 - 70 - 40 - 85 = 55

New time spent on INT operations = 200 - 70 - 40 - 85 = 5

Hence the time spent on INT operations will be reduced by 50 seconds or
by 90.909%.

##### 1.13.3 Can the total time can be reduced by 20% by reducing only the time for branch instructions?

Assume we use minimal branch instructions or none, lets find the maximum
time saved and see if the savings fall under the 20% threshold

Total time with minimal branch instructions = FP Time + L/S Time + INT
Time

\= 70 + 85 + 55 = 210

Percentage of savings = (1 - (210 / 250)) \* 100 = 16%

Hence, no, the total time can only be reduced by a maximum of 18% by
reducing branch instructions and not 20%

#### 1.14 Assume a program requires the execution of 50 x 106 FP instructions, 110 x 106 INT instructions, 80 x 106 L/S instructions, and 16 x 106 branch instructions. The CPI for each type of instruction is 1, 1, 4, and 2, respectively. Assume that the processor has a 2 GHz clock rate.

Execution Time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Total Cycles = Instructions \* CPI

Total Cycles = (50 \* 106 \* 1) + (110 \* 106 \* 1) + (80 \* 106 \* 4) +
(16 \* 106 \* 2) = 54272

Execution Time = 54272 / (2 \* 10^9) = 2.71410^{-5} s or 27.136us

##### 1.14.1 By how much must we improve the CPI of FP instructions if we want the program to run two times faster?

New Execution Time = Execution Time / 2 = 1.35710^{-5}

Execution Time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

New Total Cycles = (50 \* 106 \* NewCPI) + (110 \* 106 \* 1) + (80 \*
106 \* 4) + (16 \* 106 \* 2)

New Total Cycles = 5300 \* NewCPI + 48972

Execution Time = Cycles / Clock Rate

Cycles = Execution Time \* Clock Rate

5300 \* newCPI + 48972 = 1.35710^{-5} \* (2 \* 10^9)

newCPI = (27136 - 48972) / 5300

newCPI = -4.12 CPI

It is impossible to run the program twice as fast by only improving FP
instructions CPI as shown by the negative result.

##### 1.14.2 By how much must we improve the CPI of L/S instructions if we want the program to run two times faster?

New Execution Time = Execution Time / 2 = 1.35710^{-5}

Execution Time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

New Total Cycles = (50 \* 106 \* 1) + (110 \* 106 \* 1) + (80 \* 106 \*
newCPI) + (16 \* 106 \* 2)

New Total Cycles = 20352 + 8480 \* newCPI

Execution Time = Cycles / Clock Rate

Cycles = Execution Time \* Clock Rate

8480 \* newCPI + 20352 = 1.35710^{-5} \* (2 \* 10^9)

newCPI = (27136 - 20352) / 8480

newCPI = 0.8 CPI

Hence L/S instructions must be improved to decrease CPI from 4 to 0.8 or
reduced by 80%

##### 1.14.3 By how much is the execution time of the program improved if the CPI of INT and FP instructions is reduced by 40% and the CPI of L/S and Branch is reduced by 30%?

Execution Time = (Instructions \* CPI) / Clock Rate or Cycles / Clock
Rate

Total Cycles = Instructions \* CPI

Total Cycles = (0.6 \* 50 \* 106 \* 1) + (0.6 \* 110 \* 106 \* 1) + (0.7
\* 80 \* 106 \* 4) + (0.7 \* 16 \* 106 \* 2) = 36294.4

Execution Time = 36294.4 / (2 \* 10^9) = 1.81510^{-5} s or 18.147us

Hence the execution time improved from 2.71410^{-5} to 1.81510^{-5} or
by 33.125%

#### 1.15 When a program is adapted to run on multiple processors in a multiprocessor system, the execution time on each processor is comprised of computing time and the overhead time required for locked critical sections and/or to send data from one processor to another. Assume a program requires t = 100 s of execution time on one processor. When run p processors, each processor requires t/p s, as well as an additional 4 s of overhead, irrespective of the number of processors. Compute the per-processor execution time for 2, 4, 8, 16, 32, 64, and 128 processors. For each case, list the corresponding speedup relative to a single processor and the ratio between actual speedup versus ideal speedup (speedup if there was no overhead).

<table class="table" style="margin-left: auto; margin-right: auto;">

<thead>

<tr>

<th style="text-align:right;">

Processors

</th>

<th style="text-align:right;">

Time (s)

</th>

<th style="text-align:right;">

Speed Up (%)

</th>

<th style="text-align:right;">

Ideal Time (s)

</th>

<th style="text-align:right;">

Ideal Speed Up (%)

</th>

<th style="text-align:right;">

Actual vs Ideal Speed Up Ratio

</th>

</tr>

</thead>

<tbody>

<tr>

<td style="text-align:right;">

2

</td>

<td style="text-align:right;">

54.00

</td>

<td style="text-align:right;">

46.0

</td>

<td style="text-align:right;">

50.000

</td>

<td style="text-align:right;">

50.0

</td>

<td style="text-align:right;">

0.920

</td>

</tr>

<tr>

<td style="text-align:right;">

4

</td>

<td style="text-align:right;">

29.00

</td>

<td style="text-align:right;">

71.0

</td>

<td style="text-align:right;">

25.000

</td>

<td style="text-align:right;">

75.0

</td>

<td style="text-align:right;">

0.947

</td>

</tr>

<tr>

<td style="text-align:right;">

8

</td>

<td style="text-align:right;">

16.50

</td>

<td style="text-align:right;">

83.5

</td>

<td style="text-align:right;">

12.500

</td>

<td style="text-align:right;">

87.5

</td>

<td style="text-align:right;">

0.954

</td>

</tr>

<tr>

<td style="text-align:right;">

16

</td>

<td style="text-align:right;">

10.25

</td>

<td style="text-align:right;">

89.8

</td>

<td style="text-align:right;">

6.250

</td>

<td style="text-align:right;">

93.8

</td>

<td style="text-align:right;">

0.957

</td>

</tr>

<tr>

<td style="text-align:right;">

32

</td>

<td style="text-align:right;">

7.12

</td>

<td style="text-align:right;">

92.9

</td>

<td style="text-align:right;">

3.125

</td>

<td style="text-align:right;">

96.9

</td>

<td style="text-align:right;">

0.959

</td>

</tr>

<tr>

<td style="text-align:right;">

64

</td>

<td style="text-align:right;">

5.56

</td>

<td style="text-align:right;">

94.4

</td>

<td style="text-align:right;">

1.562

</td>

<td style="text-align:right;">

98.4

</td>

<td style="text-align:right;">

0.959

</td>

</tr>

<tr>

<td style="text-align:right;">

128

</td>

<td style="text-align:right;">

4.78

</td>

<td style="text-align:right;">

95.2

</td>

<td style="text-align:right;">

0.781

</td>

<td style="text-align:right;">

99.2

</td>

<td style="text-align:right;">

0.960

</td>

</tr>

</tbody>

</table>
