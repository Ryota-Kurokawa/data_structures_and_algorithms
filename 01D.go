package main

import "fmt"

func main() {
	var count int

	fmt.Scanf("%d", &count)
	arr := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	maxv := arr[1] - arr[0]

	for j := 0; j < count-1; j++ {
		for i := j + 1; i < count; i++ {
			if arr[i]-arr[j] > maxv {
				maxv = arr[i] - arr[j]
			}
		}
	}
	fmt.Println(maxv)
}
