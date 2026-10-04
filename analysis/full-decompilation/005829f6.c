
void __thiscall FUN_005829f6(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_2 * 4 + *(int *)(param_1 + 4));
  while (puVar2 != param_3) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_0040189d(puVar2,0xc);
    *(undefined4 **)(param_2 * 4 + *(int *)(param_1 + 4)) = puVar1;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    puVar2 = puVar1;
  }
  return;
}

