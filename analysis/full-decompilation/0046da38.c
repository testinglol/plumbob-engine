
void __thiscall FUN_0046da38(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x50) != 1) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) - param_3;
    piVar1 = (int *)(param_1 + 0x184 + param_2 * 4);
    *piVar1 = *piVar1 + param_3;
    iVar2 = *(int *)(param_1 + 0x90);
    *(short *)(param_1 + 0x2c) = (short)(iVar2 / 10000);
    *(short *)(param_1 + 0x2a) = (short)(iVar2 % 10000);
    FUN_0040766a(0xda,iVar2);
  }
  return;
}

