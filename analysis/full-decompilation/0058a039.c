
void __thiscall FUN_0058a039(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x138);
  *(short *)(iVar1 + 0x5de) = (short)param_2;
  *(ushort *)(iVar1 + 0x5e0) = (ushort)(param_2 != 0);
  *(undefined2 *)(iVar1 + 0x5e2) = 0;
  *(undefined2 *)(iVar1 + 0x5e4) = 1;
  *(undefined2 *)(iVar1 + 0x5e6) = 0;
  return;
}

