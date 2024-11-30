#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Total_quartos 10

// struct de um quarto
typedef struct {
  char nome_cliente[50];
  int numero;
  int quartos_disponivel;
} quartos_hotel;

// struct do hotel
typedef struct {
  quartos_hotel reservas[Total_quartos];
  int td_quartos;

} Hotel;
// função para inicializar os quartos como disponível
void inicializar_quartos(Hotel *hotel, int td_quartos) {
  int i;
  hotel->td_quartos = td_quartos;
  for (i = 0; i < td_quartos; i++) {
    hotel->reservas[i].numero = i + 1; // Mostrando o número dos quartos
    hotel->reservas[i].quartos_disponivel = 1; // Significa que os quartos estão livres
    strcpy(hotel->reservas[i].nome_cliente,""); // Inicializando o nome do cliente como vazio
  }
}
// Função para carregar os quartos no arquivo
void carregar_quartos(Hotel *hotel) {
  FILE *carregar_reservas = fopen("reservas.txt", "r");
  if (carregar_reservas == NULL) {
    printf("Não existe nenhuma reserva!");
  }
  int numero;
  char nome[50];
  while (fscanf(carregar_reservas, "%d %49[^\n]", &numero, nome) != EOF) {
    hotel->reservas[numero - 1].quartos_disponivel = 0; // 
    strcpy(hotel->reservas[numero - 1].nome_cliente, nome);
  }

  fclose(carregar_reservas);

  return;
}
// Função para salvar reservas em um arquivo
void salvarReservas(Hotel *hotel) {
  FILE *file = fopen("reservas.txt", "w");
  if (file == NULL) {
    printf("Erro ao salvar as reservas.\n");
    // verificar se o arquivo foi aberto corretamente
    return;
  }
  int i;
  for (i = 0; i < hotel->td_quartos; i++) {
    if(!hotel->reservas[i].quartos_disponivel) {
      fprintf(file, "%d %s\n", hotel->reservas[i].numero,hotel->reservas[i].nome_cliente); // Salvando dentro do arquivo
    }
  }
  fclose(file);
}

// Função para listar os quartos disponíveis
void listarQuartosDisponiveis(Hotel *hotel) {
  printf("\nQuartos Disponiveis:\n");
  int i;
  for (i = 0; i < hotel->td_quartos; i++) {
    if (hotel->reservas[i].quartos_disponivel) {
      printf("Quarto %d está disponível.\n", hotel->reservas[i].numero); // Mostra os quartos disponíveis
    }
  }
}

// Função para reservar um quarto
void reservarQuarto(Hotel *hotel, int numero, char *nome_cliente) {
  if (numero < 1 || numero > hotel->td_quartos) {
    printf("Número de quarto inválido.\n"); // Verifica se o número do quarto é válido
    return;
  }

  if (hotel->reservas[numero - 1].quartos_disponivel) {
    hotel->reservas[numero - 1].quartos_disponivel = 0; // Reserva o quarto
    strcpy(hotel->reservas[numero - 1].nome_cliente, nome_cliente);
    printf("Reserva realizada para %s no quarto %d.", nome_cliente, numero); // Mostra a mensagem de reserva realizada
  } else {
    printf("O quarto %d já está reservado.\n", numero);
    // Mostra que o quarto já está reservado
  }
}
// Função para liberar um quarto
void cancelar_reserva(Hotel *hotel, int numero) {
  if (numero < 1 || numero > hotel->td_quartos) {
    printf("Número de quarto inválido.\n"); // Verifica se o número do quarto é válido
    return;
  }
  if (hotel->reservas[numero - 1].quartos_disponivel) {
    printf("O quarto %d não está reservado.\n", numero);
  } // Verifica se o quarto está reservado
  if (!hotel->reservas[numero - 1].quartos_disponivel) {
    hotel->reservas[numero - 1].quartos_disponivel = 1; // Libera o quarto
    printf("Reserva cancelada com sucesso para o quarto %d", numero);
    strcpy(hotel->reservas[numero - 1].nome_cliente, ""); // limpa o nome 
    return;
  } // Libera o quarto e atualiza o arquivo
}
// Função para listar os quartos ativos
void listarQuartosAtivos(Hotel *hotel) {
  printf("\nQuartos Ativos:\n");
  int i;
  for (i = 0; i < hotel->td_quartos; i++) {
    if (!hotel->reservas[i].quartos_disponivel) {
      printf("Quarto %d está ocupado.\n", hotel->reservas[i].numero);
      // Mostra os quartos disponíveis
    }
  }
}
