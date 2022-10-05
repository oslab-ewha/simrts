# simrts (SIMulator for Real-time Task Scheduling)

- This simulator aims to provide a reliable and precise tool to validate various realtime task scheduling policies.
- Currently supported policies are:
  - with DVS(Dynamic Voltage Scaling)
  - with HM(Hybrid Memory)
  - with DVS and HM
  - with greedy DVS and HM
  - Fixed scheduling via pre-generating tool such as [gastask](https://github.com/oslab-ewha/gastask)

## Build

- GNU tools(gcc, make) are required
- `$ make`
- `simrts` will be generated if a build succeeds.

## Configuration File

- Before running simrts, a configuration file is required.
- Below is a configuration sample:
```
# wcet_sacle power_active power_idle
*cpufreq
1    10    8
0.8   1.7  1.3

# type max_capacity wcet_scale power_active power_idle
*mem
dram  1000 1   0.1   0.1
nvram 1000 0.7 0.01  0.01

# wcet period memreq mem_active_ratio
*task
10 30   200 0.1
10 20   20  0.05
 1 20   20  0.1
```

## Running
### Usage
```
Usage: simrts <options> <config path>
 <options>
      -h: this message
      -v: verbose mode
      -t <max simulation time>: (default: 1000)
      -p <policy>: dvshm, dvsdram, hm, dram, fixed
```
