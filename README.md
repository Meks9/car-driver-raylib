Car Driver is simple game made in raylib

<img width="400" height="300" alt="car-driver-1" src="https://github.com/user-attachments/assets/1ec2ba0a-7e12-43fb-a655-d4f6e602a79e" />
<img width="400" height="300" alt="car-driver-2" src="https://github.com/user-attachments/assets/6098f3e2-587d-44c6-9d60-0f6c13f3636e" />

- Goal is to not get hit by enemy cars for as long as possible, but the longer you survive, faster the enemy cars are.
- You can add and remove road lanes and enemies. (game tries to not overlap enemies, so not all of them can appear at same time)

# Requirements
- Raylib
- cmake

# Build

To build it yourself use these commands:

`cmake -S <path-to-/car-driver-raylib/src> --preset default`

You should now have a build dir in car-driver-raylib

`cmake --build <path-to-/car-driver-raylib/build/>`

Now /build dir should have binary file you can run
