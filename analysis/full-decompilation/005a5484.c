
void __fastcall FUN_005a5484(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        FUN_005bbecb(puVar2);
        puVar2 = puVar1;
      }
      *(undefined4 *)(*(int *)(param_1 + 4) + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

