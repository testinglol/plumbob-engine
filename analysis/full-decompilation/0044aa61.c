
undefined4 __fastcall FUN_0044aa61(int param_1)

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
  } while (iVar2 < 0x10);
  if (DAT_006c3f1c == 0) {
    (*DAT_006c3f24)(param_1);
  }
  return 0;
}

