
void __thiscall FUN_004cd0b4(int param_1,undefined4 param_2,undefined1 param_3,undefined4 *param_4)

{
  FUN_005a5e48(param_2);
  *(undefined1 *)(param_1 + 0x4c) = param_3;
  if (param_4 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = *param_4;
    *(undefined4 *)(param_1 + 0x54) = param_4[1];
    *(undefined4 *)(param_1 + 0x58) = param_4[2];
    *(undefined4 *)(param_1 + 0x5c) = param_4[3];
  }
  return;
}

