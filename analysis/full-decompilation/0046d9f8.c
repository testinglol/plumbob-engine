
void __thiscall FUN_0046d9f8(int param_1,int param_2)

{
  if (*(short *)(param_1 + 0x50) == 0) {
    *(int *)(param_1 + 0x90) = param_2;
    *(short *)(param_1 + 0x2c) = (short)(param_2 / 10000);
    *(short *)(param_1 + 0x2a) = (short)(param_2 % 10000);
    FUN_0040766a(0xda,param_2);
  }
  return;
}

