
void __fastcall FUN_004e7045(int param_1)

{
  undefined1 uVar1;
  
  FUN_004e60c8(1);
  uVar1 = 1;
  DAT_006f0138 = uVar1;
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  DAT_006f013a = uVar1;
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  *(undefined1 *)(param_1 + 1) = 1;
  FUN_004e6166(2);
  FUN_004e61c6(2);
  *(undefined4 *)(param_1 + 0x14) = 8;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057afae(8);
  }
  *(undefined4 *)(param_1 + 0x18) = 8;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057b015(8);
  }
  *(undefined4 *)(param_1 + 0x1c) = 8;
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057b07c(8);
  }
  DAT_006c2971 = uVar1;
  FUN_004322cf(1);
  FUN_004e6387(1);
  DAT_006c9f91 = uVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  DAT_006d7444 = 0;
  DAT_006d74f0 = 0xfa;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined1 *)(param_1 + 0x20) = 1;
  return;
}

