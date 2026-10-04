
void __thiscall FUN_005f358e(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar5 = *(int *)(param_1 + 0xd8);
  piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + iVar5 * 4);
  iVar4 = *(int *)(param_1 + 0xd4) - *piVar1;
  cVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x48))();
  local_8 = iVar4;
  local_c = iVar4;
  if (cVar2 != '\0') {
    for (; -1 < local_8; local_8 = local_8 + -1) {
      if (-1 < local_8 + -2) {
        iVar4 = **(int **)(param_1 + 0x114);
        iVar3 = FUN_004096c2(0xffffffff);
        iVar3 = (**(code **)(iVar4 + 0x44))(iVar3 + -2 + *piVar1 + local_8);
        iVar4 = local_c;
        if (1 < iVar3) {
          local_c = local_c + (1 - iVar3);
          local_8 = local_8 + (1 - iVar3);
          iVar4 = local_c;
        }
      }
    }
  }
  iVar5 = iVar5 + param_2;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2 <= iVar5) {
    iVar5 = (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + iVar5 * 4);
  iVar5 = piVar1[1];
  if ((iVar5 < iVar4) &&
     (((char)piVar1[8] != '\0' || (iVar4 = iVar5, *(char *)((int)piVar1 + 0x21) != '\0')))) {
    iVar4 = iVar5 + -1;
  }
  cVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x48))();
  if (cVar2 == '\0') {
    iVar4 = (*piVar1 - *(int *)(param_1 + 0xd4)) + iVar4;
  }
  else {
    FUN_005f2c6c(*piVar1 - *(int *)(param_1 + 0xd4),param_3,0);
  }
  FUN_005f2c6c(iVar4,param_3,1);
  FUN_005f37cd();
  return;
}

