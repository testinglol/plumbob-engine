
char FUN_0048a777(void)

{
  SHORT SVar1;
  SHORT SVar2;
  char cVar3;
  
  SVar1 = GetKeyState(0x10);
  SVar2 = GetKeyState(0x11);
  cVar3 = SVar2 < 0;
  if (SVar1 < 0) {
    cVar3 = cVar3 + '\x02';
  }
  return cVar3;
}

