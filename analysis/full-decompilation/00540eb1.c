
void __thiscall FUN_00540eb1(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(undefined4 *)(param_1 + 0x38) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x34 + param_2 * 4) = 1;
  }
  return;
}

