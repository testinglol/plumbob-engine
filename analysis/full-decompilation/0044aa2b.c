
undefined4 __fastcall FUN_0044aa2b(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = iVar3;
    if (DAT_006f2a04 != '\0') {
      iVar1 = iVar2;
    }
    param_1 = param_1 + iVar1;
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + 2;
  } while (iVar2 < 0x14);
  if (DAT_006c3e0c == 0) {
    (*DAT_006c3e14)(param_1);
  }
  return 0;
}

