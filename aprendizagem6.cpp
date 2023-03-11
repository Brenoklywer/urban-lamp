#include <iostream>
#include <time.h>
using namespace std;

struct horario
{
	int hora;
	int minuto;
};

void conversao_tempo(int a);
int subtração(horario a, horario b);
horario ler_horario();
void exibir(horario informacoes);

int main()
{
	horario inicio_aula;
	horario fim_aula;

	system("chcp 1252 > nul");

	cout << "Início: ";
	inicio_aula = ler_horario();

	cout << "Fim: ";
	fim_aula = ler_horario();

	cout << "Entre ";
	exibir(inicio_aula);
	cout << " e ";
	exibir(fim_aula);
	cout << " existem " << subtração(inicio_aula, fim_aula) << " minutos, isto é, ";
	conversao_tempo(subtração(inicio_aula, fim_aula));

	return 0;
}
horario ler_horario()
{
	horario horario_usu;

	cin >> horario_usu.hora;
	cin.ignore();
	cin >> horario_usu.minuto;

	return horario_usu;
}
void exibir(horario informacoes)
{
	cout << informacoes.hora << ":";
	cout << informacoes.minuto;
}
int subtração(horario inicio_tempo, horario fim_tempo)
{
	int minuto_a = inicio_tempo.minuto;
	int hora_a = inicio_tempo.hora;
	int minuto_b = fim_tempo.minuto;
	int hora_b = fim_tempo.hora;

	int intervalo_tempo = 0;

	fim_tempo.hora = fim_tempo.hora - 1;

	int tempo_rodado = 60 - inicio_tempo.minuto;

	if (fim_tempo.minuto == 0)
	{
		do
		{
			for (int i = 0; i <= tempo_rodado; i++)
			{
				fim_tempo.minuto = fim_tempo.minuto + 1;
				inicio_tempo.minuto = inicio_tempo.minuto + 1;
				if (inicio_tempo.minuto == 60)
				{
					inicio_tempo.minuto = 0;
					inicio_tempo.hora = inicio_tempo.hora + 1;
					if (inicio_tempo.hora == 24)
					{
						inicio_tempo.hora = 0;
					}
				}
			}
		} while (fim_tempo.minuto == 20);

	}

	do
	{
		for (int i = 0; i <= fim_tempo.minuto; i++)
		{

			inicio_tempo.minuto = inicio_tempo.minuto + 1;

			intervalo_tempo = intervalo_tempo + 1;

			if (inicio_tempo.minuto == 60)
			{
				inicio_tempo.minuto = 0;

				i = 0;

				inicio_tempo.hora = inicio_tempo.hora + 1;

				if (inicio_tempo.hora == 24)
				{
					inicio_tempo.hora = 0;
				}
			}

		}
	} while (inicio_tempo.hora <= fim_tempo.hora);

	return intervalo_tempo;
}
void conversao_tempo(int a)
{
	int hora, minuto;

	hora = a / 60;
	minuto = a % 60;
	if (minuto != 0)
	{
		cout << hora << "h e " << minuto << " minutos.";
	}
	else
	{
		cout << hora << "h e " << minuto << " minuto.";
	}
}