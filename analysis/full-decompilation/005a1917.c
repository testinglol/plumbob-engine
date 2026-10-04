
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_005a1917(int param_1,char param_2,char param_3,char param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_2 == '\0') && (param_3 == '\0')) && (param_4 == '\0')) {
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      _param_4 = 0;
      iVar5 = piVar2[0x18] - piVar2[0x17] >> 2;
      local_c = iVar5;
      if (0 < iVar5) {
        do {
          piVar2 = (int *)FUN_006359f2(*(undefined4 *)
                                        (*(int *)(*(int *)(param_1 + 0xc) + 0x5c) + _param_4 * 4),0,
                                       &RenderObject::RTTI_Type_Descriptor,
                                       &RenderMesh::RTTI_Type_Descriptor,0);
          if (piVar2 != (int *)0x0) {
            uVar3 = FUN_005d14f7();
            FUN_005d14ea(uVar3);
            piVar2[0x31] = piVar2[0x31] & 0xfffffffd;
            piVar4 = piVar2 + 0x3c;
            piVar1 = piVar2 + 0x3b;
            piVar2 = piVar2 + 0x3b;
            _param_2 = 0;
            iVar6 = *piVar4 - *piVar1 >> 2;
            iVar5 = local_c;
            if (0 < iVar6) {
              do {
                piVar4 = (int *)FUN_005a1c48(_param_2);
                piVar2 = (int *)0x0;
                if (piVar4 != (int *)0x0) {
                  FUN_005d4796(local_64);
                  local_50 = 0x3f800000;
                  local_4c = 0x3f800000;
                  local_48 = 0x3f800000;
                  local_44 = 0x3f800000;
                  local_60 = 0x3f800000;
                  local_5c = 0x3f800000;
                  local_58 = 0x3f800000;
                  local_54 = 0x3f800000;
                  local_30 = 0;
                  local_2c = 0;
                  local_28 = 0;
                  local_24 = 0;
                  local_40 = 0;
                  local_3c = 0;
                  local_38 = 0;
                  local_34 = 0;
                  FUN_005d4701(local_64);
                  piVar2 = (int *)(**(code **)(*piVar4 + 8))();
                }
                _param_2 = _param_2 + 1;
                iVar5 = local_c;
              } while (_param_2 < iVar6);
            }
          }
          _param_4 = _param_4 + 1;
        } while (_param_4 < iVar5);
      }
    }
    *(undefined1 *)(param_1 + 0xac) = 0;
    *(undefined1 *)(param_1 + 0xad) = 0;
    *(undefined1 *)(param_1 + 0xae) = 0;
  }
  else {
    *(char *)(param_1 + 0xac) = param_2;
    piVar2 = *(int **)(param_1 + 0xc);
    *(char *)(param_1 + 0xad) = param_3;
    *(char *)(param_1 + 0xae) = param_4;
    if (piVar2 != (int *)0x0) {
      local_c = 0;
      iVar5 = piVar2[0x18] - piVar2[0x17] >> 2;
      local_14 = iVar5;
      if (0 < iVar5) {
        do {
          piVar2 = (int *)FUN_006359f2(*(undefined4 *)
                                        (*(int *)(*(int *)(param_1 + 0xc) + 0x5c) + local_c * 4),0,
                                       &RenderObject::RTTI_Type_Descriptor,
                                       &RenderMesh::RTTI_Type_Descriptor,0);
          if (piVar2 != (int *)0x0) {
            iVar5 = FUN_005d14e3();
            if (iVar5 == 0) {
              FUN_005d14ea(1);
            }
            iVar5 = FUN_005d14e3();
            if ((iVar5 == 2) &&
               ((*(char *)(param_1 + 0xac) != '\0' || (*(char *)(param_1 + 0xad) != '\0')))) {
              piVar2[0x31] = piVar2[0x31] | 2;
            }
            else {
              piVar2[0x31] = piVar2[0x31] & 0xfffffffd;
            }
            piVar4 = piVar2 + 0x3c;
            piVar2 = piVar2 + 0x3b;
            local_8 = 0;
            iVar6 = *piVar4 - *piVar2 >> 2;
            iVar5 = local_14;
            if (0 < iVar6) {
              do {
                local_10 = FUN_005a1c48(local_8);
                piVar2 = (int *)0x0;
                if (local_10 != 0) {
                  FUN_005d4796(local_64);
                  local_60 = _DAT_006721a4;
                  local_54 = _DAT_0067219c;
                  if (*(char *)(param_1 + 0xac) == '\0') {
                    if (*(char *)(param_1 + 0xae) == '\0') {
                      if (*(char *)(param_1 + 0xad) == '\0') {
                        local_60 = 0x3f800000;
                        _param_3 = 0x3f800000;
                        _param_4 = 0x3f800000;
                        local_54 = 0x3f800000;
                      }
                      else {
                        _param_3 = _DAT_00672198;
                        _param_4 = 0x3f800000;
                        local_60 = _DAT_00672198;
                      }
                    }
                    else {
                      _param_3 = 0x3f800000;
                      _param_4 = _DAT_0067219c;
                    }
                  }
                  else {
                    _param_3 = 0x3f800000;
                    _param_4 = _DAT_006721a0;
                  }
                  local_28 = _param_4;
                  local_3c = _param_3;
                  local_38 = _param_4;
                  local_5c = _param_3;
                  local_58 = _param_4;
                  local_50 = local_60;
                  local_4c = _param_3;
                  local_48 = _param_4;
                  local_44 = local_54;
                  local_40 = local_60;
                  local_34 = local_54;
                  local_30 = local_60;
                  local_2c = _param_3;
                  local_24 = local_54;
                  piVar2 = (int *)FUN_005d4701(local_64);
                }
                local_8 = local_8 + 1;
                iVar5 = local_14;
              } while (local_8 < iVar6);
            }
          }
          local_c = local_c + 1;
        } while (local_c < iVar5);
      }
    }
  }
  return piVar2;
}

