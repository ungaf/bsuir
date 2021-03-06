package main

import (
	"fmt"
	"os"
)

func PrintSetLn(s []int) {

	if len(s) == 0 {

		fmt.Print("{ }")
		return

	}

	fmt.Print("{")
	for i := 0; i < len(s)-1; i++ {
		fmt.Printf("%d, ", s[i])
	}
	fmt.Printf("%d}\n", s[len(s)-1])
}

func PrintCortegeSetLn(s [][2]int) {

	if len(s) == 0 {

		fmt.Print("{ }")
		return

	}

	fmt.Print("{")
	for i := 0; i < len(s)-1; i++ {
		fmt.Printf("<%d, %d>, ", s[i][0], s[i][1])
	}
	fmt.Printf("<%d, %d>}\n", s[len(s)-1][0], s[len(s)-1][1])

}

func main() {

	var mode int

	fmt.Print("Выберите способ задания множеств:\n\t1 - Перечисление\n\t2 - Высказывание\nВаш выбор: ")
	fmt.Fscan(os.Stdin, &mode) // Пользователь выбирает способ задания множеств

	var first, second []int

	switch mode {

	case 1: // Если пользователь выбирает способ задания множеств перечислением

		var c1, c2 int

		fmt.Print("Введите мощность первого множества A: ")
		fmt.Fscan(os.Stdin, &c1) // Пользователь задает мощность первого множества

		fmt.Print("Задайте первое множество A: ")
		// Пользователь задает первое множество
		for i := 0; i < c1; i++ {
			var e int
			fmt.Fscan(os.Stdin, &e)
			first = append(first, e)
		}

		fmt.Print("Введите мощность второго множества B: ")
		fmt.Fscan(os.Stdin, &c2) // Пользователь задает мощность второго множества

		// Пользователь задает второе множество
		fmt.Print("Задайте первое множество: ")
		for i := 0; i < c2; i++ {
			var e int
			fmt.Fscan(os.Stdin, &e)
			second = append(second, e)
		}

	case 2:

		var c1, c2 int

		fmt.Print("Введите мощность множества А: ")
		fmt.Fscan(os.Stdin, &c1) // Пользователь задает мощность первого множества А

		for x := 1; x <= c1; x++ { // Присваиваем значение x = 1

			var a int
			a = x*x - 2*x + 9 // Вычисляем значение а по формуле, подставляя текущее значение х
			first = append(first, a) // Переносим значение а во множество А

			// Если значение х больше n, то множество задано
			// x = x + 1

		}

		fmt.Print("\nA = "); PrintSetLn(first) // Выведем на экран полученное множество A

		fmt.Print("Введите мощность множества B: ")
		fmt.Fscan(os.Stdin, &c2) // Пользователь задает мощность первого множества B

		for x := 1; x <= c2; x++ { // Присваиваем значение x = 1

			var a int
			a = x*x + 7*x + 1 // Вычисляем значение b по формуле, подставляя текущее значение х
			second = append(second, a) // Переносим значение b во множество B

			// Если значение х больше m, то множество задано
			// x = x + 1

		}

		fmt.Print("\nB = "); PrintSetLn(second) // Выведем на экран полученное множество B
	
	}

	fmt.Print("Выберите операцию из списка:\n\t1 - Объединение А и В\n\t2 - Пересечение А и В\n\t")
	fmt.Print("3 - Разность А и В\n\t4 - Разность В и А\n\t5 - Симметрическая разность А и В\n\t")
	fmt.Print("6 - Дополнение множества А\n\t7 - Дополнение множества В\n\t8 - Декартово произведение А и В\n\t")
	fmt.Print("9 - Декартово произведение В и А\nВаш выбор: ")

	fmt.Fscan(os.Stdin, &mode) // Пользователь задаёт операцию

	switch mode {

	case 1: // Если пользователь хочет найти объединение множеств А и В

		var d []int // Создаем новое пустое множество D

		d = first // Каждый элемент множества А переносим в множество D

		for i := 0; i < len(second); i++ { // Возьмём первый элемент множества В

			var add bool
			add = true

			for j := 0; j < len(d); j++ { // Возьмём первый элемент множества D

				if second[i] == d[j] {
					add = false
					break
				} // Если взятый элемент множества В равен взятому элементу D
										   // то, перейдём к следующему элементу В или закончим

			   // Если элемент множества D не последний, возьмём следующий элемент множества D

			}

			if add { d = append(d, second[i]) } // Если элемент множества D - последний, то добавим взятый элемент множества В в D

		}

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 2: // Если пользователь хочет найти пересечение множеств А и В:

		var d []int // Создаем новое пустое множество D

		for i := 0; i < len(first); i++ { // Возьмём первый элемент множества А

			for j := 0; j < len(second); j++ { // Возьмём первый элемент множества В

				if first[i] == second[j] { d = append(d, first[i]) } // Если взятый элемент А равен взятому эл.
																	   // множества В, то добавим его в D

			   // Если не равен взятому В, то возьмём следующий элемент множества В, если тот не последний

			}

			// Если взятый элемент множества В - последний, то возьмём следующий элемент множества А

		}

		// Если взятый элемент множества А - последний, то выведем полученное множество на экран

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 3:

		var d []int // Создаем новое пустое множество D

		for i := 0; i < len(first); i++ { // Возьмём первый элемент множества А

			var add bool
			add = true

			for j := 0; j < len(second); j++ { // Возьмём первый элемент множества В

				if first[i] == second[j] { add = false; break } // Если взятый элемент А равен вз. элементу В, возьмём след. эл. А

				// Если взятый элемент множества В не явл. последним, то возьмём следующий эл. мн. В

			}

			if !add { continue }
			// Если вз. эл. множества В - последний, то добавим вз. элемент множества А во мн. D
			d = append(d, first[i])

			// Если элемент мн. А - не последний, возьмём след. эл. мн. А

		}

		// Если эл. мн. А - последний, выведем на экран мн. D

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 4:

		var d []int // Создаем новое пустое множество D

		for i := 0; i < len(second); i++ { // Возьмём первый элемент множества B

			var add bool
			add = true

			for j := 0; j < len(first); j++ { // Возьмём первый элемент множества A

				if second[i] == first[j] { add = false; break } // Если взятый элемент B равен вз. элементу A, возьмём след. эл. B

				// Если взятый элемент множества A не явл. последним, то возьмём следующий эл. мн. A

			}

			if !add { continue }
			// Если вз. эл. множества A - последний, то добавим вз. элемент множества B во мн. D
			d = append(d, second[i])

			// Если элемент мн. B - не последний, возьмём след. эл. мн. B

		}

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

		// Если эл. мн. B - последний, выведем на экран мн. D

		case 5:

			var d []int // Создаем новое пустое множество D

			// Разность множеств А и В

			var c []int // Создадим пустое множество С

			for i := 0; i < len(first); i++ { // Возьмём первый элемент множества А

				var add bool
				add = true

				for j := 0; j < len(second); j++ { // Возьмём первый элемент множества В

					if first[i] == second[j] {
						add = false
						break
					} // Если взятый элемент А равен вз. элементу В, возьмём след. эл. А

					// Если взятый элемент множества В не явл. последним, то возьмём следующий эл. мн. В

				}

				if !add {
					continue
				}
				// Если вз. эл. множества В - последний, то добавим вз. элемент множества А во мн. C
				c = append(c, first[i])

				// Если элемент мн. А - не последний, возьмём след. эл. мн. А

			}

			// Разность множеств В и А

			var f []int // Создадим новое пустое множество F

			for i := 0; i < len(second); i++ { // Возьмём первый элемент множества B

				var add bool
				add = true

				for j := 0; j < len(first); j++ { // Возьмём первый элемент множества A

					if second[i] == first[j] { add = false; break } // Если взятый элемент B равен вз. элементу A, возьмём след. эл. B

					// Если взятый элемент множества A не явл. последним, то возьмём следующий эл. мн. A

				}

				if !add { continue }
				// Если вз. эл. множества A - последний, то добавим вз. элемент множества B во мн. F
				f = append(f, second[i])

				// Если элемент мн. B - не последний, возьмём след. эл. мн. B

			}

			// Объединение множеств C и F

			d = c // Создаём новое пустое множество D. Каждый элемент множества C переносим в множество D

			for i := 0; i < len(f); i++ { // Возьмём первый элемент множества F

				var add bool
				add = true

				for j := 0; j < len(d); j++ { // Возьмём первый элемент множества D

					if f[i] == d[j] {
						add = false
						break
					} // Если взятый элемент множества F равен взятому элементу D
					// то, перейдём к следующему элементу F или закончим

					// Если элемент множества D не последний, возьмём следующий элемент множества D

				}

				if add { d = append(d, f[i]) } // Если элемент множества D - последний, то добавим взятый элемент множества В в D

			}

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 6:

		// Зададим множество U

		var u []int

		for x := 1; x <= 100; x++ { // Присвоим значение x = 1

			// Если x > 100, U задано
			u = append(u, x)
			// x = x + 1

		}

		var d []int // Создаем новое пустое множество D

		for i := 0; i < len(u); i++ { // Возьмём первый элемент множества U

			var add bool
			add = true

			for j := 0; j < len(first); j++ { // Возьмём первый элемент множества A

				if u[i] == first[j] { add = false; break } // Если взятый элемент U равен вз. элементу A, возьмём след. эл. U

				// Если взятый элемент множества A не явл. последним, то возьмём следующий эл. мн. A

			}

			if !add { continue }
			// Если вз. эл. множества A - последний, то добавим вз. элемент множества U во мн. D
			d = append(d, u[i])

			// Если элемент мн. U - не последний, возьмём след. эл. мн. U

		}

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 7:

		// Зададим множество U

		var u []int

		for x := 1; x <= 100; x++ { // Присвоим значение x = 1

			// Если x > 100, U задано
			u = append(u, x)
			// x = x + 1

		}

		var d []int // Создаем новое пустое множество D

		for i := 0; i < len(u); i++ { // Возьмём первый элемент множества U

			var add bool
			add = true

			for j := 0; j < len(second); j++ { // Возьмём первый элемент множества B

				if u[i] == second[j] { add = false; break } // Если взятый элемент U равен вз. элементу B, возьмём след. эл. U

				// Если взятый элемент множества B не явл. последним, то возьмём следующий эл. мн. B

			}

			if !add { continue }
			// Если вз. эл. множества B - последний, то добавим вз. элемент множества U во мн. D
			d = append(d, u[i])

			// Если элемент мн. U - не последний, возьмём след. эл. мн. U

		}

		fmt.Print("\nD = "); PrintSetLn(d) // Выведем на экран полученное множество D

	case 8:

		var d [][2]int // Создадим новое пустое множество D

		for i := 0; i < len(first); i++ { // Возьмём первый элемент множества А

			for j := 0; j < len(second); j++ { // Возьмём первый элемент множества В

				cortege := [2]int{first[i], second[j]} // Создаём кортеж из двух элементов, первый - вз. эл. А, второй - вз. эл. В
				d = append(d, cortege)

				// Возьмём следующий элемент множества В

			}

			// Если элемент множества В - последний, возьмём следующий элемент множества А

		}

		// Если элемент множества А - последний, выведем на экран полученное множество

		PrintCortegeSetLn(d)

	case 9:

		var d [][2]int // Создадим новое пустое множество D

		for i := 0; i < len(second); i++ { // Возьмём первый элемент множества B

			for j := 0; j < len(first); j++ { // Возьмём первый элемент множества A

				cortege := [2]int{second[i], first[j]} // Создаём кортеж из двух элементов, первый - вз. эл. B, второй - вз. эл. A
				d = append(d, cortege)

				// Возьмём следующий элемент множества A

			}

			// Если элемент множества A - последний, возьмём следующий элемент множества B

		}

		// Если элемент множества B - последний, выведем на экран полученное множество

		PrintCortegeSetLn(d)

	}

}
