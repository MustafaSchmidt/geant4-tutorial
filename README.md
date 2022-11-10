# geant4-tutorial

Repository for the learning process/tests with Geant4

</br>

## Versão utilizada

Geant4 11.0.3 (mais recente até então)

</br>
</br>
</br>

## Installation of Geant4

Aviso: o seguinte método contempla uma instalação feita utilizando o código fonte do Geant4 (build from source).
</br>
</br>

### 1. Antes de instalar o Geant4

Recomenda-se primeiro baixar as seguintes bibliotecas:

```bash
cmake cmake-curses-gui gcc g++ libexpat1-dev qt5-default libxmu-dev libmotif-dev
```

Note: for the case ```qt5-default``` has no installation candidate you may try the following
(it is supposed to install qt5 dependencies without using ```qt5-default```)

```bash
qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```

</br>

### 2. Download Geant4 source code

Você pode baixar a última versão do código pelo próprio GitHub [aqui](https://github.com/Geant4/geant4/releases), ou no
[site oficial](https://geant4.web.cern.ch/support/download).

</br>

### 3. Passo-a-passo para a instalação (single-thread)

Recomenda-se criar um folder para a instalação do Geant4. Isso servirá para poder controlar múltiplas versões instaladas (tanto de diferentes releases
como de diferentes builds -- ex.: single vs multithread) e servirá também para deletá-las mais facilmente, caso precise. No caso, criaremos um folder na própria `home`:

```bash
cd ~/

mkdir geant4

cd geant4
```

Caso não tenha baixado, pode baixar e descompactar o arquivo-fonte aqui mesmo (exemplo com a versão 11.0.3):

```bash
wget -c https://github.com/Geant4/geant4/archive/refs/tags/v11.0.3.tar.gz

tar -xzvf v11.0.3.tar.gz

cd geant4-11.0.3
```

Para iniciar o build:

```bash
mkdir build

cd build

ccmake ..
```

Na tela do terminal, aperte `c` para configurar (algumas mensagens vão aparecer, mas, se não houver nenhum erro, podemos prosseguir) e depois `e`.

Escolha as opções que deseja alterar. No caso, pressionando `Enter` para modificar as configurações, recomendamos que:

* Modifique o campo de `CMAKE_INSTALL_PREFIX` para um folder ao lado da versão baixada:

```bash
/home/$USER_NAME_HERE$/geant4/geant4-11.0.3-install/
```

* Modifique:

  * `GEANT4_BUILD_MULTITHREADED` para `OFF` (recomendamos uma [outra instalação](https://github.com/jhapreis/geant4-tutorial/blob/master/README.md#3-passo-a-passo-para-a-instala%C3%A7%C3%A3o-single-thread) para habilitar multithreads);

  * `GEANT4_INSTALL_DATA` para `ON`;

  * `GEANT4_USE_QT` para `ON`;

  * `GEANT4_USE_RAYTRACER_X11` para `ON`;

Após, aperte `c` para compilar os arquivos `Make`, novamente `c` (caso algumas bibliotecas opcionais não tenham sido encontradas -- não é um erro) e, finalmente `g` para gerar o arquivo de `Make` do Geant4.

</br>

### 4. Compilar e instalar

Finalmente, rode o comando `make` para compilar o Geant4. Isso pode demorar MUITO tempo, então, se o seu dispositivo conseguir, utilize a compilação Multithread para poder executar mais rapidamente. No exemplo, utilizamos 4 threads.

```bash
make -j4
```

Obs.: enquanto compila, ele vai baixar alguns arquivos adicionais, então é necessário ter conexão com a Internet. Além disso, ele compile excessivamente mais rápido do que consegue baixar os arquivos, erros podem vir a ocorrer. Portanto, assegure-se de ter uma boa conexão com a Internet (ou diminua o número de threads).

Após a compilação terminar, rode o comando

```bash
make install
```

para realizar a instalação (esse comando deve executar mais rápido).

Após isso, é necessário rodar o comando de source para poder garantir que a localidade dos arquivos seja encontrada. No caso, vale mais a pena adicionar ao final do arquivo `~/.bashrc`:

```bash
. /home/$USER_NAME_HERE$/geant4/geant4-11.0.3-install/share/Geant-11.0.3/geant4make/geant4make.sh
```

</br>

### 5. Teste da instalação

Para testar a instalação, podemos rodar um dos programas de demo do próprio Geant4. Acesse o arquivo no caminho

```bash
cd /home/$USER_NAME_HERE$/geant4/geant4-11.0.3/examples/basic/B1/

mkdir build

cd build

cmake ..

make

./exampleB1
```
