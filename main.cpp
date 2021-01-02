//Creado por Juan Carlos Juárez. A00824524.
//Proyecto del 3er Parcial.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Disco.h"
#include "Software.h"
#include "Libro.h"
#include "Reserva.h"




int menuDeOpciones()
{
	int opcionMenu;
	cout << "\n";
	cout << "-------Menu de Opciones-------\n\n";
    cout << "1)Consultar la lista de materiales." << endl;
	cout << "2)Consultar la lista de reservaciones." << endl;
	cout << "3)Consultar las reservaciones de un material dado." << endl;
	cout << "4)Consultar las reservaciones de una fecha dada." << endl;
	cout << "5)Hacer una reservacion." << endl;
	cout << "6)Terminar." << endl;
	cout << "\n";
	cout << "Opcion: ";
	cin >> opcionMenu;

	return opcionMenu;
}

int main()
{

    int changer1=0;
	int opcionMenu;
	int cont1 = 0;
	int cont2 = 0;
	int changer2=0;
	int idMaterial, numPaginas, duracion, dia, mes, anio, idMaterialB, idClienteB;
	string titulo, autor, sist;
	char tipoMat;
	Material* arrMat[20];
	Reserva arrRev[50];
	Fecha fec;



	ifstream getFile;
	ofstream writeFile;


	getFile.open("Material.txt");
	while(!getFile.eof())
	{

    getFile >> idMaterial;
    getFile >> titulo;
    getFile >> tipoMat;

    if(tipoMat == 'L')
		{
        getFile >> numPaginas;
        getFile >> autor;
        arrMat[cont1] = new Libro(numPaginas, autor, idMaterial, titulo);
	    }

    if(tipoMat == 'D')
		{

        getFile >> duracion;
        arrMat[cont1] = new Disco(duracion, idMaterial, titulo);
		}

    if(tipoMat == 'S')
		{
        getFile >> sist;
        arrMat[cont1] = new Software(sist, idMaterial, titulo);
		}
		cont1++;
	}

	getFile.close();
	getFile.open("Reserva.txt");
	while(!getFile.eof())
	{
    getFile >> dia;
    getFile >> mes;
    getFile >> anio;
    fec.setFecha(dia, mes, anio);
    arrRev[cont2].setfechaReservacion(fec);
    getFile >> idMaterialB;
    arrRev[cont2].setidMaterial(idMaterialB);
    getFile >> idClienteB;
    arrRev[cont2].setidCliente(idClienteB);
    cont2++;
	}

	cout << "**Tercer Proyecto Parcial**" << endl;
	cout << "*Juan Carlos Juarez. A00824524.*" << endl;
	getFile.close();
	bool bState = false;
	do
    {
    opcionMenu = menuDeOpciones();
    switch(opcionMenu)
	{
	case 1:
	    //******
		cout << endl;
		cout << "*Lista de Materiales: \n\n";
		for(int i = 0; i < cont1; i++)
		{
			arrMat[i]->muestra();
		}
		break;
	case 2:
	    //******
		cout << endl;
		cout << "*Lista de Reservaciones: \n\n";
		for(int i = 0; i < cont2; i++)
		{
			for(int i2 = 0; i2 < cont1; i2++)
			{
				if(arrMat[i2]->getidMaterial() == arrRev[i].getidMaterial())
				{
			cout << "*" << arrRev[i].getfechaReservacion() << " " << arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo()) << " " << arrRev[i].getidMaterial() << " " << arrRev[i].getidCliente() << endl;
            arrMat[i2]->muestra();
            cout << endl;
		}
		    }
		}
		break;
	case 3:
	    //*****
	    cout << endl;
	    cout << "*Reservacion de un Material dado: \n\n";
	    cout << "Ingrese Id del material: ";
	    cin >> idMaterialB;
	    cout << endl;
	    for(int i = 0; i < cont2; i++)
	    {
	    	for(int i2 = 0; i2 < cont1; i2++)
	    	{
	           if(idMaterialB == arrRev[i].getidMaterial())
	           {
	              if(idMaterialB == arrMat[i2]->getidMaterial())
	              {
	              	cout << "*" << arrRev[i].getfechaReservacion() << " " << arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo()) << endl;
	              	arrMat[i2]->muestra();
	              	cout << endl;
				  }

		       }
	        }
        }
	    break;
	case 4:
	    //*****
		cout << endl;
		cout << "*Reservacion de una Fecha dada: \n\n";
		cout << "Ingrese dia de reserva: ";
		cin >> dia;
		cout << "Ingrese mes de reserva: ";
		cin >> mes;
		cout << "Ingrese anio de reserva: ";
		cin >> anio;
		cout << endl;
		fec.setFecha(dia, mes, anio);
		for(int i = 0; i < cont2; i++)
		{
			for(int i2 = 0; i2 < cont1; i2++)
			{
            if(arrRev[i].getidMaterial() == arrMat[i2]->getidMaterial())
			    {
                if((fec >= arrRev[i].getfechaReservacion()) && (fec <= arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo())))
			        {
                cout << "*" << arrRev[i].getfechaReservacion() << " " << arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo()) << " " << arrRev[i].getidMaterial() << " " << arrRev[i].getidCliente() << endl;
                arrMat[i2]->muestra();
                cout << endl;
				    }
		        }
			}
		}
		break;
	case 5:
	    //*****
	    changer1=0;
		bState = false;
		cout << endl;
		cout << "*Hacer una Reservacion: \n\n";
		cout << "Ingrese Id del material: ";
		cin >> idMaterialB;
		for(int i = 0; i < cont1; i++)
		{
			if((arrMat[i]->getidMaterial() != idMaterialB) && (i == (cont1-1)))
			{
				cout << "Id no encontrado" << endl;
				cout << "Ingrese de nuevo Id del material: ";
		        cin >> idMaterialB;
		        i = 0;
			}
			if(arrMat[i]->getidMaterial() == idMaterialB)
			{
				i = cont1;
			}
		}
		cout << "Ingrese Id del cliente: ";
		cin >> idClienteB;
		cout << "Ingrese dia de reserva: ";
		cin >> dia;
		cout << "Ingrese mes de reserva: ";
		cin >> mes;
		cout << "Ingrese anio de reserva: ";
		cin >> anio;
		fec.setFecha(dia, mes, anio);
		for(int i = 0; i < cont2; i++)
		{
		    if(idMaterialB == arrRev[i].getidMaterial())
		    {
            for(int i2 = 0; i2 < cont1; i2++)
		    	{
            if(arrMat[i2]->getidMaterial() == arrRev[i].getidMaterial())
		    	   {
            if(((fec >= arrRev[i].getfechaReservacion()) && (fec <= arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo()))) || (((fec + arrMat[i2]->cantidadDiasPrestamo()) >= arrRev[i].getfechaReservacion()) && ((fec + arrMat[i2]->cantidadDiasPrestamo()) <= arrRev[i].calculaFechaFinReserva(arrMat[i2]->cantidadDiasPrestamo()))))
			       {
                    cout << "El material se encuentra reservado durante dicha fecha" << endl;
                    bState = true;
                    changer1++;
                    break;
			       }
                else
			       {
			       	cout << "\n*El material ha sido reservado*" << endl;
                arrRev[cont2].setfechaReservacion(fec);
                arrRev[cont2].setidMaterial(idMaterialB);
                arrRev[cont2].setidCliente(idClienteB);
                cont2++;
                writeFile.open("Reserva.txt", ios::app);
                writeFile << endl;
                writeFile << fec.getDia() << " " << fec.getMes() << " " << fec.getAno() << " " << idMaterialB << " " << idClienteB;
                writeFile.close();
                bState = true;
                changer1++;
			       	break;
				   }
			       }
			    }
			    if(changer1>0){
                    break;
			    }
		    }
		    else
		    {
            if((bState == false) && (i == (cont2-1)))
		    	{
		    	cout << "\n*El material ha sido reservado*" << endl;
                arrRev[cont2].setfechaReservacion(fec);
                arrRev[cont2].setidMaterial(idMaterialB);
                arrRev[cont2].setidCliente(idClienteB);
                cont2++;
                writeFile.open("Reserva.txt", ios::app);
                writeFile << endl;
                writeFile << fec.getDia() << " " << fec.getMes() << " " << fec.getAno() << " " << idMaterialB << " " << idClienteB;
                writeFile.close();
                bState = true;
			       	break;
			       }
			}
	    }
		break;
	case 6:
	    //*****


		break;
	default:
	cout << "\nIngrese una opcion correcta: " << endl;
}
} while (opcionMenu != 6);
	return 0;
}
