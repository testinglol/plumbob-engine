
int FUN_00507130(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004cba76(8);
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = FUN_004cba76(0x20);
  if (cVar1 == '\0') {
    cVar1 = FUN_004cba76(2);
    if (cVar1 == '\0') {
      cVar1 = FUN_004cba76(0x80);
      if (cVar1 == '\0') {
        cVar1 = FUN_004cba76(1);
        iVar2 = 4;
        if (cVar1 == '\0') {
          cVar1 = FUN_004cba76(4);
          if (cVar1 == '\0') {
            cVar1 = FUN_004cba76(0x10);
            if (cVar1 == '\0') {
              cVar1 = FUN_004cba76(0x40);
              return (-(uint)(cVar1 != '\0') & 8) - 1;
            }
            iVar2 = 6;
          }
          else {
            iVar2 = 5;
          }
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

