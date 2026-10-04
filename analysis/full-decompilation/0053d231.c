
void __thiscall FUN_0053d231(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 1) {
LAB_0053d24d:
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  else {
    if (param_3 != 3) {
      if (param_3 == 5) goto LAB_0053d24d;
      if (param_3 != 6) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x14) = param_2;
  }
  return;
}

