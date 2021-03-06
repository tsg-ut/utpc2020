filename="$1"
sample="$2"
bin="./bin/${filename%.*}"
./.vscode/build.sh "$filename" || exit 1

if [ ! -f "$sample" ]; then
  echo "$sample not exists"
  exit 1
fi

echo "=== Input ==="
cat "$sample"
echo ""

echo "=== Output ==="
if [ -d /usr/local/share/crystal-0.33.0-1 ] || [ -d /tmp/crystal-0.33.0-1 ]; then
  "${bin}" < "$sample" | tee out.txt
else
  docker run -v "$PWD":/mnt -i crystallang/crystal:0.33.0 "/mnt/${bin}" < $sample | tee out.txt
fi