
void __thiscall FUN_00582884(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + param_2 * 4);
  if (puVar3 == param_3) {
    FUN_00582849(param_2,param_4);
  }
  else {
    puVar1 = (undefined4 *)*puVar3;
    while (puVar2 = puVar1, puVar2 != param_3) {
      puVar3 = puVar2;
      puVar1 = (undefined4 *)*puVar2;
    }
    while (puVar2 != param_4) {
      *puVar3 = *puVar2;
      FUN_005bbecb(puVar2);
      puVar2 = (undefined4 *)*puVar3;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
  }
  return;
}

