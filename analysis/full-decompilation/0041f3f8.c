
undefined4 __thiscall FUN_0041f3f8(int param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),*(short *)(param_1 + 8));
  if ((int)*(short *)(param_1 + 8) + (int)(short)param_2 < 0x7fff) {
    iVar1 = iVar1 + param_2;
    *(short *)(param_1 + 8) = (short)iVar1;
  }
  else {
    *(undefined2 *)(param_1 + 8) = 0x7fff;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(param_1 + 8));
}

