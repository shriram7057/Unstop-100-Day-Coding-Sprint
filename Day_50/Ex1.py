def solve(ar):
  ans = []
  def backtrack(ind, res):
    if ind == len(ar):
      ans.append(res.copy())
      return
    res.append(ar[ind])
    backtrack(ind+1, res)
    res.pop()
    backtrack(ind+1, res)
  backtrack(0, [])
  for i in range(len(ans)-1,-1,-1):
    for j in range(len(ans[i])):
      print(ans[i][j], end=' ')
    print()

input()
solve(list(map(int, input().split())))