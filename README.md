# CrackNClash 🔓🔑
**"Crack n Clash"** is an innovative puzzle game designed as a competitive challenge between a human player and an AI opponent. Both participants race to pick complex locks by guessing the correct pin combinations.

# 👾 Game Proper
**Objective:**
  * The player and the AI compete to pick the same lock first by correctly setting all pins in their proper positions within the allotted time for both the player and the AI. The winner is the one who successfully unlocks the lock before the other.

# 🧏‍♀️ Rules of the Game
1. Both the player and AI attempt to pick the same lock simultaneously.
2. Each lock has a fixed number of pins that must be set correctly.
3. After each attempt, feedback is given indicating which pins are correctly or incorrectly set.
4. The AI uses backtracking to optimize its search for the correct combination.
5. The player uses intuition, logic, and feedback to guess the correct pin settings.
6. The game imposes a time limit to increase tension.
7. The first to unlock the lock wins the round.

# 🤖 Implementation of AI Algorithm (Backtracking)
The AI opponent employs the backtracking search algorithm to simulate an expert lock picker. This algorithm was chosen for several reasons:
**Efficiency:** Backtracking systematically explores all possible pin settings, pruning invalid paths early to avoid wasted attempts.
**Competitiveness:** It allows the AI to quickly narrow down correct combinations, providing a challenging opponent for the player.
**Flexibility:** The algorithm can adapt to different lock complexities and constraints dynamically.
**Realism:** Mimics logical human reasoning in solving puzzles, enhancing immersion.

# 🏁 How to run?
Clone the repository and run on your computer that has C Programming Language and compiler installed.
