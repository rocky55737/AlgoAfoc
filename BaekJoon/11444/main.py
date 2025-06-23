n = int(input())

f_dict = {
    "0": 0,
    "1": 1,
}

def fibonacci(number):
    if str(number) in f_dict:
        return f_dict[str(number)]
    if str(number - 1) in f_dict and str(number - 2) in f_dict:
        f_dict[str(number)] = (f_dict[str(number - 1)] + f_dict[str(number - 2)]) % 1000000007
    elif (number % 2 == 0):
        f_dict[str(number)] = fibonacci(number // 2) * (fibonacci(number // 2 - 1) + fibonacci(number // 2 + 1)) % 1000000007
    else :
        f_dict[str(number)] = (fibonacci(number // 2 + 1) * fibonacci(number // 2 + 1) + fibonacci(number // 2) * fibonacci(number // 2)) % 1000000007
    return f_dict[str(number)]

print(fibonacci(n))