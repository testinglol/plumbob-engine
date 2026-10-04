
int * __thiscall FUN_006331bc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint unaff_retaddr;
  
  iVar2 = FUN_006327fb(1);
  if (iVar2 != 0) {
    uVar3 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x18))
                      (param_2,param_3);
    param_1[2] = uVar3;
    if (uVar3 < unaff_retaddr) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 3;
    }
    FUN_00632716();
  }
  return param_1;
}

