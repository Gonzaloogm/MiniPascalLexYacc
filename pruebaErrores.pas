program ErroresComunes;

const
  PI = 3.14;
  TASA : 10;      { ERROR 1 }
  MAX = 100;      

var
  a: integer;
  b integer;      { ERROR 2 }
  c: integer;     

begin
  writeln("Inicio del programa correcto");

  a := 10;
  
  c := 20 + * 5;  { ERROR 3 }
  
  writeln("Hola") { ERROR 4 }
  writeln("Adios");

  writeln("Recuperado.");
  writeln("Si ves esto, tu compilador ha superado los 3 errores.");
end.