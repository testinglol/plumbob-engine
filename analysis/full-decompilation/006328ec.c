
int * __thiscall FUN_006328ec(int *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_8;
  
  uVar5 = 0;
  iVar2 = FUN_006327fb(0);
  if (iVar2 == 0) {
    return param_1;
  }
  iVar2 = *(int *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1);
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1) = 0;
  if ((param_2 != 0) && (iVar2 != 1)) {
    do {
      iVar3 = FUN_006340b6();
      if (iVar3 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 1;
        if (uVar5 != 0) goto LAB_00632991;
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 6;
        break;
      }
      iVar4 = FUN_00636918(iVar3);
      if (iVar4 != 0) break;
      local_8 = (undefined1)iVar3;
      *(undefined1 *)(uVar5 + param_2) = local_8;
      FUN_0063407d();
      uVar5 = uVar5 + 1;
    } while (uVar5 < iVar2 - 1U);
    if (uVar5 != 0) {
LAB_00632991:
      *(undefined1 *)(uVar5 + param_2) = 0;
      goto LAB_00632998;
    }
  }
  puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
  *puVar1 = *puVar1 | 2;
LAB_00632998:
  FUN_00632716();
  return param_1;
}

