#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#define Total_quartos 10



int main(){

  Hotel hotel;
  inicializar_quartos(&hotel, Total_quartos);
  carregar_quartos(&hotel);
  salvarReservas(&hotel);
  int op=0, num_quarto;
  char cliente[50];
    printf("\t\n     _____________________________");
    printf("\t\n    |                             |");
    printf("\t\n    |      HOTEL COPABANANAS      |");
    printf("\t\n   _|_____________________________|_");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|");
    printf("\t\n  |        |       |       |       |");
    printf("\t\n  |  []    |  []   |  []   |  []   |");
    printf("\t\n  |________|_______|_______|_______|    @@   @@");
    printf("\t\n  |        |       |       |       |   @@@@ @@@@");
    printf("\t\n  |  []    |  []   |  []   |  []   |    ||   ||");
    printf("\t\n  |________|_______|_______|_______|    ||   ||");
    printf("\t\n            |             |");
    printf("\t\n            |    _____    |");
    printf("\t\n            |___|     |___|");
    printf("\t\n                |_____|");
  do{
    // Menu do Hotel
    printf("\n\n\n-------------------------------------------");
    printf("\n\t 1. Listar quartos livres");
    printf("\n\t 2. Reservar quartos;");
    printf("\n\t 3. Cancelar reserva;");
    printf("\n\t 4. Reservas que estão ativas;");
    printf("\n\t 5. Sair.\n");
    printf("\n-------------------------------------------");
    scanf("%d", &op);
    
    switch (op) {
    case 1:
      // Listar quartos disponíveis
      listarQuartosDisponiveis(&hotel);
      break;
    case 2:
      printf("Digite o número do quarto que deseja reservar: "); // Solicita o número do quarto
      scanf("%d", &num_quarto);
      getchar();
      puts("Digite o nome do cliente: ");
      fgets(cliente, 50, stdin); // Ler a string do cliente
      
      reservarQuarto(&hotel, num_quarto,cliente); // chamando as funções de reservar e salvar
      salvarReservas(&hotel); // Salvando as alterações no arquivo
      break;
    case 3:
      printf("Digite o número do quarto que deseja cancelar: "); // Cancelar reserva
      scanf("%d", &num_quarto);
      cancelar_reserva(&hotel, num_quarto);
      salvarReservas(&hotel);// Salvando as alterações no arquivo
      break;
    case 4:
      listarQuartosAtivos(&hotel); // Listar quartos ativos)
      break;
    case 5:
      printf("\t\n O serviço foi encerrado."); // Encerra o programa
      break;

    default:
      printf("Não existe está opção."); // Caso o usuário digite uma opção inválida
    
      break;
    }

    }while(op != 5); // Verificação do menu de entrada

  return 0;
}