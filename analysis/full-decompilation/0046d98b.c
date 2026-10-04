
void __thiscall FUN_0046d98b(int param_1,undefined2 param_2,undefined2 param_3)

{
  short sVar1;
  int iVar2;
  
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x1a) = param_3;
  FUN_0040766a(0xdb,0);
  sVar1 = *(short *)(param_1 + 0x18);
  iVar2 = FUN_0046d641();
  if (iVar2 != sVar1) {
    *(short *)(param_1 + 0x18) = (short)iVar2;
    FUN_004c482f();
    FUN_0040766a(0xdd,0);
  }
  return;
}

