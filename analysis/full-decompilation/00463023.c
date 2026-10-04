
int __thiscall FUN_00463023(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_00462f2f(param_2);
  uVar1 = *(undefined4 *)(param_2 + 0x40);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  return param_1 + 0x18;
}

