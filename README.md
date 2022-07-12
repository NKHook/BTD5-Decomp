# BTD5-Decomp
A decompilation of Ninja Kiwi's game [Bloons TD 5](https://store.steampowered.com/app/306020/Bloons_TD_5/). This is made possible by the use of [Avast's RetDec](https://github.com/avast/retdec) decompiler.

## The process
1. The script downloads RetDec
2. The script runs retdec on the file target/BTD5-Win.exe
3. A cmake script is generated to make the build possible
4. The patches are then applied to the decompiled source