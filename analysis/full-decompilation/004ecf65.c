
void __fastcall FUN_004ecf65(int param_1)

{
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
  if (*(int *)(param_1 + 0xd8) < *(int *)(param_1 + 0xd4)) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd8);
  }
  FUN_004ec9ed();
  FUN_005e46f0(1);
  return;
}

