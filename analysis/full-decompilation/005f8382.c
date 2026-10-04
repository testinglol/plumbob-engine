
int __fastcall FUN_005f8382(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x80);
  iVar3 = 8;
  do {
    if (*piVar2 != 0) {
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

