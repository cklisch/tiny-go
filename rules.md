# Tiny Go Rules

## Requirements
- 2 Players
- 1 Board with a square grid with sides of n fields $n < 1$ and n odd
- 2 sets of stones, each containing $n^2 / 2$ rounded down to the next integer distinguishable stones

## Game
A game consists of two rounds. Each players picks a set of stones. Both players start one round.

### Round
The players take alternating turns as long as they have stones left.

#### Turn
1. The player places one of his stones on an unoccupied field.
2. The player may remove any group of stones[^1] with no liberties[^2]. These stones can not be places again during the round.

## End
All stones which were removed during the two rounds are added up. The player who removed more of the opponents stones wins. If both captured the same amount it is a draw.

[^1]: A group of stones is a single stone or all stones recursively adjacent to stones of the same set.
[^2]: A group with no liberties has no free fields adjacent to it.
