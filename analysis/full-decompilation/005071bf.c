
int FUN_005071bf(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004cbaac(1);
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = FUN_004cbaac(2);
  if (cVar1 == '\0') {
    cVar1 = FUN_004cbaac(0x20);
    if (cVar1 == '\0') {
      cVar1 = FUN_004cbaac(8);
      if (cVar1 == '\0') {
        cVar1 = FUN_004cbaac(4);
        if (cVar1 == '\0') {
          cVar1 = FUN_004cbaac(0x10);
          if (cVar1 == '\0') {
            cVar1 = FUN_004cbaac(0x80);
            if (cVar1 == '\0') {
              cVar1 = FUN_004cbaac(0x40);
              return (-(uint)(cVar1 != '\0') & 8) - 1;
            }
            iVar2 = 6;
          }
          else {
            iVar2 = 5;
          }
        }
        else {
          iVar2 = 4;
        }
      }
      else {
        iVar2 = 3;
      }
    }
    else {
      iVar2 = 2;
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

