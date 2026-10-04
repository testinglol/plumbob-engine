
void __thiscall FUN_00535b26(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xf4) + 0x84) - *(int *)(*(int *)(param_1 + 0xf4) + 0x7c);
  FUN_004cb1a2(iVar1 + 0xf + param_2,param_3 + 10);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 5;
  *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + -5;
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 5;
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -5;
  *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + (5 - (iVar1 + 10));
  return;
}

