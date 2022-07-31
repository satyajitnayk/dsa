A=[18,19,29,15,16]

Approach 1: (2*x - currentMinimum)
O(1) space  
->Can be done using a trick => whene ever we get element < currentMinimum store instead (2*x - currentMinimum)
->While retreating we can check if currentMinimum >= top of stack  that means we stored the dummy element
 & reverse the process to get back the original element

A=[18,19,29,15,16]
->s: 18    currentMinimum=18
->s: 18, 19       19 > currentMinimum no need to update currentMinimum, currentMinimum=18
->s: 18, 19,29    same for 29 , currentMinimum=18
->s: 18,19,29,12       15 < currentMinimum(18) => store 2*x-currentMinimum = 2*15-18=30-18=12, currentMinimum=15
->s: 18,19,29,12,16    16 < currentMinimum(15) so just push original value  , currentMinimum=15
