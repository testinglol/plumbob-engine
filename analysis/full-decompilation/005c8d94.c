
undefined1 __thiscall FUN_005c8d94(int param_1,int param_2,int *param_3,int param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 local_5;
  
  if ((((param_3[2] <= *param_3) || (param_3[3] <= param_3[1])) || (param_5[2] <= *param_5)) ||
     (((param_5[3] <= param_5[1] || (piVar1 = *(int **)(param_2 + 4), piVar1 == (int *)0x0)) ||
      (iVar3 = *(int *)(param_4 + 4), iVar3 == 0)))) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_3,iVar3,param_5,0x200,0);
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 == 0) {
LAB_005c8e35:
    local_5 = 1;
  }
  else {
    if (iVar2 == -0x7789fe3e) {
      iVar2 = FUN_005caa0d();
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 != 0) {
        return 0;
      }
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,param_3,iVar3,param_5,0x200,0);
      *(int *)(param_1 + 4) = iVar3;
      if (iVar3 == 0) goto LAB_005c8e35;
    }
    local_5 = FUN_005c8cc4(param_2,param_3,param_4,param_5);
  }
  return local_5;
}

