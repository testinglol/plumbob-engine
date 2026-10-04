
void FUN_004706c3(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_004705f2(param_1,iVar2);
    if (iVar1 != 0) {
      if (param_2 == (undefined1 *)0x0) {
        return;
      }
      *param_2 = (char)iVar2;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  return;
}

