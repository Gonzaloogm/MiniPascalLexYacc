program mini;

const 
	MIN = 10;
	MAX = 100;
	PI = 3.14;
 	SALUDO = "Hola";
 	OK = true;
var
  a: integer;
  b: integer; 
  i: integer;
  resultado: integer;
  potencia: integer;
  resto: integer;
  r: real;
  nombre: string;
  continuar: boolean;

begin
    i := 33;                     { asignación simple }
    b := 9 + i;                  { asignación con expresión }
    resultado := b * 2;         { multiplicación }
    resto := b mod 5;           { operación mod }
    potencia := i ** 2;         { potencia si la soportáis }

    writeln(i);                 { print variable }
    writeln(b);
    writeln(resultado);
    writeln(resto);

    readln(i);                  { leer un entero y guardarlo en i }

    a := i + MIN;               { uso de constante }
    r := PI * 2;                { real con constante }
    
    writeln(a);
    writeln(r);

    { lectura de string – depende de tu sintaxis si lo procesáis ya }
    { readln(nombre); }
    { writeln(nombre); }

end;