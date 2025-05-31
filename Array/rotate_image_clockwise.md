### Clockwise Rotation (90°):

- Transpose the matrix.
- Reverse each row.

### Counterclockwise Rotation (90°):

- Transpose the matrix.
- Reverse each column.

> if anti clock wise do reverse

## Transpose Logic:

- Loop through 𝑖(rows) and 𝑗 > 𝑖 (columns above the diagonal).
- Swap (𝑖,𝑗)(i,j) with (𝑗,𝑖)(j,i).

```c++
// Step 1: Transpose the matrix across the main diagonal
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
```

## Reverse Transpose Logic:

- Outer Loop (i): Loops through rows of the matrix.
- Inner Loop (j): For each row 𝑖, the inner loop iterates only up to the secondary diagonal. The range of columns is from the first column 𝑗=0 to 𝑗=𝑛−𝑖−1.
- Swap: Elements at positions(𝑖,𝑗) and(𝑛−1−𝑗,𝑛−1−𝑖) are swapped.

```c++
// Loop over elements above the secondary diagonal
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
    }
}
```
