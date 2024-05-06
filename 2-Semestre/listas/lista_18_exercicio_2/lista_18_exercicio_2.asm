.data
base_prompt: .asciiz "Entre com a base: "
expoente_prompt: .asciiz "Entre com o expoente: "
result_prompt: .asciiz "Resultado: "

.text
.globl main

main:
    # Prompt para entrada da base
    li $v0, 4
    la $a0, base_prompt
    syscall

    # Ler a base
    li $v0, 5
    syscall
    move $s0, $v0 # Armazenar a base em $s0

    # Prompt para entrada do expoente
    li $v0, 4
    la $a0, expoente_prompt
    syscall

    # Ler o expoente
    li $v0, 5
    syscall
    move $s1, $v0 # Armazenar o expoente em $s1

    # Chamada da função potencia
    move $a0, $s0 # Passar a base como argumento
    move $a1, $s1 # Passar o expoente como argumento
    jal potencia
    move $s2, $v0 # Armazenar o resultado em $s2

    # Prompt para exibir o resultado
    li $v0, 4
    la $a0, result_prompt
    syscall

    # Exibir o resultado
    li $v0, 1
    move $a0, $s2
    syscall

    # Terminar o programa
    li $v0, 10
    syscall

potencia:
    # Procedimento para calcular a potência de um número
    # Argumentos:
    #   $a0: base
    #   $a1: expoente
    # Resultado:
    #   $v0: resultado da potência

    # Caso base: expoente == 0
    beq $a1, $zero, potencia_base_zero

    # Chamada recursiva: return base * potencia(base, expoente - 1)
    addi $sp, $sp, -8 # Reserva espaço para 2 registros no stack
    sw $ra, 4($sp)    # Salva o endereço de retorno
    sub $a1, $a1, 1   # Decrementa o expoente
    jal potencia       # Chama potencia recursivamente
    lw $ra, 4($sp)    # Restaura o endereço de retorno
    addi $sp, $sp, 8  # Libera espaço do stack
    mul $v0, $a0, $v0 # Calcula base * potencia
    jr $ra            # Retorna

potencia_base_zero:
    li $v0, 1          # Se o expoente é zero, retorna 1
    jr $ra             # Retorna
