import math

#calcula la distancia entre dos puntos
def distancia(p1, p2):
    return math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)

#determina que tipo de recta es conforme a los valores dados
def recta(p1, p2):
    if p1[0] == p2[0]:
        return "Recta vertical"
    elif p1[1] == p2[1]:
        return "Recta horizontal"
    else:
        return "Recta inclinada"

#calcula la pendiente de de los valores
def pendiente(p1, p2):
    Px = p2[0] - p1[0]
    Py = p2[1] - p1[1]
    return math.degrees(math.atan2(Py, Px)) #grados

#calcula el perimetro del triangulo
def perimetro(p1, p2, p3):
    Pe1 = distancia(p1, p2)
    Pe2 = distancia(p2, p3)
    Pe3 = distancia(p3, p1)
    return Pe1 + Pe2 + Pe3 #operacion importante

#diccionario y stack para valor positivo
def digito(numero):
    digito = {
        '0': "cero",
        '1': "uno",
        '2': "dos",
        '3': "tres",
        '4': "cuatro",
        '5': "cinco",
        '6': "seis",
        '7': "siete",
        '8': "ocho",
        '9': "nueve"
    }
    stack = []
    while numero > 0:
        digitos = numero % 10
        stack.append(digito[str(digitos)]) #agregar elementos del lado derecho
        numero //= 10
    while stack:
        print(stack.pop(), end="-") #retira y devuelve el elemento a la parte superior
    print()

while True:
    x1 = int(input("Ingrese la coordenada del primer punto (x1): "))
    y1 = int(input("Ingrese la coordenada del primer punto (y1): "))
    x2 = int(input("Ingrese la coordenada del segundo punto (x2): "))
    y2 = int(input("Ingrese la coordenada del segundo punto (y2): "))

    Pu1 = (x1, y1)
    Pu2 = (x2, y2)

    distancia_total = distancia(Pu1, Pu2)
    print("La distancia entre los dos puntos es:", distancia_total)

    tipo_Recta = recta(Pu1, Pu2)
    print("La recta es:", tipo_Recta)

    pendiente_total = pendiente(Pu1, Pu2)
    print("La pendiente de la recta es:", pendiente_total, "grados")

    x3 = int(input("Ingrese la coordenada del tercer punto (x3): "))
    y3 = int(input("Ingrese la coordenada del tercer punto (y3): "))

    Pu3 = (x3, y3)

    perimetro_total = perimetro(Pu1, Pu2, Pu3)
    print("El perímetro del triángulo es:", perimetro_total)

    lista_puntos = [Pu1, Pu2, Pu3]
    print("La lista de puntos es:", lista_puntos)

    numero = int(input("Ingrese un numero o numeros positivos: "))
    digito(numero)
    
    opcion = input("¿Ingresar otro valor? (si/no): ")
    if opcion.lower() != "si": #convierte todos los caracteres en minusculas
        break