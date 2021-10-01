s=input()
def reverse(s,l):
  if(l==len(s)):
    return
  reverse(s,l+1)
  print(s[l])

reverse(s,0)
