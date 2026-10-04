
int FUN_00645496(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *DAT_00703ad8;
  piVar3 = DAT_00703ad8;
  while( true ) {
    if (iVar2 == 0) {
      return -((int)piVar3 - (int)DAT_00703ad8 >> 2);
    }
    iVar2 = FUN_00648f3a(param_1,iVar2,param_2);
    if ((iVar2 == 0) && ((sVar1 = *(short *)(*piVar3 + param_2 * 2), sVar1 == 0x3d || (sVar1 == 0)))
       ) break;
    iVar2 = piVar3[1];
    piVar3 = piVar3 + 1;
  }
  return (int)piVar3 - (int)DAT_00703ad8 >> 2;
}

