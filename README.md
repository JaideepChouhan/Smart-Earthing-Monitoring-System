# AIER Meter System — Anti-Pilfering & Earthing Health Monitoring Network  
**SIH 2023 (Idea Submission)**  
**Team:** AIR Revolutionaries | ECE, 1st Semester

---

## Problem We Addressed

Electricity theft (power pilferage) is a major reason for:
* Revenue loss in power distribution
* Overloading of transformers
* Unstable supply and blackouts

In most residential and rural networks, **there is no real-time monitoring** to verify how much electricity is supplied vs how much is actually billed.  
Any difference goes unnoticed — until losses accumulate.

At the same time, **faulty or weak earthing** can cause:
* Leakage currents
* Shocks
* Equipment damage

So we designed a system that detects **both**:
* **Power Theft**
* **Earthing Leakage Faults**

---

## What Is AIER Meter System?

A **chain-connected network of smart meters** that compares current flow at each level of distribution to detect any abnormal loss or unaccounted usage.

| Device | Role | Installed At |
|-------|------|--------------|
| **Home Meter** | Measures power used by a consumer & detects leakage | Individual Homes / Loads |
| **DA (Distribution Analyzer)** | Compares sum of multiple Home Meters | Local Distribution Box |
| **DP Head (Main Head Unit)** | Compares DA readings & sends alert via GSM | Transformer / Control Point |

---

## ⚡ Core Logic: Theft Detection by Comparison

Each device uses **CT sensors** to measure current.

If: 

(Current at DA Output) ≠ (Sum of All Home Meter Currents)

→ **Possible Power Theft / Illegal Tapping Detected**

### Leakage (Earthing) Detection
Each Home Meter compares: If above threshold → **Leakage Fault Alert**

This method is:
* Simple
* Cost-effective
* Scalable to thousands of homes

---

## Communication (Planned Architecture)

Home Meter → DA → DA → DP Head → GSM Alert → Authority


* **nRF24L01** modules to create a **chain/network**
* **GSM Module** at head-level for mobile alerts

We **completed** the metering + comparison logic.  
We **could not complete** the wireless communication stage at that time — but we had the architecture ready.

---

## Hardware Used
* CT Current Sensor
* Arduino Uno / Nano
* 16x2 LCD Display
* Buzzer / LED Indicators
* Breadboard / Handmade Circuit Layouts
* *Hand-drawn circuit diagrams (included in repo)*

---

## Repository Structure

AIER-Meter-System/
│── Home_Meter/
│ └── AIR0214_Meter_PRGM.ino
│
│── DA_Module/
│ └── AI_ER_DA_code.ino
│
│── Head_Unit/
│ └── (Planned Communication Code - Incomplete)
│
│── docs/
│ ├── circuit_diagrams/ # Hand-drawn originals
│ └── demo/ # Video / Images
│
└── README.md


---

## Team AIR Revolutionaries (SIH 2023)

| Name | Role |
|------|------|
| **Jaideep Chouhan** | Team Leader, Embedded Programming & System Integration |
| **Jai Bhugra** | Circuit Design & Current Calibration |
| **Chintu Sahu** | Embedded Implementation & Module Replication |
| **Jangid Vinay Kumar** | Device Physical Design & Layout |
| **Mamta Bairwa** | Presentation & Concept Communication |
| **Lareb** | Debugging Support & Documentation |

> We were all 1st semester students with no previous embedded experience.  
> We learned everything while building it — together.

---

## Demonstration
*[(checkout our first stage)](https://drive.google.com/file/d/1TRCFn7btSDsR3SVidfszVk2cfPGkqwwG/view?usp=drive_link)*  
Shows current measurement on 16X2 LCD.

*[(checkout our second stage)](https://drive.google.com/file/d/13xh771XabVxoeucFKGbL0OeV8l5w-GpD/view?usp=sharing)*  
Shows current measurement on 16X2 LCD and fault detection using a LED indicator.

---

## What We Achieved
* Built a functioning **Energy Meter** using CT sensors
* Implemented **Earthing Leakage Detection**
* Designed **Distribution Comparison Logic**
* Created **complete system architecture**

## What Was Left (And Will Be Completed)
* nRF24L01 Mesh Communication
* DP Head GSM Alert System
* PCB + Final Hardware Enclosure

---

## Why This Project Matters

This is where our engineering journey began.  
Not perfect. Not finished. But **real**.

We didn’t just build circuits — we learned:
* How to work as a team
* How to debug hardware in real time
* How to convert a *problem statement* into a *system architecture*

And that is what made this project valuable.

---
