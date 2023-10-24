#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mathlib.h"

int main() {
    printf("Content-type:text/html\n\n");
    double a = 1, b = 78;
    char method[50];
    
    sscanf(getenv("QUERY_STRING"), "borne1=%lf&borne2=%lf&method=%s", &a, &b, method);

    printf("<body>");
    printf("<h1>Fonction log(x)-1</h1>");
    css("math.css");

    printf("<center>");
    printf("<form action=\"./mathfonc.cgi\" method=\"get\">");
    printf("<input placeholder=\"borne1\" type=\"text\" pattern=\"[0-9]+\" name=\"borne1\">");
    printf("<input placeholder=\"borne2\" type=\"text\" pattern=\"[0-9]+\" name=\"borne2\">");
    printf("<button type=\"submit\" name=\"method\" value=\"d\">Methode de dichotomie</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"c\">Methode de Descartes</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"n\">Methode de Newton</button>");
    printf("<button type=\"submit\" name=\"method\" value=\"i\">Calcul d` Integrale</button>");
    printf("</form>");
    printf("</center>");

    printf("<div class=\"main\"><center>");
    
    if (strcmp(method, "d") == 0) {
        printf("<table border>");
        printf("<h2>%d iterations</h2>", dicho(a, b) - 1);
        printf("</table>");
    } 
    
    else if (strcmp(method, "c") == 0) {
        printf("<table border>");
        printf("<h2>%d iterations</h2>", secante(a, b) - 1);
        printf("</table>");
    } 
    
    else if (strcmp(method, "n") == 0) {
        printf("<table border>");
        printf("<h2>%d iterations</h2>", tangente(a, b) - 1);
        printf("</table>");
    } 
    
    else if (strcmp(method, "i") == 0) {
        printf("<h2>%lf</h2>", inteTrap(a, b));
    }
    printf("</center></div>");
    printf("</body>");
    
    return 0;
}
