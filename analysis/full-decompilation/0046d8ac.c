
void __thiscall FUN_0046d8ac(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0x34) < 0) {
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
    uVar1 = *(undefined2 *)(param_1 + 0x30);
    FUN_0046d7b3(param_2);
    *(undefined2 *)(param_1 + 0x34) = uVar1;
    FUN_0040766a(0x109,1);
  }
  return;
}

