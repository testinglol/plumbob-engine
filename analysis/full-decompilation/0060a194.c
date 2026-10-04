
undefined1 __thiscall
FUN_0060a194(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_14;
  uint local_8;
  
  local_8 = param_3[1];
  iVar7 = *param_3;
  iVar5 = (**(code **)(*param_1 + 0x58))();
  local_14 = 0;
  bVar3 = false;
  iVar1 = param_3[2];
  iVar2 = *param_3;
  if (param_5 != 0) {
    if ((char)param_1[8] == '\0') {
      cVar4 = (**(code **)(*param_2 + 0x20))(0x40);
      if (cVar4 == '\0') {
        return 0;
      }
      *(undefined1 *)(param_1 + 8) = 1;
      bVar3 = true;
    }
    if (local_8 < (uint)param_3[3]) {
      do {
        if (param_5 <= local_14) break;
        iVar6 = (**(code **)(*param_1 + 0x60))(param_4,param_5 - local_14,iVar1 - iVar2);
        if (param_6 == 0) {
          iVar7 = *param_3;
        }
        else if (param_6 == 1) {
          iVar7 = (**(code **)(*param_1 + 0x68))(param_4,iVar6);
          iVar7 = (((uint)(iVar1 - iVar2) >> 1) - iVar7 / 2) + *param_3;
        }
        else if (param_6 == 2) {
          iVar7 = (**(code **)(*param_1 + 0x68))(param_4,iVar6);
          iVar7 = param_3[2] - iVar7;
        }
        (**(code **)(*param_1 + 0x78))(param_2,iVar7,local_8,param_4,iVar6,0,0,0);
        local_8 = local_8 + iVar5;
        param_4 = param_4 + iVar6;
        local_14 = local_14 + iVar6;
      } while (local_8 < (uint)param_3[3]);
    }
    if (bVar3) {
      (**(code **)(*param_2 + 0x24))(0x40);
      *(undefined1 *)(param_1 + 8) = 0;
    }
  }
  return 1;
}

