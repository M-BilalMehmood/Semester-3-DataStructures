// Define the crossword puzzle as a 2D array
const crossword = [
    ['C', 'E', 'M'],
    ['B', 'A', 'O'],
    ['X', 'W', 'T']
];

// Define the word to search for
const word = 'CAT';

// Initialize empty arrays to store the row and column indices of the characters in the word
const rowIndexes = [];
const colIndexes = [];

// Loop through each row of the crossword puzzle
for (let i = 0; i < crossword.length; i++) {
    // Loop through each column of the current row
    for (let j = 0; j < crossword[i].length; j++) {
        // Check if the current character matches the first character of the word
        if (crossword[i][j] === word[0]) {
            // If it does, loop through the rest of the characters in the word
            for (let k = 1; k < word.length; k++) {
                // Check if the next character in the word matches the corresponding character in the crossword puzzle
                if (crossword[i + k][j + k] !== word[k]) {
                    // If it doesn't, break out of the loop and continue searching
                    break;
                }
                // If we've reached the end of the word and all characters match, store the row and column indices
                if (k === word.length - 1) {
                    rowIndexes.push(i, i + 1, i + 2);
                    colIndexes.push(j, j + 1, j + 2);
                }
            }
        }
    }
}

// Output the row and column indices as a 2D array
console.log([rowIndexes, colIndexes]);
