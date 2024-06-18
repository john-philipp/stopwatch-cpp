scriptDir=$(dirname "$(pwd)/${BASH_SOURCE[0]}")
source "$scriptDir/methods.sh"

before

cmake ../src
make

after