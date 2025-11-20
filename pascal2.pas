program OperacionesYControl;

var
  a: integer;
  b: integer; 
  i: integer;
  resultado: integer; 
  potencia: integer; 
  resto: integer;
  nombre: string;
  continuar: boolean;

begin
  writeln('Introduce tu nombre:');
  readln(nombre);

  writeln('Hola, ', nombre, '! Vamos a hacer algunos cálculos.');

  writeln('Introduce un número entero (a):');
  readln(a);
  writeln('Introduce otro número entero (b):');
  readln(b);

  { Operaciones aritméticas }
  resultado := a + b * 2 - (a div 2);
  potencia := a ** 2;  { potencia entera }
  resto := a mod b;    { resto de la división entera }

  writeln('Resultado de la expresión: ', resultado);
  writeln('El cuadrado de a es: ', potencia);
  writeln('El resto de a div b es: ', resto);

  { Uso de if/else con operadores booleanos }
  if (a > b) and not (a = 0) then
    writeln('a es mayor que b y distinto de cero.')
  else if (a = b) then
    writeln('a y b son iguales.')
  else
    writeln('a es menor que b o a es cero.');

  { Bucle while }
  i := 0;
  continuar := true;
  while continuar do
  begin
    writeln('Iteración número: ', i);
    i := i + 1;
    if i >= 3 then
      continuar := false;
  end;

  { Bucle for }
  writeln('Contando del 1 al 5:');
  for i := 1 to 5 do
    writeln('Número: ', i);

  { Uso del operador + como concatenación }
  writeln('Fin del programa, ', nombre + '. ¡Hasta luego!');
end.

