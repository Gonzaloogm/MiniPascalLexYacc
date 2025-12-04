program ejemplo;
const
 PI = 3.1416;
var
 a,i:integer;
 b:real;
 c:string;
begin
 i := a; (*variable a sin inicializar*)
 writeln("Introduce el valor: ");
 readln(valor); (*variable valor sin declarar*)
 writeln("Introduce el valor de la a: ");
 readln(a);
 writeln("Introduce el valor de la b: ");
 readln(b);
 i := a * b; (*tipos incompatibles en la instrucción*)
 PI := 3.1595; (*modificación de valor de una constante*)
 writeln("Valor: ",c); (*variable sin inicializar*)
end.