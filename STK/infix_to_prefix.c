/*


  1) Input infix expression
  2) ((A+B)*C)-D
  3) Reverse the expression
     D-)C*)B+A((
  4) Replace All ')' with '(' with ')'
     D-(C*(B+A))
  5) Convert this to postfix expression
       DCBA+*-
  6) Reverse the expression to get prefix expression
       -*+ABCD

*/