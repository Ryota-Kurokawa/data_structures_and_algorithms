// 1万回Helloworldを出力するまでの時間を測る

package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	for i := 0; i < 1000000; i++ {
		fmt.Println("Hello, World!")
	}
	end := time.Now()
	fmt.Println("time:", end.Sub(start))
}
