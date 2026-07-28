Car Driver is a simple game made in raylib

<img width="400" height="300" alt="car-driver-1" src="https://github.com/user-attachments/assets/1ec2ba0a-7e12-43fb-a655-d4f6e602a79e" />
<img width="400" height="300" alt="car-driver-2" src="https://github.com/user-attachments/assets/6098f3e2-587d-44c6-9d60-0f6c13f3636e" />

- Goal is to not get hit by enemy cars for as long as possible, but the longer you survive, faster the enemy cars are.
- You can add and remove road lanes and enemies. (game tries to not overlap enemies, so not all of them can appear at same time)

# How to play
## Pre-built binary
You can use the binary inside /binaries dir

## Build
Requirements
- Raylib
- cmake

To build it yourself use these commands. Path to build can be any folder you want

`cmake -B <path-to-build> -S <path-to-src>`
<br>
`cmake --build <path-to-build>`

Now build dir should have binary file you can run
