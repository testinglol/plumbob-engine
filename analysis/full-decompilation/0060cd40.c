
undefined4 *
FUN_0060cd40(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_24 = 0;
  if (param_6 < 1) {
    return param_1;
  }
  local_28 = 0;
  iVar7 = param_6;
  do {
    local_20 = param_9;
    if (iVar7 <= param_9) {
      local_20 = iVar7;
    }
    local_1c = 0;
    if (0 < param_5) {
      local_2c = 0;
      iVar5 = param_5;
      do {
        iVar3 = param_8;
        if (iVar5 <= param_8) {
          iVar3 = iVar5;
        }
        puVar1 = (undefined4 *)
                 (((int)(local_2c + (local_2c >> 0x1f & 7U)) >> 3) + local_28 + param_3);
        uVar4 = (int)(iVar3 * param_7 + (iVar3 * param_7 >> 0x1f & 7U)) >> 3;
        iVar3 = local_20;
        if (0 < local_20) {
          do {
            puVar6 = puVar1;
            puVar8 = param_1;
            for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar8 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
            param_1 = (undefined4 *)((int)param_1 + param_2);
            puVar1 = (undefined4 *)((int)puVar1 + param_4);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        local_1c = local_1c + param_8;
        iVar5 = iVar5 - param_8;
        local_2c = local_2c + param_7 * param_8;
      } while (local_1c < param_5);
    }
    local_24 = local_24 + param_9;
    local_28 = local_28 + param_4 * param_9;
    iVar7 = iVar7 - param_9;
  } while (local_24 < param_6);
  return param_1;
}

