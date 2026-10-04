
float10 FUN_00610c90(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_1 & 0xff) - (param_2 & 0xff);
  iVar2 = (param_1 >> 8 & 0xff) - (param_2 >> 8 & 0xff);
  iVar3 = (param_1 >> 0x10 & 0xff) - (param_2 >> 0x10 & 0xff);
  return (float10)(iVar3 * iVar3 + iVar2 * iVar2 + iVar1 * iVar1);
}

