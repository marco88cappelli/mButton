# mButton
Control state button in Arduino AVR

Questa classe semplifica all'utente la gestione dei pulsanti, permettendo d'intercettare tre stati:
  - Pressione
  - Rilascio
  - Cambiamento di stato
 Ogni evento richiama una funzione passata alla classe come puntatore.
 
 Le funzioni che possono essere puntate sono di due tipi:
  - void fun (){}
  - void fun (long long n){}
 
 La prima funzione serve per gli eventi di pressione e cambio di stato, metre la seconda funzione serve per l'evento di rilascio, infatti il parametro n conterrà la durata della pressione.
 Di default i puntatori sono inizializzati a NULL.
 
 La funzione ha un filtro di debounce che di default è 25ms
