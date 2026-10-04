
undefined4 __fastcall FUN_00607d39(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_4;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  iStack_4 = param_1;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    uStack_18 = 0x607d55;
    (**(code **)(*(int *)puVar2[2] + 4))();
  }
  uStack_1c = *(undefined4 *)(param_1 + 0xc);
  uStack_18 = uStack_1c;
  FUN_00602902(&uStack_1c);
  FUN_00578f92(&iStack_4);
  if (*(char *)(param_1 + 0x2c) != '\0') {
    uStack_18 = 0x607d81;
    FUN_00608fed();
    *(undefined1 *)(param_1 + 0x2c) = 0;
  }
  if (*(char *)(param_1 + 0x2d) != '\0') {
    uStack_18 = 0x607d8e;
    FUN_00608704();
    *(undefined1 *)(param_1 + 0x2d) = 0;
  }
  *(undefined1 *)(param_1 + 8) = 0;
  return 1;
}

