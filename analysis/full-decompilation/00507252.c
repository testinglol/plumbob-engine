
int FUN_00507252(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004cbb08(1);
  if (cVar1 != '\0') {
    return 0;
  }
  cVar1 = FUN_004cbb08(2);
  if (cVar1 == '\0') {
    cVar1 = FUN_004cbb08(4);
    if (cVar1 == '\0') {
      cVar1 = FUN_004cbb08(8);
      if (cVar1 == '\0') {
        cVar1 = FUN_004cbb08(0x20);
        if (cVar1 == '\0') {
          cVar1 = FUN_004cbb08(0x40);
          if (cVar1 == '\0') {
            cVar1 = FUN_004cbb08(0x10);
            if (cVar1 == '\0') {
              cVar1 = FUN_004cbb08(0x80);
              return (-(uint)(cVar1 != '\0') & 7) - 1;
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

