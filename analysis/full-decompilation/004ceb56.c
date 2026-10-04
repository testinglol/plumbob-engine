
void __fastcall FUN_004ceb56(int param_1)

{
  FUN_005d4bbf(&DAT_006de560);
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 0x40;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_0050a9c0(param_1);
  }
  return;
}

