
undefined4
FUN_004c7a32(char *param_1,int param_2,undefined4 param_3,undefined4 *param_4,int *param_5,
            undefined4 *param_6,int *param_7)

{
  uint3 uVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_1c [5];
  char *local_8;
  
  pcVar2 = param_1;
  local_1c[4] = FUN_004aeea6();
  if (((local_1c[4] == 0) || (param_2 == 0x10)) || (param_2 == 0x20)) {
    uVar5 = 0;
  }
  else {
    uVar1 = (uint3)param_1;
    param_1 = (char *)(uint)(uVar1 & 0xffff);
    iVar7 = 0;
    if (0 < local_1c[4]) {
      local_8 = pcVar2;
      do {
        iVar6 = (int)*local_8;
        iVar4 = (int)local_8[1];
        if (param_2 == 1) {
          if (iVar6 < 1) {
            piVar8 = local_1c + iVar7 + 2;
            *piVar8 = -iVar4;
            iVar4 = iVar6;
LAB_004c7aa7:
            iVar6 = FUN_00636bef(iVar4);
            local_1c[iVar7] = iVar6;
            iVar4 = *piVar8;
            uVar5 = param_3;
            FUN_004b5717(iVar4,iVar6,param_3);
            cVar3 = FUN_004b5eb5(iVar4,iVar6,uVar5);
            if (cVar3 != '\0') {
              *(undefined1 *)((int)&param_1 + iVar7 + 2) = 1;
            }
          }
        }
        else if (iVar4 < 1) {
          piVar8 = local_1c + iVar7 + 2;
          *piVar8 = iVar6;
          goto LAB_004c7aa7;
        }
        local_8 = local_8 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_1c[4]);
    }
    if (param_1._2_1_ == '\0') {
      if (param_1._3_1_ == '\0') {
        return 0;
      }
      *param_4 = local_1c[3];
      uVar5 = 1;
      local_1c[0] = local_1c[1];
    }
    else if (param_1._3_1_ == '\0') {
      *param_4 = local_1c[2];
      uVar5 = 1;
    }
    else {
      *param_4 = local_1c[2];
      uVar5 = 2;
      *param_5 = local_1c[0];
      *param_6 = local_1c[3];
      param_5 = param_7;
      local_1c[0] = local_1c[1];
    }
    *param_5 = local_1c[0];
  }
  return uVar5;
}

