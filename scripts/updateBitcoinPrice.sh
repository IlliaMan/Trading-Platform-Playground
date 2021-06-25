#!/bin/bash 

curl https://api.coinbase.com/v2/prices/spot?currency=USD 2>/dev/null | python3 -c "import sys, json; print(json.load(sys.stdin)['data']['amount'])" > ../data/bitcoinPrice.txt 
