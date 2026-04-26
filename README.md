#  Frostbound

### *Object-Oriented Programming (CS-2001) — Semester Project*

---

##  Project Description

**Frostbound** is a tactical, console-based **Role-Playing Game (RPG)** developed in **C++**. The system simulates a survival environment where players manage resources like _health_, _gold_, and _stamina_ while navigating through increasingly difficult dungeon levels.

The project demonstrates the practical application of core **OOP principles**:

- **Inheritance** — Shared character base class extended by specialized types
- **Polymorphism** — Dynamic attack behavior across character classes
- **Data Persistence** — Game state saved and loaded via File I/O

---

## Group Members

| Name | Student ID |
|:-----|:----------:|
| **Arsal Ali Rehmat Ullah Ali** | 25K-0968 |
| **Ali Naqi Khoso**             | 25K-0989 |
| **Moawiz Ahmed**               | 25K-0518 |

---

## Use Cases

1. **Character Customization**
   Select from three distinct classes — _Warrior_, _Rogue_, or _Tank_ — each with unique base stats for **HP**, **Attack**, and **Defense**.

2. **Tactical Combat**
   Evaluate player choices (**Basic**, **Special**, or **Ultimate** attacks) against a stamina-cost requirement. If stamina is insufficient, the attack fails and no damage is dealt.

3. **Dynamic Inventory Management**
   Purchase armor sets *(Helmet, Chestplate, Leggings, Boots)*, shields, and potions from a **persistent shop**.

4. **Free-Action Consumables**
   Restore **health or stamina** during a battle sequence _without_ forfeiting your turn to the enemy.

5. **Progress Persistence**
   Write the current game state *(Stats, Level, Inventory)* to a local file and retrieve it upon restart.

6. **Hub Exploration**
   Between battles, visit a **Merchant**, check detailed stats, or **save your game** before proceeding to higher levels.

---

## Compilation Instructions

> **Requirement:** A C++ compiler such as **MinGW/GCC** must be installed.

The project is modularized into header (`.h`) and source (`.cpp`) files.

**Steps:**

1. Open your **terminal** or **command prompt**
2. Navigate to the **project root directory**
3. Run the following command:

```bash
g++ source/*.cpp -o Frostbound
```

---

## Execution Instructions

After successful compilation, run the executable:

**Windows:**
```bash
Frostbound.exe
```

**Linux / macOS:**
```bash
./Frostbound
```

---

## How to Use the System

**Starting the Game**
- Choose `"Start New Journey"` to create a new character
- Choose `"Continue"` to load progress from `save.txt`
- _If the save file is missing or empty, the system will prompt you to start fresh_

**Navigating the Hub**
- Use **numeric inputs (1–5)** to select activities:
  - `1` → Dungeon (Combat)
  - `2` → Shop
  - `3` → Check Stats
  - `4` → Save Game
  - `5` → Exit

**Combat**
- Select your attack type each turn
- Monitor your **STM (Stamina)** bar closely
- _If stamina runs low_, use a **Stamina Potion** from the inventory menu without losing your turn

**Shopping**
- Enter the shop and buy multiple items freely
- You will remain in the shop menu until you **manually select "Exit" (Option 9)**

**Game Over**
- If your **HP reaches zero**, the journey ends
- Return to the main menu to restart from the beginning

---

## Assumptions and Limitations

> The following constraints and assumptions apply to the current version of the system:

| # | Category | Detail |
|---|----------|--------|
| 1 | **File Directory** | A folder named `data/` must exist in the root directory for `save.txt` and `info.txt` |
| 2 | **Input Type** | The system assumes **numeric input** for all menus; basic buffer clearing is implemented to prevent infinite loops from character inputs |
| 3 | **Resolution** | Designed for a **standard 80-column console** window |
| 4 | **Inventory Size** | The inventory system is optimized for **up to 10 items** |
| 5 | **Memory Management** | Dynamic memory is **cleared upon player death** to prevent memory leaks |

---

*Developed for **FAST-NUCES BCS** — OOP Lab*
