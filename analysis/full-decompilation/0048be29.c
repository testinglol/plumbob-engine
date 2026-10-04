
undefined4 __fastcall FUN_0048be29(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x38) == 3) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048c2bc();
  }
  FUN_0048bff5(uVar2);
  for (puVar1 = *(undefined4 **)(param_1 + 0x2c); puVar1 != *(undefined4 **)(param_1 + 0x30);
      puVar1 = puVar1 + 1) {
    (**(code **)(*(int *)*puVar1 + 0x18))();
  }
  return 0;
}

