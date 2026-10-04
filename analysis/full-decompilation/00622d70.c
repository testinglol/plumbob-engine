
void __thiscall FUN_00622d70(int param_1,int param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  iVar2 = 1000000;
  iVar5 = 0;
  iVar3 = param_2;
  local_4 = param_1;
  do {
    iVar4 = 0;
    do {
      iVar1 = FUN_00622e00(iVar5,iVar4,param_2);
      if (iVar1 < iVar2) {
        iVar2 = iVar1;
        iVar3 = iVar5;
        local_4 = iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  iVar2 = iVar3 * 0xff + 8;
  *param_3 = ((char)(iVar2 / 0xf) + (char)(iVar2 >> 0x1f)) -
             (char)((longlong)iVar2 * 0x88888889 >> 0x3f);
  iVar2 = local_4 * 0xff + 8;
  *param_4 = ((char)(iVar2 / 0xf) + (char)(iVar2 >> 0x1f)) -
             (char)((longlong)iVar2 * 0x88888889 >> 0x3f);
  return;
}

