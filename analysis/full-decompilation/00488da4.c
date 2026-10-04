
char __fastcall FUN_00488da4(int param_1)

{
  SHORT SVar1;
  SHORT SVar2;
  char cVar3;
  
  SVar1 = GetKeyState(0x10);
  SVar2 = GetKeyState(0x11);
  cVar3 = SVar2 < 0;
  if (*(char *)(param_1 + 0x3f) != '\0' || SVar1 < 0) {
    cVar3 = cVar3 + '\x02';
  }
  return cVar3;
}

