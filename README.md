```
ARG=($(python3 -c "import random; print(' '.join(str(random.randint(-2**31, 2**31 - 1)) for _ in range(100)))"))
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | ./checker_linux $ARG

./push_swap $ARG | wc -l
```
