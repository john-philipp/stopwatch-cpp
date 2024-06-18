function before() {
  echo [INFO] "Running 'before'..."
  set -e
  if [[ $(basename "$(pwd)") == build || -d build ]]; then
    rm -rf build
  fi

  mkdir build
  cd build
}

function after() {
  echo [INFO] "Running 'after'..."
}
