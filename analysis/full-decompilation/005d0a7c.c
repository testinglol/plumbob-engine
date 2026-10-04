
void __thiscall FUN_005d0a7c(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x84) = *param_2;
  *(undefined4 *)(param_1 + 0x88) = param_2[1];
  *(undefined4 *)(param_1 + 0x8c) = param_2[2];
  FUN_0049b802();
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x8c);
  FUN_005d0b5a();
  return;
}

