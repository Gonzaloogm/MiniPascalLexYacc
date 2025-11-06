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
    i := 33;                     
    b := 9 + i;                 
    resultado := b * 2;         
    resto := b mod 5;           
    potencia := i ** 2;        

    writeln(i);                 
    writeln(b);
    writeln(resultado);
    writeln(resto);

    readln(i);                  

    a := i + MIN;               
    r := PI * 2;                
    
    writeln(a);
    writeln(r);


end.