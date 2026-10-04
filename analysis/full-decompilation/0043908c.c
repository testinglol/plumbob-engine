
void __thiscall FUN_0043908c(int param_1,byte param_2)

{
  if (DAT_006d6184 != 0) {
    if ((param_2 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x160) = 0x7fffffff;
      *(undefined4 *)(param_1 + 0x164) = 0x7fffffff;
      *(undefined4 *)(param_1 + 0x168) = 0x80000000;
      *(undefined4 *)(param_1 + 0x16c) = 0x80000000;
    }
    if ((param_2 & 2) != 0) {
      *(undefined4 *)(param_1 + 0x170) = 0x7fffffff;
      *(undefined4 *)(param_1 + 0x174) = 0x7fffffff;
      *(undefined4 *)(param_1 + 0x178) = 0x80000000;
      *(undefined4 *)(param_1 + 0x17c) = 0x80000000;
    }
  }
  return;
}

