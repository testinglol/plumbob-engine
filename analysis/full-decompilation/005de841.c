
undefined4 __thiscall FUN_005de841(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_3;
  if ((((iVar2 < param_2[2]) && (iVar1 = *param_2, iVar1 < param_3[2])) && (param_3[1] < param_2[3])
      ) && (param_2[1] < param_3[3])) {
    if (iVar2 < iVar1) {
      iVar2 = iVar1;
    }
    *param_1 = iVar2;
    iVar2 = param_2[1];
    if (param_2[1] <= param_3[1]) {
      iVar2 = param_3[1];
    }
    param_1[1] = iVar2;
    iVar2 = param_2[2];
    if (param_3[2] <= param_2[2]) {
      iVar2 = param_3[2];
    }
    param_1[2] = iVar2;
    iVar2 = param_2[3];
    if (param_3[3] <= param_2[3]) {
      iVar2 = param_3[3];
    }
    param_1[3] = iVar2;
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  else {
    param_1[3] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    uVar3 = 0;
  }
  return uVar3;
}

