# Daemon Lord Engine

<table>
  <tr>
    <td width="200" valign="top">
      <img src="docs/banner.png" alt="Daemon Lord Engine Banner" width="180"/>
    </td>
    <td valign="top">
      A modern, experimental, high-performance <strong>C++23</strong> game engine currently in active development. Built primarily with <strong>Clang++</strong> for maximum adherence to the latest C++ standards and targeting <strong>Linux</strong>.
      <br><br>
      The repository includes a minimal <strong>Testbed</strong> project, which serves as a sandbox for validating core engine systems, rendering capabilities, and experimental features.
    </td>
  </tr>
</table>

---

## Badges

<!-- Replace badge links with actual ones later -->
![Language: C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)
![Build: Experimental](https://img.shields.io/badge/build-experimental-orange.svg)
![Status: In Development](https://img.shields.io/badge/status-in%20development-yellow.svg)
![License: TBD](https://img.shields.io/badge/license-TBD-lightgrey.svg)

---

## Features (Work-in-Progress)

- Modular engine architecture  
- Cross-platform C++23 codebase  
- Testbed sandbox for experimentation  
- Unified build script  
- **Planned Components:**
  - Rendering pipeline  
  - Scene graph  
  - Input handling  
  - Asset management  
  - Component-based / ECS architecture  
  - Editor tools  

---

## Build & Run

Both the **Engine** and **Testbed** are built through the `build.sh` script.

### **Prerequisites**
- **C++ Standard:** C++23  
- **Compiler:** Clang++  
- **Supported Platforms:** Linux (X11)
- **Build Script:** `build.sh`

---

### **Clean Engine and Testbed**
```sh
./build.sh clean
```

### **Build Debug or Relase**
```sh
./build.sh Debug
# or
./build.sh Release
```
