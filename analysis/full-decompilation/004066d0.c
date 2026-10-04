
int __fastcall FUN_004066d0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0xc);
  do {
    if (*piVar2 == 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
  } while (iVar3 < 8);
  return iVar1;
}

