
int FUN_00623b20(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 >> 0x10 & 0xff) - (param_2 >> 0x10 & 0xff);
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  iVar2 = (param_1 >> 8 & 0xff) - (param_2 >> 8 & 0xff);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar1 = (param_1 & 0xff) - (param_2 & 0xff);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  return iVar1 + iVar2 + iVar3;
}

