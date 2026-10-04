
void __thiscall FUN_005d0a0d(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x78) = *param_2;
  *(undefined4 *)(param_1 + 0x7c) = param_2[1];
  *(undefined4 *)(param_1 + 0x80) = param_2[2];
  *(undefined4 *)(param_1 + 0x84) = *param_3;
  *(undefined4 *)(param_1 + 0x88) = param_3[1];
  *(undefined4 *)(param_1 + 0x8c) = param_3[2];
  FUN_0049b802();
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x8c);
  FUN_005d0b5a();
  return;
}

