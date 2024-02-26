/**
 * La fonction calcule les coefficients de Bézout en utilisant l'algorithme d'Euclide.
 * @param {number} a - Premier nombre en entrée
 * @param {number} b - Deuxième nombre en entrée
 * @return {Array<number>} Tableau de deux nombres qui sont les coefficients de Bézout
 */
function bezout(a, b) {
    if (b == 0) return [1, 0];
  
    let q = Math.floor(Math.abs(a / b)),
      r = a % b,
      res = bezout(b, r);
  
    return [res[1], res[0] - q * res[1]];
}

module.exports = bezout;