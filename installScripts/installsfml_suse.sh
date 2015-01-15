set -e

zypper mr -e --all
zypper mr -d -l

zypper install openal-devel libsndfile-devel

#zypper install libxrandr-dev libjpeg62-dev libglew1.6-dev 
#libfreetype6-dev libsndfile1-dev libopenal-dev cmake 
#build-essential unzip


version=2.2
file=SFML-$version-sources.zip

cd /tmp

rm -rf SFML*
wget http://www.sfml-dev.org/download/sfml/$version/$file

unzip $file

cd SFML-$version

cmake -DCMAKE_INSTALL_PREFIX=/usr CMakeLists.txt 
make
make install