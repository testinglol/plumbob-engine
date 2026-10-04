
undefined1 __thiscall
FUN_0060b44d(int *param_1,undefined4 param_2,int *param_3,char *param_4,uint param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_10;
  uint local_8;
  
  local_10 = 0;
  local_8 = param_3[1];
  iVar6 = *param_3;
  bVar2 = false;
  iVar1 = param_1[6];
  uVar4 = param_3[2] - iVar6;
  if ((param_5 != 0) && (cVar3 = (**(code **)(*param_1 + 0x3c))((int)*param_4), cVar3 != '\0')) {
    if (*(char *)((int)param_1 + 0x22) == '\0') {
      cVar3 = FUN_0060bec0(param_2);
      if (cVar3 == '\0') {
        return 0;
      }
      *(undefined1 *)((int)param_1 + 0x22) = 1;
      bVar2 = true;
    }
    while (((local_8 < (uint)param_3[3] && (local_10 < param_5)) &&
           (cVar3 = (**(code **)(*param_1 + 0x3c))((int)*param_4), cVar3 != '\0'))) {
      iVar5 = (**(code **)(*param_1 + 0x60))(param_4,param_5 - local_10,uVar4);
      if (param_6 == 0) {
        iVar6 = *param_3;
      }
      else if (param_6 == 1) {
        iVar6 = (**(code **)(*param_1 + 0x68))(param_4,iVar5);
        iVar6 = ((uVar4 >> 1) - iVar6 / 2) + *param_3;
      }
      else if (param_6 == 2) {
        iVar6 = (**(code **)(*param_1 + 0x68))(param_4,iVar5);
        iVar6 = param_3[2] - iVar6;
      }
      (**(code **)(*param_1 + 0x78))(param_2,iVar6,local_8,param_4,iVar5,0,0,0);
      local_8 = local_8 + iVar1;
      param_4 = param_4 + iVar5;
      local_10 = local_10 + iVar5;
    }
    if (bVar2) {
      FUN_0060beeb(param_2);
      *(undefined1 *)((int)param_1 + 0x22) = 0;
    }
  }
  return 1;
}

