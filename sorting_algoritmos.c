#include<stdio.h>
#include<time.h>

/* xxxxxxxxxxx BUBBLE SORT xxxxxxxxxxxxxxx*/
void bubbleSort(int arr[], int n, long long *comp, long long *mov)
{

    *mov = 0;
    *comp = 0;
    int temp, i, j;

    for ( i = 0; i < n - 1; i++) // laço para pecorrer o array, travado no tamanho do array sem que haja muito desperdicios
    {
        for ( j = 0; j < n-i-1 ; j++) //  laço de comparações, comparação do bubnle de 1 par 1
        {
            (*comp)++;

            if (arr[j] > arr[j+1]) // troca dos numeros
            {
              temp = arr[j]; 
              arr[j] = arr[j+1];
              arr[j+1] = temp; 
              
              (*mov)++;
            }
            
        }
        
    }
    
};

/* xxxxxxxxxxx SELECTION SORT xxxxxxxxxxxxxxx*/
void selectionSort(int arr[], int n, long long *comp, long long *mov)
{
    *mov = 0;
    *comp = 0;
    int i, j, temp, min_idx; // min_idx pode-se dizer uma fila separada de indices.

    for ( i = 0; i < n -1; i++) // laço para pecorer
    {


        min_idx = i; // ele precisa assumir o valor de i para continuar a partir dele

        for ( j = i + 1 ; j < n ; j++) // comparações e o meu j precisa ser o proximo de i ou idx
        {
            (*comp)++;
            if (arr[j] < arr[min_idx]) // aqui rola a comparação de fato, ele olha se o meu j é maior que meu numero que esta sendo comparado, o idx, se form maior o idx assume o valor/posição de j 
            {
                min_idx = j;
            }
            
        }


        if (min_idx != i) {
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
            (*mov)++;
        }
       
    }
    

}



/* xxxxxxxxxxx INSERTION SORT xxxxxxxxxxxxxxx*/
void insertionSort(int arr[], int n, long long *comp, long long *mov)
{
    *mov = 0;
    *comp = 0;
    int i, j, key, temp;

    for (i = 1; i < n; i++) // pecorrer array, o i começa a frente pois atras dele esta tudo ordenado
    {

        key = arr[i];

        j = i -  1;

       while ( j >= 0 ) // se existir numero a esquerda (for maior que 0) e se o numero que esta em key for maior que o que esta no meu j ele precisa andar para direita sendo as comparações
       {
         (*comp)++;
            

         if (arr[j] > key) // quebrei o insert em comparação e troca para funcionar com  os criterios de desempenho, nos contadores
         {
            arr[j+1] = arr[j];
            (*mov)++;
            j--; // j = j - 1 são a mesma coisa
            
         } 
         else 
         {
            break; // se não precisar trocar ele so quebra o laço
         }
         
       }
       arr[j+1] = key;
       (*mov)++;
    }
    
}

/* xxxxxxxxxxx QUICK SORT xxxxxxxxxxxxxxx*/

/* PARTITION*/

int part(int arr [], int low , int high, long long *comp, long long *mov )
{
   
    int pivo, i, j, temp;

    pivo = arr[high]; // Pivô escolhido como último elemento

    i = low - 1;  // Índice do menor elemento

    for ( j = low; j < high; j++) // enquanto meu j é igual ao menor elemento ele vaio ate o pivo de ultimo elemento, posição 
    {

        (*comp)++;
        if (arr[j] < pivo) // se meu valor de j for menor que meu pivo que é o ultimo, o i++...
        {
            
            i++; //aumenta a area de esquerda dos menores, para por mais numeros
             temp = arr[i]; //troca basica onde o i salva no temporario, o i pega o menor valor de j, e o j assume o valor grande ded i
             arr[i] = arr[j];
             arr[j] = temp;
             (*mov) ++;
        }
        
    }
      
    temp = arr[i+1]; // aqui são as trocas 
    arr[i+1] = arr[high];
    arr[high] = temp;
    (*mov) ++;

    return (i+1); // devolve pivo

}

/* Quick*/
void quickSort(int arr[], int low, int high, long long *comp, long long *mov)
{
    if (low < high) // se o ultimo menor for baixo do numero onde esta a posição final o pi- vo, faz a partição
    {
         int pi = part(arr, low, high, comp, mov);

        quickSort(arr, low, pi - 1, comp, mov); // ordem
        quickSort(arr, pi + 1, high, comp, mov); // ordem
    }
    
}

/* xxxxxxxxxxx MERGE SORT xxxxxxxxxxxxxxx*/

/* Merge*/
void merge(int arr[], int l, int m, int r, long long *comp, long long *mov)
{
    // l = esquerda, m = meio e r = direita
    

    int i, j, k;

    int e = m -  l + 1; // o tamanho da parte esquerda, o meio - esquerda mais 1

    int d = r - m; // tamanho da direita que o r (final ) ate o meio

    int L[e], R[d]; // copia  da parte esquerda e direita

    for (i = 0; i < e; i++) { //copia os dados por exemplo, i so pode ir ate o ultimo elemento da esquerda
        L[i] = arr[l + i]; // vai pegar todos os elementos da esqueda e jogar no L.
        (*mov)++;
    }

       for (j = 0; j < d; j++) { 
        R[j] = arr[m + 1 + j];
        (*mov)++;
    }

        i = 0;
        j = 0;
        k = l;


    while (i < e && j < d) { // i < menor que  a parte esquerda e j igualmente
         
        (*comp)++; 

        if (L[i] <= R[j]) { // comparação entre os menores de cada um e joga nos vetores de acordo 
            arr[k++] = L[i++]; // copia ele para K e avança para os proximos numero
        } else { 
            // se não joga o valor de R dentro de K
            arr[k++] = R[j++];
        }
        (*mov)++;
    }


    
    // sobras da esquerda
    while (i < e) {
        arr[k++] = L[i++];
        (*mov)++;
    }

    // sobras da direita
    while (j < d) {
        arr[k++] = R[j++];
        (*mov)++;
    }
}

/* MergeSort*/
void mergeSort(int arr[], int l, int r, long long *comp, long long *mov)
{
    if (l < r) { // se tiver mais de um elemento
        int m = (l + r) / 2; // calculo do meio
        mergeSort(arr, l, m, comp, mov); // ordena a parte esquerda
        mergeSort(arr, m + 1, r, comp, mov); // ordena a parte direita
        merge(arr, l, m, r, comp, mov); // agora junta
    }
}

/* xxxxxxxxxxx PRINT ARRAYxxxxxxxxxxxxxxx*/

void print(int arr[], int n) // printa o array 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copiarArray(int origem[], int destino[], int n) // copia o array 
{
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/* xxxxxxxxxxx PROGRAMA PRINCIPAL xxxxxxxxxxxxxxx*/
int main ()
{
     int opcao; // para o switch case

     /* FUNÇÕES DE TEMPO*/
    clock_t inicio, fim; 
    double tempo;
    long long comp, mov;



    int array[] = {9, 3, 7, 1, 6, 2, 8, 5, 4, 10, 15, 65, 90, 120, 1001, 45, 87, 21, 39, 50}; 
    int n = sizeof(array) / sizeof(array[0]); // meu n assume o tamanho do meu array no caso 20 numeros
    int arr[n];


    // uso do do while, pois ele precisa aparecer apenas uma vez e seguir certas regras, sendo mais funcional nesse caso, por exemplo: ele execeuta sem saber quantas vezes vai loopar, logo obdece o menu com opções.

    do {
        printf("\nxxxxxxxx MENU DE ORDENACAO xxxxxxxx\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Quick Sort\n");
        printf("5 - Merge Sort\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo...");
            break; // se escolher 0 quebra, no caso sai
        }

        copiarArray(array, arr, n); // isso é para garantir que o array seja justo para todos os algoritmos

        printf("\nArray antes da organizacao: "); 
        print(arr, n);

        // inicio da contagem de tempo
        inicio = clock();

        /*===== BUBBLE ====*/
        switch (opcao) {

            /*===== BUBBLE ====*/
            case 1:
                bubbleSort(arr, n, &comp, &mov);
                break;

            /*===== SELECTION ====*/
            case 2:
                selectionSort(arr, n, &comp, &mov);
                break;

            /*===== INSERTION ====*/
            case 3:
                insertionSort(arr, n, &comp, &mov);
                break;

            /*===== QUICK ====*/
            case 4:
                comp = 0;
                mov = 0;
                quickSort(arr, 0, n - 1, &comp, &mov);
                break;

                // Aqui nos restamos o contador devido ao alto numero de trocas especificas.

            /*===== MERGE ====*/
            case 5:
                comp = 0;
                mov = 0;
                mergeSort(arr, 0, n - 1, &comp, &mov);
                break;

            default:
                printf("Opcao invalida!\n");
                continue;
        }

        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Array depois da organizacao: ");
        print(arr, n);

        printf("Comparacoes: %lld\n", comp);
        printf("Movimentacoes: %lld\n", mov);
        printf("Tempo: %.6f segundos\n", tempo);

    } while (opcao != 0);

    return 0;

    // os comentários ajuda a estudar, por isso estão menos tecnico e informais.
}