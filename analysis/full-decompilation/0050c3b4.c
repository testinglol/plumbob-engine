
undefined4 __fastcall FUN_0050c3b4(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((char)param_1[0x37] != '\0') {
    uVar3 = 4;
    local_28 = 0;
    local_24 = 0;
    local_20 = 3;
    local_1c = 4;
    if (*(char *)((int)param_1 + 0xde) < '\0') {
      local_10 = param_1[0x38] + 0x10;
      local_c = param_1[0x39];
      FUN_004ba5ac(&local_10);
      uVar3 = 0xfffffffc;
    }
    else {
      FUN_004ba5ac(param_1 + 0x3a);
    }
    local_14 = 0;
    local_18 = uVar3;
    FUN_004ba5ac(param_1 + 7);
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x40);
    if (cVar1 != '\0') {
      local_8 = 0;
      local_c = 5;
      piVar5 = param_1 + 0x3d;
      do {
        uVar2 = FUN_0050c626();
        uVar3 = 0xff0000;
        if (uVar2 == 0xff0000) {
          uVar6 = 0xd10000;
LAB_0050c498:
          FUN_0050c54c(uVar3,uVar6,500);
        }
        else {
          uVar3 = 0xff00;
          if (uVar2 == 0xff00) {
            uVar6 = 0xca39;
            goto LAB_0050c498;
          }
        }
        piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        uVar2 = (**(code **)(*piVar4 + 0x38))(uVar2 >> 0x10,uVar2 >> 8,uVar2);
        FUN_0050c8d2(&local_28,
                     CONCAT31((int3)((uVar2 & 0xffff) >> 8),*(char *)((int)param_1 + 0xde) < '\0'),
                     uVar2 & 0xffff);
        FUN_00422698();
        FUN_004ba5ac(&local_18);
        if ((uint)piVar5[0xc] <= DAT_006e5490) {
          local_8 = local_8 + 1;
        }
        piVar5 = piVar5 + 0xd;
        local_c = local_c + -1;
      } while (local_c != 0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x40);
      if (local_8 == 5) {
        if (*(char *)((int)param_1 + 0xdd) != '\0') {
          *(undefined1 *)(param_1 + 0x37) = 0;
          *(undefined1 *)((int)param_1 + 0xde) = 0;
          *(undefined1 *)((int)param_1 + 0xdd) = 0;
        }
      }
      else {
        (**(code **)(*param_1 + 0x168))();
      }
    }
  }
  return 1;
}

