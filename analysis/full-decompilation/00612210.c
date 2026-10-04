
void FUN_00612210(undefined4 *param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((-1 < param_3) && (param_3 < *(int *)(*param_2 + 0x14))) {
    puVar3 = (undefined4 *)(param_2[2] * param_3 + param_2[1]);
    for (uVar1 = *(uint *)(*param_2 + 0x10) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)param_1 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
  }
  return;
}

