
void __thiscall FUN_0046df0d(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 8)) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1 << ((byte)param_2 & 0x1f);
  }
  return;
}

