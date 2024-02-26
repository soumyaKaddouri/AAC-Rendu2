const bezout = require('./bezout');

// Test case 1: Nombres positifs
const result1 = bezout(50, 11);
console.log(result1); // Résultat attendu : [2, -9]

// Test case 2: Un des nombres est négatif
const result2 = bezout(-50, 11);
console.log(result2); // Résultat attendu : [-1, 6]

// Test case 3: Les deux nombres sont négatifs
const result3 = bezout(-50, -11);
console.log(result3); // Résultat attendu : [2, -9]

// Test case 4: Un des nombres est zéro
const result4 = bezout(50, 0);
console.log(result4); // Résultat attendu : [1, 0]

// Test case 5: Les deux nombres sont zéro
const result5 = bezout(0, 0);
console.log(result5); // Résultat attendu : [1, 0]