const char INDEX_PAGE[] /*PROGMEM*/ = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Control Masina</title>
</head>

<body>
	<h1>Control masina</h1>
  <script>
    if( window.location.pathname == "/INAINTE_FULL") 
    {
      document.write("<a href='/'> <img src='https://imgur.com/jyvDYWB.jpg' style='margin-left:100px'> </a>"); 
    }
    else 
    {
      document.write("<a href='/INAINTE_FULL'> <img src='https://imgur.com/0YH4lOU.jpg' style='margin-left:100px'> </a>");
    }
  </script>
  <br>
  <script>
    if( window.location.pathname == "/VIREAZA_STANGA")
    {
        document.write("<a href='/'> <img src='https://imgur.com/fB9Pqc6.jpg'> </a>");
    }
    else
    {
        document.write("<a href='/VIREAZA_STANGA'><img src='https://imgur.com/J2aFTPx.jpg'></a>");
    }  
  </script>
  
  <script>
    if( window.location.pathname == "/INAINTE_INCET") 
    {
      document.write("<a href='/'> <img src='https://imgur.com/7N5Z6Go.jpg'> </a>");      
    }
    else 
    {
      document.write("<a href='/INAINTE_INCET'> <img src='https://imgur.com/l5LBCFE.jpg'> </a>");
    }
  </script>
  
  <script>
    if( window.location.pathname == "/VIREAZA_DREAPTA") 
    {
      document.write("<a href='/'> <img src='https://imgur.com/iUy8Ctj.jpg'> </a>");      
    }
    else 
    {
      document.write("<a href='/VIREAZA_DREAPTA'><img src='https://imgur.com/1CzzIbj.jpg'></a>");
    } 
  </script>
  <br>
  <a href='/ROTIRE_STANGA'><img src='https://imgur.com/PfnvhM1.jpg'></a>
  <a href='/STOP'><img src='https://imgur.com/SuSwv4h.jpg'></a> 
  <a href='/ROTIRE_DREAPTA'><img src='https://imgur.com/LyEk17w.jpg'></a>
  <br>              
  <a href='/INAPOI'><img src='https://imgur.com/25fPjAB.jpg' style='margin-left:100px'></a> 
</pre>
</body>
</html>
)rawliteral";

/* PROGMEM foloseste memoria ROM arduino-ului, nu memoria RAM */
/* Si din pacate la noi se da reset si nu functioneaza pe exemplul nostru */
/* https://www.arduino.cc/reference/tr/language/variables/utilities/progmem/  */