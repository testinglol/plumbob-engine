
undefined4 __thiscall FUN_0041f473(int param_1,int param_2)

{
  short sVar1;
  undefined4 in_EAX;
  int iVar2;
  
  sVar1 = *(short *)(param_1 + 8);
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),sVar1);
  if ((int)sVar1 == (int)(short)param_2 || (int)sVar1 - (int)(short)param_2 < 0) {
    *(undefined2 *)(param_1 + 8) = 0;
  }
  else {
    iVar2 = iVar2 - param_2;
    *(short *)(param_1 + 8) = (short)iVar2;
  }
  return CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(param_1 + 8));
}

