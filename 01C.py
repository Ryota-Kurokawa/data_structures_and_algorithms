def is_prime(n):
  split_counter = 0
  if n < 2:
    return False
  for i in range(2, n + 1):
    if n % i == 0:
      split_counter += 1

  if split_counter > 1:
    return False
  else:
    return True

n = int(input())
arr = []
for i in range(0, n):
  input_num = int(input())
  arr.append(input_num)

count = 0
for i in arr:
  if is_prime(i):
    count += 1
print(count)
