
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00513534(int *param_1,undefined4 param_2)

{
  float fVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float10 fVar9;
  undefined4 uVar10;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = (**(code **)(*(int *)param_1[0x69] + 0x58))();
  local_2c = 0;
  local_28 = (10 - iVar4) / 2;
  local_24 = param_1[9] - param_1[7];
  local_20 = param_1[10] - param_1[8];
  cVar2 = FUN_004cff80();
  if (cVar2 != '\0') {
    local_24 = param_1[0x21] - param_1[0x1f];
    local_2c = 0;
    local_20 = (param_1[0x22] - param_1[0x20]) + -5;
    local_28 = 0;
    if (*(char *)(DAT_006e486c + 100) == '\x14') {
      local_28 = 2;
    }
    else if (*(char *)(DAT_006e486c + 100) == '\x0f') {
      local_28 = 3;
    }
  }
  param_1[0x58] = 1;
  FUN_005eea5e(&local_2c);
  param_1[0x59] = 1;
  cVar2 = FUN_005e3bfd(param_2);
  local_10 = DAT_006f38bc;
  iVar4 = DAT_006f38b8;
  uVar3 = 0;
  if (cVar2 != '\0') {
    local_1c = DAT_006f38b8;
    local_18 = DAT_006f38bc;
    local_14 = __ftol();
    local_14 = local_14 + iVar4;
    local_10 = local_10 + 5;
    FUN_004ba5ac(param_1 + 7);
    uVar5 = FUN_0050c626();
    piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    local_c = (**(code **)(*piVar6 + 0x38))(uVar5 >> 0x10,uVar5 >> 8,uVar5);
    local_c = local_c & 0xffff;
    if (((uint)param_1[0x7c] <= DAT_006e5490) && (uVar5 == 0xff0000)) {
      uVar10 = 0;
      fVar9 = (float10)FUN_00513ade(0);
      uVar7 = FUN_00513857(0x405d5f,0xd10000,(float)fVar9);
      fVar9 = (float10)FUN_00513ade(uVar7);
      uVar8 = FUN_00513857(0x405d5f,0xd10000,(float)fVar9);
      FUN_0050c54c(uVar8,uVar7,uVar10);
    }
    uVar5 = FUN_0050c626();
    piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    local_8 = (**(code **)(*piVar6 + 0x38))(uVar5 >> 0x10,uVar5 >> 8,uVar5);
    local_8 = local_8 & 0xffff;
    if (((uint)param_1[0x89] <= DAT_006e5490) && (uVar5 == 0xff00)) {
      fVar1 = (float)(param_1[0x65] + 0x32) * _DAT_00667420;
      if (_DAT_0066657c <= fVar1) {
        if (_DAT_00666748 < fVar1) {
          fVar1 = 1.0;
        }
      }
      else {
        fVar1 = 0.0;
      }
      uVar8 = 500;
      uVar7 = FUN_00513857(0x405d5f,0xca39,fVar1,500);
      FUN_0050c54c(0xff00,uVar7,uVar8);
    }
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
    if (cVar2 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x40))(local_8,&local_1c,0);
      local_38 = local_18;
      local_30 = local_10;
      local_3c = local_14;
      local_34 = DAT_006f38b8 + 0x3c + param_1[7];
      (**(code **)(*(int *)param_1[0x17] + 0x40))(local_c,&local_3c,0);
      if (1 < local_34 - local_3c) {
        local_48 = local_18;
        local_40 = local_10;
        local_44 = local_14;
        local_4c = local_14 + -1;
        if (local_14 != local_4c) {
          (**(code **)(*(int *)param_1[0x17] + 0x40))(0,&local_4c,0);
        }
      }
      (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
    }
    if ((char)param_1[0x8a] != '\0') {
      for (piVar6 = (int *)(**(code **)(*param_1 + 0x18))(); piVar6 != (int *)0x0;
          piVar6 = (int *)(**(code **)(*piVar6 + 0x18))()) {
        if (piVar6[0x2d] != 0) {
          FUN_005e4a3a(0);
          FUN_005e4a3a(1);
          break;
        }
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

