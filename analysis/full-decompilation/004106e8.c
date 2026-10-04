
undefined4 __thiscall
FUN_004106e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_0042ed71(*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x130));
  *(undefined4 *)(param_1 + 0x10c) = param_3;
  iVar1 = FUN_00410dc5(param_1,param_2,0x46414d49,param_3,param_4);
  return CONCAT31((int3)((uint)-iVar1 >> 8),'\x01' - (iVar1 != 0));
}

