
undefined4 __fastcall FUN_00533375(int *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  size_t sVar6;
  undefined2 *puVar7;
  int *_Str;
  undefined4 uVar8;
  undefined1 local_30 [16];
  float local_20;
  int local_1c;
  undefined2 *local_18;
  int local_14;
  uint local_10;
  int local_c;
  char local_5;
  
  param_1[0x4f] = param_1[0x4f] + 1;
  if (param_1[0x45] <= param_1[0x4f]) {
    param_1[0x4f] = param_1[0x43];
  }
  local_5 = '\x01' - (param_1[0x4f] % 10 != 0);
  FUN_00533ffc();
  FUN_00533886(DAT_006fe88c,DAT_006fe890 - DAT_006fe88c >> 4);
  FUN_00533ee8(DAT_006fe880,DAT_006fe884 - DAT_006fe880 >> 4);
  if ((param_1[0x41] - param_1[0x40]) / 0x18 != 0) {
    FUN_005340bf(0);
  }
  if (((int *)param_1[0x17] != (int *)0x0) &&
     (cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x40), cVar1 != '\0')) {
    iVar3 = (**(code **)(*(int *)param_1[0x17] + 0xcc))();
    uVar4 = (**(code **)(*(int *)param_1[0x17] + 0xd0))();
    uVar4 = uVar4 >> 1;
    local_20 = 1.0 / (float)param_1[0x50];
    local_c = 0;
    local_10 = 0;
    puVar7 = (undefined2 *)
             (iVar3 + ((param_1[0x46] + -1 + param_1[8]) * uVar4 + param_1[7] + param_1[0x4f] +
                      param_1[0x43]) * 2);
    local_18 = puVar7;
    if ((param_1[0x3e] - param_1[0x3d]) / 0x28 != 0) {
      local_14 = 0;
      do {
        if (((*(char *)((int)param_1 + 0x145) == '\0') || (local_10 == param_1[0x38])) &&
           (local_1c = __ftol(), 0 < local_1c)) {
          if (local_10 == param_1[0x38]) {
            uVar2 = 0xffff;
          }
          else {
            uVar2 = FUN_005340bf(local_10);
          }
          iVar3 = 0;
          if (0 < local_1c) {
            do {
              if (param_1[0x46] - param_1[0x44] <= local_c) break;
              iVar3 = iVar3 + 1;
              local_c = local_c + 1;
              *puVar7 = uVar2;
              puVar7 = puVar7 + -uVar4;
            } while (iVar3 < local_1c);
          }
        }
        local_10 = local_10 + 1;
        local_14 = local_14 + 0x28;
      } while (local_10 < (uint)((param_1[0x3e] - param_1[0x3d]) / 0x28));
    }
    if (local_c < param_1[0x46] - param_1[0x44]) {
      do {
        *puVar7 = 0;
        local_c = local_c + 1;
        puVar7 = puVar7 + -uVar4;
      } while (local_c < param_1[0x46] - param_1[0x44]);
    }
    if ((local_5 != '\0') &&
       (iVar3 = 0, param_1[0x46] != param_1[0x44] && -1 < param_1[0x46] - param_1[0x44])) {
      do {
        puVar7 = local_18 + uVar4 * -10;
        iVar3 = iVar3 + 10;
        *local_18 = (undefined2)DAT_006f2a64;
        local_18 = puVar7;
      } while (iVar3 < param_1[0x46] - param_1[0x44]);
    }
    (**(code **)(*(int *)param_1[0x17] + 0x24))(0x40);
  }
  _Str = param_1 + 0x54;
  if ((char)param_1[0x54] != '\0') {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
    if (cVar1 != '\0') {
      uVar8 = 0;
      iVar3 = *(int *)param_1[0x17];
      uVar5 = FUN_004df599(local_30,param_1 + 7);
      (**(code **)(iVar3 + 0x40))(0,uVar5,uVar8);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
    }
    uVar8 = 0;
    iVar3 = *(int *)param_1[0x39];
    sVar6 = _strlen((char *)_Str);
    uVar5 = FUN_004df599(local_30,param_1 + 7);
    (**(code **)(iVar3 + 0x80))(param_1[0x17],uVar5,_Str,sVar6,uVar8);
  }
  if ((char)param_1[0x51] != '\0') {
    FUN_0053365d();
    *(undefined1 *)(param_1 + 0x51) = 0;
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

