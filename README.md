
# <p align="center">Left4Dead2 External Poc</p>
Left4Dead2 External Cheat is a proof-of-concept project for the old Source Engine, featuring an OS-ImGui overlay.
This project is unfinished and can be optimized or extended with more features.
It does not inject anything into the game process instead, it creates an external overlay on top of the Left 4 Dead 2 window.
The application locates the client.dll and engine.dll module base addresses, uses known offsets (eg: dwLocalPlayer) to read the game's memory,
scans the entity list, and retrieves information such as entity positions, health, team, zombie class, and life state. 
For example it can distinguish between Survivors, Special Infected (Smoker, Boomer, Hunter, Spitter, Jockey, Charger), the Tank, the Witch, and Common Infected.
It also reads the game's view matrix to transform 3D world coordinates into 2D screen coordinates,
allowing ESP elements such as 2D boxes, snaplines, health bars, names, and distance indicators to be rendered accurately on the overlay.
⚠ This project is intended for educational and research purposes only. Do not use it on VAC-secured or official servers, as you may be permanently banned ⚠

|--------|-------|
| ![Image 1](https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/1.png?raw=true) | ![Image 2](https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/2.png?raw=true) |
| ![Image 3](https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/3.png?raw=true) | ![Image 4](https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/4.png?raw=true) |

## 🧐 Features
### [Cheats]
- Infinite Ammo
- GodMod (Infinite Health)
### [Visuals]
- Wireframe Wallhack
- Asus Wallhack (Buggy)
- Draw Decals
- Luxels
- Skeleton ESP
- Minecraft Mod
- Tracer ESP
### [Debug]
- Weapon Debug
- Box Debug Entity
- Draw Debug Overlay
- Draw Render Box
- Debug Vgui Panel
- Draw Static Props
- Draw World
- Draw Footsteps
### [CheatEngine table included]

## 🛠️ Install Dependencies
```bash
Visual Studio 2022
Windows SDK
OS-ImGui (included)
No additional third-party libraries are required.
```
🧑🏻‍💻 Usage
```js
1) Launch Left4Dead2
2) Launch Left4dead2 external
3) Press Insert to open or close the menu
4) Enable or disable the desired features
Note: Make sure the game is running in Windowed or Borderless Windowed mode so the overlay can be displayed correctly.
```

## 🙇 Acknowledgements      
- [OsImgui By Tkazer](https://github.com/TKazer/OS-ImGui)

## ❤️ Support  
If you like this project, don't forget to leave a star on GitHub. Your support is greatly appreciated!

## 🙇 Author
#### Yhzan95
- Email: [Yhzan95@protonmail.com]()
        
## ➤ License
Distributed under the MIT License. See [LICENSE](LICENSE) for more information.

        
