# geant4-tutorial
Repository for the learning process/tests with Geant4

</br>



# Versão utilizada: 

Geant4 11.0.3 (mais recente até então)

</br>
</br>
</br>


# Installation of Geant4

Aviso: o seguinte método contempla uma instalação feita utilizando o código fonte do Geant4 (build from source).
</br>
</br>



## 1. Antes de instalar o Geant4

Recomenda-se primeiro baixar as seguintes bibliotecas:

```
cmake cmake-curses-gui gcc g++ libexpat1-dev qt5-default libxmu-dev libmotif-dev
```

Note: for the case ```qt5-default``` has no installation candidate you may try the following
(it is supposed to install qt5 dependencies without using ```qt5-default```)

```
qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```



## 2. Download Geant4 source code
Você pode baixar a última versão do código pelo próprio GitHub [aqui](https://github.com/Geant4/geant4/releases), ou no 
[site oficial](https://geant4.web.cern.ch/support/download).



## 3. Passo-a-passo para a instalação
Recomenda-se criar um folder para a instalação do Geant4. Isso servirá para poder controlar múltiplas versões instaladas (tanto de diferentes releases 
como de diferentes builds -- ex.: single vs multithread) e servirá também para deletá-las mais facilmente, caso precise.

No caso, criaremos um folder na própria `home`:

```
cd ~/

mkdir geant4

cd geant4
```

Caso não tenha baixado, pode baixar e descompactar o arquivo-fonte aqui mesmo (exemplo com a versão 11.0.3):

```
wget -c https://github.com/Geant4/geant4/archive/refs/tags/v11.0.3.tar.gz

tar -xzvf v11.0.3.tar.gz
```


