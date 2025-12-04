program OperacionesYControl;

const
  PI = 3.1416;

var
  a: integer;
  b: real;      
  i: integer;
  resultado: integer; 
  nombre: string;
  c: string;    (* Variable añadida para probar 'sin inicializar' *)
  continuar: integer;

begin
  (* ERROR 1: Variable 'a' se usa aquí antes de hacerle un readln o asignación *)
  i := a; 

  writeln("Introduce tu nombre:");
  readln(nombre);

  writeln("Hola, ");
  writeln(nombre);

  writeln("Introduce el valor: ");
  (* ERROR 2: Variable 'valor' no está declarada en VAR *)
  readln(valor); 

  writeln("Introduce un número entero (a):");
  readln(a); (* Aquí recién se inicializa 'a', pero ya dio error arriba *)
  
  writeln("Introduce otro número real (b):");
  readln(b);

  (* ERROR 3: Tipos incompatibles. 'i' es integer, pero 'b' es real. *)
  (* La multiplicación genera un real que no cabe en un integer *)
  i := a * b; 

  (* ERROR 4: Intentando modificar una constante *)
  PI := 3.1595;

  (* ERROR 5: Variable 'c' declarada pero nunca se le dio valor *)
  writeln("Valor: ", c); 
  
  resultado := a + 10;
  writeln("Resultado: ");
  writeln(resultado);

  if ( (a > 0) and not (a = 0) ) then begin
    writeln("a es positivo.");
  end
  else begin
    writeln("a es cero o negativo.");
  end;

  i := 0;
  continuar := 1;

  while (continuar > 0) do begin
    writeln("Iteración while: ");
    writeln(i);
    i := i + 1;
    if (i >= 2) then begin
      continuar := 0;
    end
  end;

  writeln("Contando del 1 al 3:");
  for i := 1 to 3 do begin
    writeln("Número for: ");
    writeln(i);
  end;

  writeln("Fin del programa.");
end.


