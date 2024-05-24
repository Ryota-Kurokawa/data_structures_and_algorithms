package main

import "fmt"

func main() {
	var n int
	var maxv = -1000000000

	x := 0
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		if i == 0 {
			x = a
		} else {
			if maxv < a-x {
				maxv = a - x
			}
			if x > a {
				x = a
			}
		}
	}
	fmt.Println(maxv)
}
