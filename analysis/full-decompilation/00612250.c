
void FUN_00612250(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((-1 < param_3) && (param_3 < *(int *)(*param_2 + 0x10))) {
    iVar3 = *(int *)(*param_2 + 0x14);
    puVar2 = (undefined4 *)(param_2[1] + param_3 * 4);
    if (0 < iVar3) {
      iVar1 = param_2[2];
      do {
        *param_1 = *puVar2;
        param_1 = param_1 + 1;
        puVar2 = (undefined4 *)((int)puVar2 + iVar1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

