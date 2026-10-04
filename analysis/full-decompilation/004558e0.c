
int __thiscall FUN_004558e0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  iVar4 = DAT_00666580;
  if (((uint)(param_3 + param_4) <= (uint)(iVar2 - iVar1)) &&
     (iVar3 = FUN_00455ada(param_3 + iVar1,iVar2,param_2,param_4 + param_2,param_3),
     iVar4 = DAT_00666580, iVar3 != iVar2)) {
    iVar4 = iVar3 - iVar1;
  }
  return iVar4;
}

