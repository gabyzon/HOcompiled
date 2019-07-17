Ejercicios:

En un archivo de texto respuestas.md:

1. Escriban qué esperan de cada uno de los pasos:
	El preprocessing se encarga de las directivas # como los includes y las macros.
	Controla y clasifica que atributos son los creados por nosotros.
	Además determina cuales son los atributos externos que va a tener que buscar en el último paso (linkeo)
	
	El compilador 1 se encarga es la encargada de revisar si hay errores de sintaxis y de semántica.
	y de optimizar el código para eliminar codigo innecesario o redundante y lo traduce a assembler.
	Esto lo hace en tres pasos:
		a. El front end: Análisis sintáctico, semántico y léxico. Genera una intermediate representation (IR)
		b. El middle end: Toma la IR del front end y la optimiza.
		c. El back end: Genera el código de assembler y realiza optimizaciones de hardware (por ejemplo, elige qué registros se utilizan para las variables)
	
	El compilador 2, realiza optimizaciones de hardware, para que el uso de recursos sea adecuado y el uso de la memoria sea mas efectivo.
	
	Linkea nuestro codigo con las librerias que se utilizan en el mismo para que estén disponibles al ejecutarse.
	El linkeo puede ser estático o dinámico.
	
2. ¿Qué agregó el preprocesador?
	El preprocesador creó un nuevo archivo con el mismo nombre que el archivo .c pero con extensión .pp_c
	En este caso, el archivo calculator.h incluye <stdio.h> y, a su vez, todos los que éste incluye.
	
3. Identificar en la rutina de assembler las funciones
	Al ejecutar el make assembler se generó un archivo .asm
	Este archivo contiene el codigo traducido a assembler.
	Entre las funciones, se puede identificar la add_numbers de calculator.c entre las lineas 40 y 56.

4. Explicar qué quieren decir los símbolos que se crean en el objeto
	El paso genera los objetos en binario.
	Al ejecutar el make object se crea el archivo calculator.o que para leerlo debemos usar el comando nm.
	El ejecutar este comando podemos observar lo siguiente:
	
	000000000000003e 	T add_numbers
									U _GLOBAL_OFFSET_TABLE_
	0000000000000000 	T main
									U printf
	
	Aquí están identificadas las funciones add_numbers y main y las identifica con la letra T. Estas son las funciones que creamos nosotros.
	Además se pueden observar atributos no definidos identificados con la letra U. Estas son funciones externas que deben vincularse en el proximo paso.

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?
	Al ejecutar make executable, se genera el archivo calculator.e
	Este archivo ya es un archivo ejecutable que está vinculado con las librerias externas que requiere (dependencias).
	Si hacemos un nm, podremos observar esto:
	
	0000000000000688 	T add_numbers
	0000000000201010 	B __bss_start
	0000000000201010 	b completed.7697
									w __cxa_finalize@@GLIBC_2.2.5
	0000000000201000 	D __data_start
	0000000000201000 	W data_start
	0000000000000570 	t deregister_tm_clones
	0000000000000600 	t __do_global_dtors_aux
	0000000000200dc0 	t __do_global_dtors_aux_fini_array_entry
	0000000000201008 	D __dso_handle
	0000000000200dc8 	d _DYNAMIC
	0000000000201010 	D _edata
	0000000000201018 	B _end
	0000000000000714 	T _fini
	0000000000000640 	t frame_dummy
	0000000000200db8 	t __frame_dummy_init_array_entry
	00000000000008b4 	r __FRAME_END__
	0000000000200fb8 	d _GLOBAL_OFFSET_TABLE_
									w __gmon_start__
	000000000000074c 	r __GNU_EH_FRAME_HDR
	00000000000004f0 	T _init
	0000000000200dc0 	t __init_array_end
	0000000000200db8 	t __init_array_start
	0000000000000720 	R _IO_stdin_used
									w _ITM_deregisterTMCloneTable
									w _ITM_registerTMCloneTable
	0000000000000710 	T __libc_csu_fini
	00000000000006a0 	T __libc_csu_init
									U __libc_start_main@@GLIBC_2.2.5
	000000000000064a 	T main
									U printf@@GLIBC_2.2.5
	00000000000005b0 	t register_tm_clones
	0000000000000540 	T _start
	0000000000201010 	D __TMC_END__

	Como podemos ver ahora no hay ningún descriptor que no esté definido. El programa ya conoce
	y tiene incluidas todas las funciones y variables que necesita.