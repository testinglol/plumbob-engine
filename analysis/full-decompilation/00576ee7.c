
void __thiscall FUN_00576ee7(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)*param_2;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = *(int *)(param_1 + 4);
    iVar3 = *(int *)(param_1 + 8);
    uVar4 = FUN_005b8dba(puVar1[1]);
    uVar4 = uVar4 % (uint)(iVar3 - iVar2 >> 2);
    puVar6 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar4 * 4);
    if (puVar6 == puVar1) {
      *(undefined4 *)(*(int *)(param_1 + 4) + uVar4 * 4) = *puVar6;
LAB_00576f3a:
      FUN_00576c1d(puVar6);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
    else {
      puVar5 = puVar6;
      for (puVar6 = (undefined4 *)*puVar6; puVar6 != (undefined4 *)0x0;
          puVar6 = (undefined4 *)*puVar6) {
        if (puVar6 == puVar1) {
          *puVar5 = *puVar6;
          goto LAB_00576f3a;
        }
        puVar5 = puVar6;
      }
    }
  }
  return;
}

