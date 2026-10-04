
void __thiscall FUN_0041e34e(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar1 = (undefined4 *)*param_2;
  if (puVar1 != (undefined4 *)0x0) {
    uVar4 = (uint)puVar1[1] % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2);
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar4 * 4);
    if (puVar3 == puVar1) {
      *(undefined4 *)(*(int *)(param_1 + 4) + uVar4 * 4) = *puVar3;
LAB_0041e395:
      FUN_0041e869(puVar3);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
    else {
      puVar2 = puVar3;
      for (puVar3 = (undefined4 *)*puVar3; puVar3 != (undefined4 *)0x0;
          puVar3 = (undefined4 *)*puVar3) {
        if (puVar3 == puVar1) {
          *puVar2 = *puVar3;
          goto LAB_0041e395;
        }
        puVar2 = puVar3;
      }
    }
  }
  return;
}

