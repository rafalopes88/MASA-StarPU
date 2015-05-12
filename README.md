# MASA-OmpSs

<p align="justify">
The <b>MASA-OmpSs extension</b> is used with the <a href="https://github.com/edanssandes/MASA-Core">MASA architecture</a> to align DNA sequences of unrestricted size with the Smith-Waterman/Needleman-Wunsch algorithms combined with Myers-Miller. It uses the <a href="https://pm.bsc.es/ompss">OmpsSs Programming model</a> to accelerate the computation time in CPU. 
</p>

### Download

Latest Version: [masa-ompss-1.0.1.1024.tar.gz](releases/masa-ompss-1.0.1.1024.tar.gz?raw=true)


### Compiling (masa-ompss)

```
tar -xvzf masa-ompss-1.0.1.1024.tar.gz
cd masa-ompss-1.0.1.1024
./configure
make
```

In order to compile masa-ompss successfully, you need to install the OmpSs packages (Nanos++ runtime library and Mercurium compiler). See the [OmpSs download pages](http://pm.bsc.es/ompss-downloads). For Ubuntu, you can download and install all the packages with the following commands (running with root privileges):

```
# echo 'deb http://pm.bsc.es/ompss/packages/debian wheezy main' > /etc/apt/sources.list.d/OmpSs.list
# wget -O - http://pm.bsc.es/ompss/packages/debian/ompss.gpg.key | apt-key add -
# apt-get update && apt-get install ompss
```


### Executing

```
./masa-ompss [options] seq1.fasta seq2.fasta
```
All the command line arguments can be retrieved using the --help parameter. See the [wiki](https://github.com/edanssandes/MASA-Core/wiki/Command-line-examples) for a list of command line examples.


### License:

MASA-OmpSs is an open source project with public license (GPLv3). A copy of the [LICENSE](https://raw.githubusercontent.com/edanssandes/MASA-OmpSs/master/LICENSE) is maintained in this repository. 

