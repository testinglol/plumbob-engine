
uint __thiscall FUN_005bd86a(int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_8;
  
  uVar4 = param_4;
  iVar6 = *param_1;
  local_8 = param_1[1] - iVar6;
  uVar5 = DAT_00666580;
  if (param_4 <= local_8) {
    if (param_4 == 0) {
      puVar2 = &param_3;
      if (local_8 <= param_3) {
        puVar2 = &local_8;
      }
      uVar5 = *puVar2;
    }
    else {
      param_4 = local_8 - param_4;
      piVar3 = (int *)&param_3;
      if (param_4 <= param_3) {
        piVar3 = (int *)&param_4;
      }
      uVar7 = *piVar3 + iVar6 + uVar4;
      iVar1 = param_2 + uVar4;
      param_3 = uVar7;
      if (param_2 != iVar1) {
        while (uVar4 = FUN_005bdcd0(iVar6,uVar7,param_2,iVar1,param_3), uVar4 != uVar7) {
          iVar6 = uVar4 + 1;
          param_3 = uVar4;
        }
        uVar5 = DAT_00666580;
        if (param_3 != uVar7) {
          uVar5 = param_3 - *param_1;
        }
      }
    }
  }
  return uVar5;
}

