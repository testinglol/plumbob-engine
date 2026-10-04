
undefined8 FUN_0060c5d4(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = param_3 ^ param_2;
  if ((param_2 & 0x80000000) != 0) {
    bVar4 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar4 - param_2;
  }
  if ((param_3 & 0x80000000) != 0) {
    param_3 = -param_3;
  }
  iVar1 = (int)((ulonglong)param_3 * (ulonglong)param_1);
  iVar2 = param_3 * param_2 + (int)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20);
  if ((uVar3 & 0x80000000) != 0) {
    bVar4 = iVar1 != 0;
    iVar1 = -iVar1;
    iVar2 = -(uint)bVar4 - iVar2;
  }
  return CONCAT44(iVar2,iVar1);
}

