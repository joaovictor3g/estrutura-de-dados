function fib(n)  
    if n == 0 || n == 1
        return n
    end
    return fib(n-1) + fib(n-2)
end

function mostrar(i)   
    while i <= 50
        print(fib(i), " ")
        i+=1
    end
    print("\n")
end
mostrar(0)