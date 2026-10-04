
int __thiscall FUN_005d00fa(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = *(int **)(param_1 + 0x1c);
  while( true ) {
    if (piVar2 == *(int **)(param_1 + 0x20)) {
      return iVar1;
    }
    if ((*piVar2 != 0) && (iVar1 = FUN_005ceca4(param_2), iVar1 != 0)) break;
    piVar2 = piVar2 + 1;
  }
  return iVar1;
}

