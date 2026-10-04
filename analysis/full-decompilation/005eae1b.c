
undefined4 __fastcall FUN_005eae1b(int *param_1)

{
  char cVar1;
  SHORT SVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 local_28 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar6 = param_1[0x3b];
  if (iVar6 != 0) {
    local_18 = param_1[0x43];
    local_14 = param_1[0x44];
    local_10 = *(int *)(iVar6 + 0x1c) + local_18;
    local_c = *(int *)(iVar6 + 0x20) + local_14;
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar6 = param_1[0x3b];
      uVar8 = 0;
      iVar5 = *(int *)param_1[0x17];
      uVar3 = FUN_004df599(local_28,param_1 + 7);
      (**(code **)(iVar5 + 0x9c))(param_1[0x3b],iVar6 + 0x14,uVar3,uVar8);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  if (param_1[0x3f] != param_1[0x3e]) {
    (**(code **)(*param_1 + 0x1a0))
              (param_1[0x3e],param_1[0x3f] - param_1[0x3e],param_1[0x39],param_1[0x38],param_1[0x19]
               ,param_1[0x47],param_1[0x48],param_1[0x49],param_1[0x4a]);
  }
  SVar2 = GetKeyState(1);
  if (-1 < SVar2) {
    SVar2 = GetKeyState(2);
    if (-1 < SVar2) {
      local_8 = 0;
      goto LAB_005eaf10;
    }
  }
  local_8 = 1;
LAB_005eaf10:
  iVar6 = 0;
  if (0 < (param_1[0x65] - param_1[100]) / 0x28) {
    iVar5 = 0;
    do {
      piVar4 = (int *)(param_1[100] + iVar5);
      if ((piVar4[3] == 0) && ((char)piVar4[4] != '\0')) {
        if (param_1[0x35] == iVar6) {
          if (local_8 == 0) {
            iVar7 = param_1[0x37];
          }
          else {
            iVar7 = param_1[0x38];
          }
        }
        else {
          iVar7 = param_1[0x36];
        }
        (**(code **)(*param_1 + 0x1a0))
                  (*piVar4,piVar4[1] - *piVar4,param_1[0x39],iVar7,param_1[0x19],piVar4[6],piVar4[7]
                   ,piVar4[8],piVar4[9]);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x28;
    } while (iVar6 < (param_1[0x65] - param_1[100]) / 0x28);
  }
  (**(code **)(*param_1 + 0x168))();
  iVar5 = 0;
  iVar6 = (param_1[0x65] - param_1[100]) / 0x28;
  if (0 < iVar6) {
    iVar7 = 0;
    do {
      piVar4 = *(int **)(iVar7 + 0xc + param_1[100]);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x168))();
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0x28;
      iVar6 = (param_1[0x65] - param_1[100]) / 0x28;
    } while (iVar5 < iVar6);
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}

