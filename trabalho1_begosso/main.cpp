#include <iostream>
#include <cstring>

using namespace std;

struct  cidade{
    int codigo;
    string nome;
    char uf[2];
};

struct  especialidade_med{
    int codigo;
    string descricao;
};

struct  medico{
    int codigo;
    string nome;
    int codigoEspecialidade;
    string endereco;
    int telefone;
    int codigoCidade;
};

struct paciente{
    int cpf;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct CID{
    int codigo;
    string descricao;
};

struct medicamentos{
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct consultas{
    int cpf_paciente;
    int cod_medico;
    string data;
    string horario;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

void leitu_cidade(cidade cida[]){
    int i = 0;
    for(int saida = 1; i < 3 && saida != 0; i++) {
        cout << "\nCodigo: " << (i+1) << " :";
        cin >> cida[i].codigo;
        if(cida[i].codigo > 0) {
            cout << "\nNome da cidade: ";
            cin >> cida[i].nome;
            cout << "\nEstado: ";
            cin >> cida[i].uf;
        } else saida = 0;
    }
}

int buscaCidade(cidade cida[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != cida[m].codigo; m = (i+f)/2){
        if( cod > cida[m].codigo){
            i = m +1;
        } else f = m -1;
    }
    if(cod == cida[m].codigo){
        cout <<"\n\n Cidade encontrada";
        cout << "\nCodigo cidade: " << cida[m].codigo;
        cout << "\nNome cidade: " << cida[m].nome;
        cout << "\nEstado: " << cida[m].uf;
        return m;
    }else {
        cout << "\n\n Codigo nao Encontrado!";
        return -1;
    }
}

void leitu_especia(especialidade_med esp[]){
    int i = 0;
    for(int saida = 1; i < 3 && saida != 0; i++){
        cout << "\nCodigo: " << (i+1) << " : ";
        cin >> esp[i].codigo;
        if(esp[i].codigo > 0) {
            cout << "\nDescricao: ";
            cin >> esp[i].descricao;
        }else saida = 0;
    }
}

int buscaEspec(especialidade_med esp[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != esp[m].codigo; m = (i+f)/2){
        if( cod > esp[m].codigo){
            i = m +1;
        } else f = m -1;
    }
    if(cod == esp[m].codigo){
        cout <<"\n\n Especialidade encontrada";
        cout << "\nCodigo especialidade: " << esp[m].codigo;
        cout << "\nDescricao especialidade: " << esp[m].descricao;
        return m;
    }else {
        cout << "\n\n Codigo nao Encontrado!";
        return -1;
    }
}

void leitu_CID(CID cid[]){
    int i = 0;
    for(int saida = 1; i < 3 && saida != 0; i++) {
        cout << "\nCodigo:" << (i+1) << ":";
        cin >> cid[i].codigo;
        if(cid[i].codigo > 0) {
            cout << "\nDescricao: ";
            cin >> cid[i].descricao;
        } else saida = 0;
    }
}

int buscaCid(CID cid[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != cid[m].codigo; m = (i+f)/2){
        if( cod > cid[m].codigo){
            i = m +1;
        } else f = m -1;
    }
    if(cod == cid[m].codigo){
        cout <<"\n\n CID encontrado";
        cout << "\nCodigo CID: " << cid[m].codigo;
        cout << "\nDescricao CID: " << cid[m].descricao;
        return m;
    }else {
        cout << "\n\n Codigo nao Encontrado!";
        return -1;
    }
}

void leitu_Medic(medicamentos medic[]){
    int i = 0;
    for(int saida = 1; i < 3 && saida != 0; i++) {
        cout << "\nCodigo: " << (i+1) << " : ";
        cin >> medic[i].codigo;
        if(medic[i].codigo > 0) {
            cout << "\nDescricao: ";
            cin >> medic[i].descricao;
            cout << "\nQuantidade estoque: ";
            cin >> medic[i].quant_estoque;
            cout << "\nEstoque minimo: ";
            cin >> medic[i].estoque_minimo;
            cout << "\nEstoque maximo: ";
            cin >> medic[i].estoque_maximo;
            cout << "\nPreco unitario: ";
            cin >> medic[i].preco_unitario;
        } else saida = 0;
    }
}

int buscaMedica(medicamentos medic[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != medic[m].codigo; m = (i+f)/2){
        if( cod > medic[m].codigo){
            i = m +1;
        } else f = m -1;
    }
    if(cod == medic[m].codigo){
        cout <<"\n\n Medicamento encontrado";
        cout << "\nCodigo: " << medic[m].codigo;
        cout << "\nDescricao: " << medic[m].descricao;
        cout << "\nQuantidade estoque: " << medic[m].quant_estoque;
        cout << "\nEstoque minimo: " << medic[m].estoque_minimo;
        cout << "\nEstoque maximo: " << medic[m].estoque_maximo;
        cout << "\nPreco unitario: " << medic[m].preco_unitario;
        cout << "\nValor total do remedio: " << (medic[m].quant_estoque * medic[m].preco_unitario);
        return m;
    }else {
        cout << "\n\n Codigo nao Encontrado!";
        return -1;
    }
}


void lerMedico(medico medi[], especialidade_med medic[], cidade cida[], int &contador){
    int i = 0;
    int posicaoEspec;
    int novoEspec;
    int posicaoCida;
    int novoCida;
    for(int saida = 1; i < 3 && saida != 0; i++) {
        cout << "\nCodigo: " << (i+1) << " : ";
        cin >> medi[i].codigo;
        if(medi[i].codigo > 0) {
            cout << "\nNome: ";
            cin >> medi[i].nome;
            cout << "\nCodigo Especialidade: ";
            cin >> posicaoEspec;
            novoEspec = buscaEspec(medic, posicaoEspec);
            if (novoEspec == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoEspec;
                novoEspec = buscaEspec(medic, posicaoEspec);
            }else{
                medi[i].codigoEspecialidade = medic[novoEspec].codigo;
            }
            cout << "\nCodigo Cidade: ";
            cin >> posicaoCida;
            novoCida = buscaCidade(cida, posicaoCida);
            if (novoCida == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoCida;
                novoCida = buscaCidade(cida, posicaoCida);
            }else{
                medi[i].codigoCidade = cida[novoCida].codigo;
            }
            cout << "\nEndereco: ";
            cin >> medi[i].endereco;
            cout << "\nTelefone: ";
            cin >> medi[i].telefone;
        } else saida = 0;
    }
    contador = i - 1;
}


int buscaMedico(medico medi[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != medi[m].codigo; m = (i+f)/2){
        if( cod > medi[m].codigo){
            i = m +1;
        } else f = m -1;
    }
    if(cod == medi[m].codigo){
        cout <<"\n\n Medico encontrado";
        cout << "\nCodigo: " << medi[m].codigo;
        cout << "\nNome: " << medi[m].nome;
        cout << "\nEndereco: " << medi[m].endereco;
        cout << "\nCodigo Especialidade: " << medi[m].codigoEspecialidade;
        cout << "\nCodigo Cidade: " << medi[m].codigoCidade;
        cout << "\nTelefone: " << medi[m].telefone;
        return m;
    }else {
        cout << "\n\n Codigo nao Encontrado!";
        return -1;
    }
}

void inclusaoMedico(medico x[], int contX, medico y[], int contY, medico z[], int &contZ){
    int i = 0, j = 0, k = 0;
    for(; i < contX && j < contY; k++){
        if(x[i].codigo < y[i].codigo){
            z[k].codigo = x[i].codigo;
            z[k].nome = x[i].nome;
            z[k].endereco = x[i].endereco;
            z[k].codigoEspecialidade = x[i].codigoEspecialidade;
            z[k].codigoCidade = x[i].codigoCidade;
            z[k].telefone = x[i].telefone;
            i++;
        } else {
            z[k].codigo = y[j].codigo;
            z[k].nome = y[j].nome;
            z[k].endereco = y[j].endereco;
            z[k].codigoEspecialidade = y[j].codigoEspecialidade;
            z[k].codigoCidade = y[j].codigoCidade;
            z[k].telefone = y[j].telefone;
            j++;
        }
    }
    while (i < contX){
        z[k].codigo = x[i].codigo;
        z[k].nome = x[i].nome;
        z[k].endereco = x[i].endereco;
        z[k].codigoEspecialidade = x[i].codigoEspecialidade;
        z[k].codigoCidade = x[i].codigoCidade;
        z[k].telefone = x[i].telefone;
        i++;
        k++;
    }
    while (j < contY){
        z[k].codigo = y[j].codigo;
        z[k].nome = y[j].nome;
        z[k].endereco = y[j].endereco;
        z[k].codigoEspecialidade = y[j].codigoEspecialidade;
        z[k].codigoCidade = y[j].codigoCidade;
        z[k].telefone = y[j].telefone;
        j++;
        k++;
    }
    contZ = k;
}

void mostrarMedico(medico medi[], int cont){
    if(cont > 0) {
        cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
        for (int i = 0; i < cont; i++) {
            cout << "\nCodigo: " << medi[i].codigo;
            cout << "\nNome: " << medi[i].nome;
            cout << "\nEndereco: " << medi[i].endereco;
            cout << "\nCodigo Especialidade: " << medi[i].codigoEspecialidade;
            cout << "\nCodigo Cidade: " << medi[i].codigoCidade;
            cout << "\nTelefone: " << medi[i].telefone;
            cout << endl;
        }
    }else {cout << "\nSem registro";}
}

void lerPaciente(paciente paci[], cidade cida[], int &contador){
    int i = 0;
    int posicaoCida;
    int novoCida;
    for(int saida = 1; i < 3 && saida != 0; i++) {
        cout << "\nCPF: ";
        cin >> paci[i].cpf;
        if(paci[i].cpf > 0 && paci[i].cpf < 12) {
            cout << "\nNome: ";
            cin >> paci[i].nome;
            cout << "\nCodigo Cidade: ";
           cin >> posicaoCida;
            novoCida = buscaCidade(cida, posicaoCida);
            if (novoCida == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoCida;
                novoCida = buscaCidade(cida, posicaoCida);
            }else{
                paci[i].codigo_cidade = cida[novoCida].codigo;
            }
            cout << "\nEndereco: ";
            cin >> paci[i].endereco;
        } else saida = 0;
    }
    contador = i - 1;
}

int buscaPaciente(paciente paci[], int cod){
    int i = 0, f = 2;
    int m = (i+f)/2;
    for(; f >= i && cod != paci[m].cpf; m = (i+f)/2){
        if( cod > paci[m].cpf){
            i = m +1;
        } else f = m -1;
    }
    if(cod == paci[m].cpf){
        cout <<"\n\n Paciente encontrado";
        cout << "\nCPF: " << paci[m].cpf;
        cout << "\nNome: " << paci[m].nome;
        cout << "\nEndereco: " << paci[m].endereco;
        cout << "\nCodigo Cidade: " << paci[m].codigo_cidade;

        return m;
    }else {
        cout << "\n\n CPF nao Encontrado!";
        return -1;
    }
}

void inclusaoPaciente(paciente x[], int contX, paciente y[], int contY, paciente z[], int &contZ){
    int i = 0, j = 0, k = 0;
    for(; i < contX && j < contY; k++){
        if(x[i].cpf < y[i].cpf){
            z[k].cpf = x[i].cpf;
            z[k].nome = x[i].nome;
            z[k].endereco = x[i].endereco;
            z[k].codigo_cidade = x[i].codigo_cidade;
            i++;
        } else {
            z[k].cpf = y[j].cpf;
            z[k].nome = y[j].nome;
            z[k].endereco = y[j].endereco;
            z[k].codigo_cidade = y[j].codigo_cidade;
            j++;
        }
    }
    while (i < contX){
        z[k].cpf = x[i].cpf;
        z[k].nome = x[i].nome;
        z[k].endereco = x[i].endereco;
        z[k].codigo_cidade = x[i].codigo_cidade;
        i++;
        k++;
    }
    while (j < contY){
        z[k].cpf = y[j].cpf;
        z[k].nome = y[j].nome;
        z[k].endereco = y[j].endereco;
        z[k].codigo_cidade = y[j].codigo_cidade;
        j++;
        k++;
    }
    contZ = k;
}

void mostrarPaci(paciente paci[], int cont){
    cout << "\n\nLista dos Registros de Paciente Atualizado" << endl;
    if ( cont > 0) {
        for (int i = 0; i < cont; i++) {
            cout << "\nCPF: " << paci[i].cpf;
            cout << "\nNome paciente: " << paci[i].nome;
            cout << "\nCodigo Cidade: " << paci[i].codigo_cidade;
            cout << "\nEndereco: " << paci[i].endereco;
            cout << endl;
        }
    }else {cout << "\nSem registro";}
}

void exclusaoPaci(paciente x[],int contX, int y[], int contY, paciente z[], int &contZ){
    int i=0,j=0,k=0;
    for(;j < contY; i++){
        if(x[i].cpf != y[j]){
            z[k].cpf = x[i].cpf;
            z[k].nome = x[i].nome;
            z[k].endereco = x[i].endereco;
            z[k].codigo_cidade = x[i].codigo_cidade;
            k++;
        } else j++;
    }
    while (i < contX){
        z[k].cpf = x[i].cpf;
        z[k].nome = x[i].nome;
        z[k].endereco = x[i].endereco;
        z[k].codigo_cidade = x[i].codigo_cidade;
        i++;
        k++;
    }
    contZ = k;
}

void mostarExcluPac(paciente z[], int contZ){
    cout << "\n\nLista dos Resgistro Paciente Excluido Atualizado";
    for(int i = 0; i < contZ; i++) {
        cout << "\nCPF: " << z[i].cpf;
        cout << "\nNome: " << z[i].nome;
        cout << "\nEndereco: " << z[i].endereco;
        cout << "\nCodigo Cidade: " << z[i].codigo_cidade;
        cout << endl;
    }
}

void agendamento(consultas age[], paciente x[], medico y[], medicamentos z[], CID a[], int cont){
    int i =0;
    int posicaoCPF, posicaoMedic,  posicaoCID, posicaoMedica;
    int novoCPF, novoMedic, novoCID, novoMedica;
    for(int saida = 1; i < cont && saida != 0; i++) {
        cout << "\n\nCadastro de agendamento";
        cout << "\nCpf do paciente: ";
        cin >> age[i].cpf_paciente;
        if (age[i].cpf_paciente > 0 && age[i].cpf_paciente < 12) {
            posicaoCPF = age[i].cpf_paciente;
            novoCPF = buscaPaciente(x, posicaoCPF);
            if (novoCPF == -1) {
                cout << "\n\nCPF invalido";
                cin >> posicaoCPF;
                novoCPF = buscaPaciente(x,posicaoCPF);
            } else {
                age[i].cpf_paciente = x[novoCPF].cpf;
            }
            cout << "\n Codigo Medico: ";
            cin >> posicaoMedic;
            novoMedic = buscaMedico(y, posicaoMedic);
            if (novoMedic == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoMedic;
                novoMedic = buscaMedico(y,posicaoMedic);
            } else {
                age[i].cod_medico = y[novoMedic].codigo;
            }
            cout << "\nData: ";
            cin >> age[i].data;
            cout << "\nHora: ";
            cin >> age[i].horario;
            cout << "\n Codigo CID: ";
            cin >> posicaoCID;
            novoCID = buscaCid(a, posicaoCID);
            if (novoCID == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoCID;
                novoCID = buscaCid(a,posicaoCID);
            } else {
                age[i].cod_CID = a[novoCID].codigo;
            }
            cout << "\n Codigo Medicamento: ";
            cin >> posicaoMedica;
            novoMedica = buscaMedica(z, posicaoMedica);
            if (novoMedica == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoMedica;
                novoMedica = buscaMedica( z,posicaoMedica);
            } else {
                age[i].cod_medicamento = z[novoMedica].codigo;
                cout << "\nQuantidade de medicamento: ";
                cin >> age[i].qtde_medicamento;
                if (z[novoMedica].codigo == age[i].cod_medicamento ){
                    if(z[novoMedica].quant_estoque > 0 && age[i].qtde_medicamento <= z[novoMedica].estoque_maximo){
                        z[novoMedica].quant_estoque = z[novoMedica].quant_estoque - age[i].qtde_medicamento;
                        cout << "\nQuantidade de medicamento pedido: " << age[i].qtde_medicamento;
                        cout <<"\nQuantidade de medicamento q resta no estoque: " << z[novoMedica].quant_estoque << endl;
                        cout << "\nDescricao do medicamento: " << z[novoMedica].descricao << endl;
                    }else {
                        cout << "\n\nValor maior que a quantidade";
                    }
                }else {
                    cout << "\n\nSem o remedio";
                }
            }
        } else saida = 0;
    }
}

void QtdeMedica(medicamentos x[], int cont){
    int qtdeComprar = 0, valorRemedio = 0, valorTotal = 0;
    cout << "\n\nMedicamento abaixo do estoque minimo";
    for(int i = 0; i < 3; i++){
        cout << "\n\nCodigo do medicamento: ";
        cin >> x[i].codigo;
        if(x[i].codigo != 0 && x[i].quant_estoque < x[i].estoque_minimo){
            buscaMedica(x, cont);
            qtdeComprar = x[i].estoque_maximo - x[i].quant_estoque;
            cout << "\nQuantidade a ser comprada: " << qtdeComprar << endl;
            valorRemedio = qtdeComprar * x[i].preco_unitario;
            cout << "\nValor da compra: " << valorRemedio << endl;
        }
        valorTotal = valorTotal + valorRemedio;
        cout << "\nValor total da compra de todos os remedio: " << valorTotal << endl;
    }
}


void valor(medicamentos x[], consultas y[],int cont){
    int consulta = 0, arrecadado = 0, consul =0;
    for(int i = 0; i < cont; i++) {
        cout << "\nCodigo medicamento: " << y[i].cod_medicamento;
        if (y[i].cod_medicamento == x[i].codigo) {
            consulta = (y[i].qtde_medicamento * x[i].preco_unitario);
            cout << "\nValor dos medicamentos receitados: " << consulta;
            consul = (consul + consulta);
        }else {cout << "\ncodigo invalido";
            i = i+5;

        }
    }
    cont = (cont * 100);
    arrecadado = (cont + consul);
    cout << "\nValor total das concusultas: " << cont;
    cout <<"\nTotal arrecadado: " << arrecadado;
}


int main() {
    cidade cida[10];
    especialidade_med esp[10];
    CID cid[10];
    medicamentos medic[10];
    consultas consu[10];
    medico mediX[10],mediY[10], mediZ[20];
    paciente paciX[10], paciY[10], paciZ[20];
    int paciT[10];
    int contX,contY, contZ, contX1,contY1, contZ1;
    int contX2,contY2,contZ2, cont =5;
/*
    int codigoP;
    cout <<"\n\nLeitura cidade" << endl;
    leitu_cidade(cida);
    for (codigoP = 9; codigoP != 0;){
        cout << "\n\nInforme o Codigo da cidade a ser Buscado: ";
        cin >> codigoP;
        if (codigoP != 0){
            buscaCidade(cida, codigoP);
    }
    }

    int codigoE;
    cout <<"\n\nLeitura especialidade"<< endl;
    leitu_especia(esp);
    for (codigoE = 9; codigoE != 0;){
        cout << "\n\nInforme o Codigo da especialidade a ser Buscado: ";
        cin >> codigoE;
        if (codigoE != 0){
            buscaEspec(esp, codigoE);
    }
   }

    int codigoC;
    cout <<"\n\nLeitura CID" << endl;
    leitu_CID(cid);
    for (codigoC = 9; codigoC != 0;){
        cout << "\n\nInforme o Codigo da CID a ser Buscado: ";
        cin >> codigoC;
        if (codigoC != 0){
            buscaCid(cid, codigoC);
    }
    }
*/
    int codigoM;
    cout <<"\n\nLeitura medicamento" << endl;
    leitu_Medic(medic);
    for (codigoM = 9; codigoM != 0;){
        cout << "\n\nInforme o Codigo do medicamento a ser Buscado: ";
        cin >> codigoM;
        if (codigoM != 0) {
            buscaMedica(medic, codigoM);
        }
        }
/*
    int codigoMe, codigoMe2;
    cout << "\n\nLeitura medico X" << endl;
    lerMedico(mediX, esp, cida, contX);
    cout << "\n\nLeitura medico Y" << endl;
    lerMedico(mediY, esp, cida, contY);
    for (codigoMe= 9; codigoMe != 0;){
        cout << "\n\nInforme o Codigo do medico X a ser Buscado: ";
        cin >> codigoMe;
        if (codigoMe != 0) {
            buscaMedico(mediX, codigoMe);
        }
        }
        for (codigoMe2= 9; codigoMe2 != 0;){
        cout << "\n\nInforme o Codigo do medico Y a ser Buscado: ";
        cin >> codigoMe2;
        if (codigoMe2 != 0) {
            buscaMedico(mediY, codigoMe2);
        }
        }
    inclusaoMedico(mediX, contX, mediY, contY, mediZ, contZ);
    mostrarMedico(mediZ, contZ);

    int cpfPaci, cpfPaci2;
    cout << "\n\nLeitura paciente X" << endl;
    lerPaciente(paciX,cida,contX1);
    cout << "\n\nLeitura paciente Y" << endl;
    lerPaciente(paciY,cida,contY1);
    for (cpfPaci= 9; cpfPaci != 0;) {
        cout << "\n\nInforme o CPF do paciente X a ser Buscado: ";
        cin >> cpfPaci;
        if (cpfPaci != 0) {
            buscaPaciente(paciX, cpfPaci);
        }
    }
    for (cpfPaci2= 9; cpfPaci2 != 0;) {
        cout << "\n\nInforme o CPF do paciente Y a ser Buscado: ";
        cin >> cpfPaci2;
        if (cpfPaci2 != 0) {
            buscaPaciente(paciY, cpfPaci2);
        }
    }
    inclusaoPaciente(paciX, contX1, paciY, contY1, paciZ, contZ1);
    mostrarPaci(paciZ, contZ1);

    for(contY2 = 0; contY2 < 20 && paciT[contY2 - 1] > 0; contY2++){
        cout << "\nInforme o CPF do resgistro a ser excluido: ";
        cin >> paciT[contY2];
    }
    contY2--;
    exclusaoPaci(paciX, contX2, paciT, contY2, paciZ, contZ2);
    mostarExcluPac(paciZ, contZ2);
*/
    cout << "\n\nAgendamento: ";
    agendamento(consu,paciZ,mediZ,medic,cid, cont);

    QtdeMedica(medic, cont);

    cout <<"\n\nContador de arrecadacao";
    valor(medic, consu, cont);

    return 0;
}