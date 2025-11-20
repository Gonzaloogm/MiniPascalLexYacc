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
  writeln("Introduce tu nombre:");
  readln(nombre);

  writeln("Hola, ");
  writeln(nombre);

  writeln("Introduce un número entero (a):");
  readln(a);
  writeln("Introduce otro número entero (b):");
  readln(b);

  { Operaciones aritméticas }
  resultado := a + b * 2 - (a div 2);
  potencia := a ** 2;
  resto := a mod b;

  writeln("Resultado de la expresión: ");
  writeln(resultado);

  writeln("El cuadrado de a es: ");
  writeln(potencia);

  writeln("El resto de a div b es: ");
  writeln(resto);

  { Uso de if/then/else con bloques obligatorios }
  if (a > b) and not (a = 0) then
  begin
    writeln("a es mayor que b y distinto de cero.");
  end
  else
  begin
    if (a = b) then
    begin
      writeln("a y b son iguales.");
    end
    else
    begin
      writeln("a es menor que b o a es cero.");
    end
  end;

  { Bucle while }
  i := 0;
  continuar := true;

  while (continuar) do
  begin
    writeln("Iteración número: ");
    writeln(i);

    i := i + 1;
    if (i >= 3) then
    begin
      continuar := false;
    end
  end;

  { Bucle for }
  writeln("Contando del 1 al 5:");
  for (i := 1 to 5) begin
    writeln("Número: ");
    writeln(i);
  end;

  { Uso del operador + como concatenación }
  writeln("Fin del programa, ");
  writeln(nombre + ". ¡Hasta luego!");
end.


