
void __thiscall FUN_00425540(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 0x14) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0x10;
  }
  FUN_00464973(param_1 + 0x128,uVar1);
  if (0x3f < param_3) {
    FUN_0042ff31(param_1 + 0x194,param_2,param_3);
  }
  if (param_3 < 0x42) {
    *(undefined1 *)(param_1 + 0x1a0) = 0;
    *(undefined1 *)(param_1 + 0x1a1) = 1;
  }
  else {
    FUN_0046494e(param_1 + 0x1a0);
    FUN_0046494e(param_1 + 0x1a1);
  }
  if (param_3 < 0x44) {
    *(undefined1 *)(param_1 + 0x1a2) = 0;
    *(undefined1 *)(param_1 + 0x1a3) = 1;
  }
  else {
    FUN_0046494e(param_1 + 0x1a2);
    FUN_0046494e(param_1 + 0x1a3);
  }
  if (param_3 < 0x45) {
    *(undefined1 *)(param_1 + 0x1aa) = 1;
  }
  else {
    FUN_0046494e(param_1 + 0x1aa);
  }
  if (param_3 < 0x46) {
    *(undefined1 *)(param_1 + 0x1a4) = 0;
    *(undefined1 *)(param_1 + 0x1a5) = 1;
    *(undefined1 *)(param_1 + 0x1a6) = 0;
    *(undefined1 *)(param_1 + 0x1a7) = 1;
  }
  else {
    FUN_0046494e(param_1 + 0x1a4);
    FUN_0046494e(param_1 + 0x1a5);
    FUN_0046494e(param_1 + 0x1a6);
    FUN_0046494e(param_1 + 0x1a7);
  }
  if (param_3 < 0x49) {
    *(undefined1 *)(param_1 + 0x1a8) = 0;
    *(undefined1 *)(param_1 + 0x1a9) = 1;
  }
  else {
    FUN_0046494e(param_1 + 0x1a8);
    FUN_0046494e(param_1 + 0x1a9);
  }
  return;
}

