
void __thiscall FUN_00540ecf(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c + param_2 * 4) = 1;
  }
  return;
}

