if [ ! -d "cmocka-1.1.0/build" ]; then
  echo "No cmocka-1.1.0/build found"
  wget https://cmocka.org/files/1.1/cmocka-1.1.0.tar.xz
  tar -xvf cmocka-1.1.0.tar.xz
  mkdir cmocka-1.1.0/build
  cmake -DCMAKE_INSTALL_PREFIX=/home/travis/build/alvadorn/data_structure/cmocka -DCMAKE_BUILD_TYPE=Debug -Bcmocka-1.1.0/build -Hcmocka-1.1.0
fi
