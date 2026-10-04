
uint __thiscall FUN_0041f662(int param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_0041f723(param_2,param_3);
  if (iVar1 == *(int *)(param_1 + 8)) {
    *param_4 = 0xffff;
    uVar3 = (uint)param_4 & 0xffff0000;
  }
  else {
    iVar2 = (iVar1 - *(int *)(param_1 + 4)) / 0xc;
    *param_4 = (short)iVar2;
    uVar3 = CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar1 + 8));
  }
  return uVar3;
}

