
void FUN_005944c5(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  FUN_006326ae(&local_8);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) && (iVar2 = 0, 0 < local_8)) {
    do {
      FUN_006326ae(&param_1);
      FUN_00594082(piVar1);
      if (piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
    } while ((((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) &&
            (iVar2 = iVar2 + 1, iVar2 < local_8));
  }
  return;
}

