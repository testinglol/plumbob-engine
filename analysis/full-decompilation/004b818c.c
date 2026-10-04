
undefined1
FUN_004b818c(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,char param_5,
            undefined4 param_6)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_30;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 local_5;
  
  piVar1 = param_2;
  if (DAT_006f0664 == '\0') {
    iVar3 = FUN_00582ecc();
    if (iVar3 == 0) {
      return 0;
    }
    DAT_006f0664 = '\x01';
  }
  local_5 = 1;
  if (param_3 == (int *)0x0) {
    local_30 = param_2[5];
    iVar3 = param_2[6];
    local_c = param_2[7];
    local_1c = param_2[8];
  }
  else {
    local_30 = *param_3;
    iVar3 = param_3[1];
    local_c = param_3[2];
    local_1c = param_3[3];
  }
  local_c = local_c - local_30;
  local_1c = local_1c - iVar3;
  local_10 = FUN_005a9320(local_c * local_1c * 4);
  if (local_10 == 0) {
    return 0;
  }
  cVar2 = (**(code **)(*param_2 + 0x20))(0x40);
  if (cVar2 != '\0') {
    if (param_5 != '\0') {
      FUN_004b7c9a(param_2);
    }
    uVar4 = (**(code **)(*param_2 + 0xd0))();
    iVar5 = (**(code **)(*param_2 + 0xcc))();
    param_2 = (int *)(iVar5 + (iVar3 * (uVar4 >> 1) + local_30) * 2);
    param_3 = (int *)local_10;
    if (0 < local_1c) {
      local_18 = local_1c;
      do {
        if (0 < local_c) {
          local_14 = local_c;
          _param_5 = (undefined2 *)param_2;
          iVar3 = (int)param_3 + 1;
          do {
            *(undefined1 *)(iVar3 + 2) = 0xff;
            FUN_005dfeb6(CONCAT22((short)((uint)_param_5 >> 0x10),*_param_5),iVar3 + 1,iVar3,
                         iVar3 + -1);
            _param_5 = _param_5 + 1;
            iVar3 = iVar3 + 4;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          local_14 = 0;
        }
        local_18 = local_18 + -1;
        param_3 = (int *)((int)param_3 + local_c * 4);
        param_2 = (int *)((int)param_2 + (uVar4 >> 1) * 2);
      } while (local_18 != 0);
      local_18 = 0;
    }
    iVar3 = local_1c;
    (**(code **)(*piVar1 + 0x24))(0x40);
    local_20 = local_c;
    local_1c = iVar3;
    cVar2 = FUN_004b8690(param_1,local_10,&local_20,param_4,param_6);
    if (cVar2 != '\0') goto LAB_004b82e4;
  }
  local_5 = 0;
LAB_004b82e4:
  FUN_005a9340(local_10);
  return local_5;
}

