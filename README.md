# MASA-StarPU

<p align="justify">
The <b>MASA-StarPU extension</b> is used with the <a href="https://github.com/edanssandes/MASA-Core">MASA architecture</a> to align DNA sequences of unrestricted size with multiple task scheduling policies provided by StarPU.
</p>

### Compiling (masa-StarPU)

```
cd masa-starpu
./configure
make
```

In order to compile masa-StarPU successfully, you need to install the StarPU packages (Nanos++ runtime library and Mercurium compiler). See the [StarPU download pages](http://pm.bsc.es/StarPU-downloads). For Ubuntu, you can download and install all the packages with the following commands (running with root privileges):

```
# echo 'deb http://pm.bsc.es/StarPU/packages/debian wheezy main' > /etc/apt/sources.list.d/StarPU.list
# wget -O - http://pm.bsc.es/StarPU/packages/debian/StarPU.gpg.key | apt-key add -
# apt-get update && apt-get install StarPU
```


### Executing

```
./masa-StarPU [options] seq1.fasta seq2.fasta
```
All the command line arguments can be retrieved using the --help parameter. See the [wiki](https://github.com/edanssandes/MASA-Core/wiki/Command-line-examples) for a list of command line examples.


### License:

MASA-StarPU is an open source project with public license (GPLv3). A copy of the [LICENSE](https://raw.githubusercontent.com/edanssandes/MASA-StarPU/master/LICENSE) is maintained in this repository. 

