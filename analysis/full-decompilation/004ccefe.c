
void __thiscall
FUN_004ccefe(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  *(undefined4 *)(param_1 + 0x24) = 2;
  FUN_005a5e48(0);
  *(undefined4 *)(param_1 + 0x44) = param_2;
  FUN_005d499c(param_3);
  FUN_005d499c(param_4);
  *(undefined4 *)(param_1 + 0x1c) = param_5;
  *(undefined4 *)(param_1 + 0x38) = 7;
  FUN_004cc877(0,4);
  if (*(int *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 8) = *(undefined4 *)(param_1 + 0x44);
  }
  return;
}

