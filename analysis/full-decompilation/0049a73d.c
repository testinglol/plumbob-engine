
int __thiscall FUN_0049a73d(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x20);
  FUN_00492d2c();
  return (int)*(short *)(*(int *)(param_1 + 4 + (3 - iVar1) * 4) +
                        ((*(int *)(param_2 + 0x24) +
                         (8 << ((byte)*(undefined4 *)(param_2 + 0x20) & 0x1f))) - param_3) * 2) +
         *(int *)(param_2 + 0x28);
}

