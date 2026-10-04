
int __thiscall FUN_005d9912(int param_1,int param_2)

{
  uint3 uVar2;
  int iVar1;
  
  uVar2 = (uint3)((uint)*(int *)(param_1 + 0x20) >> 8);
  if (*(int *)(param_1 + 0x20) == param_2) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar1 = CONCAT31(uVar2,1);
  }
  else {
    iVar1 = (uint)uVar2 << 8;
  }
  return iVar1;
}

