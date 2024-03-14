folder="build"
workspace=$(cd "$(dirname "$0")" && pwd)
path=${workspace}${target}
cd $path
if [ ! -d "$path/$folder" ]; then
    mkdir $folder
    is_first_complie=true
fi
cd $folder
cmake ..
make

