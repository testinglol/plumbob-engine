
undefined4 FUN_006460e8(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (DAT_0070513c == 0) {
    return 0;
  }
  FUN_0063d88b(0x19);
  uVar2 = 0xffffffff;
  do {
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      uVar2 = 0xffffffff;
      break;
    }
    param_1 = param_1 + 1;
    uVar2 = FUN_00649531(cVar1,uVar2);
    bVar3 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar3);
  FUN_0063d8ec(0x19);
  return uVar2;
}

