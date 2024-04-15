package main

import (
	"fmt"
	"math"
)

func isPrimary(num int) bool {
	var result bool = true
	var split_num int
	split_num = int(math.Floor(math.Sqrt(float64(num))))
	for i := 2; i < split_num+1; i++ {
		if num%i == 0 {
			result = false
		}
	}
	return result
}

func main() {

	var count int
	num := 0
	fmt.Scanf("%d", &count)
	arr := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	for i := 0; i < count; i++ {
		if isPrimary(arr[i]) {
			num++
		}
	}
	fmt.Println(num)
}
