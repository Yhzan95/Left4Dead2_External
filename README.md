
# <p align="center">Left4Dead2 External Poc</p>
Left4Dead2 External Cheat is a proof-of-concept project for the Source Engine featuring an OS-ImGui overlay.<br>

This project is unfinished and can be optimized or extended with additional features. Unlike an internal cheat, it does not inject code into the game process. Instead, it creates an external overlay on top of the Left 4 Dead 2 game window.<br>

The application locates the `client.dll` and `engine.dll` module base addresses, uses known offsets (e.g. `dwLocalPlayer`) to read the game's memory, scans the entity list, and retrieves information such as entity positions, health, team, zombie class, and life state.<br>

For example, it can distinguish between Survivors, Special Infected (Smoker, Boomer, Hunter, Spitter, Jockey, and Charger), the Tank, the Witch, and Common Infected.<br>

It also reads the game's view matrix to transform 3D world coordinates into 2D screen coordinates, allowing ESP elements such as 2D boxes, snaplines, health bars, names, and distance indicators to be rendered accurately on the overlay.<br>

> ⚠️ **Disclaimer:** This project is intended for educational and research purposes only. Do **not** use it on VAC-secured or official servers, as doing so may result in a permanent ban.


<p align="center">
  <img src="https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/1.png?raw=true" width="49%">
  <img src="https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/2.png?raw=true" width="49%">
</p>

<p align="center">
  <img src="https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/3.png?raw=true" width="49%">
  <img src="https://github.com/Yhzan95/Left4Dead2_External/blob/main/Screenshots/4.png?raw=true" width="49%">
</p>

## 🧐 Features

### [Esp Visuals]
- Show Allies (Toggle On/Off)
- Esp Preview Box (With real time change)
- 2D Box ESP (Outlined)
- 2D Box ESP (Corner Only)
- Healthbar ESP
- Healthbar Text
- Distance ESP
- Snapline ESP
- Show Name ESP
- Hide Debug Console
- Adjustable Circle Fov (With slider)
  
### [Movements]
- Bunnyhop
  
### [Visuals]
- Custom Crosshairs (Cross,dot,circle,Tcross)

### [Custom Colors]
#### Survivors
- Snapline Color
- ESP Name Color
- Distance Color
- Health Value Color
- 2D Box / Corner Box Color

#### Special Infected
- Snapline Color
- ESP Name Color
- Distance Color
- Health Value Color
- 2D Box / Corner Box Color

#### Tank
- Snapline Color
- ESP Name Color
- Distance Color
- Health Value Color
- 2D Box / Corner Box Color

#### Common Infected
- Snapline Color
- ESP Name Color
- Distance Color
- Health Value Color
- 2D Box / Corner Box Color

#### Other
- Crosshair Color
- Reset Colors to Default

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

        
