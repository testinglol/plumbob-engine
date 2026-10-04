
void __fastcall FUN_005c5720(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00661412;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_0067344c;
  puVar5 = (undefined4 *)param_1[10];
  local_4 = 5;
  puVar6 = param_1;
  if (puVar5 != (undefined4 *)param_1[0xb]) {
    do {
      FUN_006321f0(*puVar5);
      puVar5 = puVar5 + 1;
    } while (puVar5 != (undefined4 *)param_1[0xb]);
  }
  iVar4 = param_1[0xb];
  iVar1 = param_1[10];
  FUN_00406200(iVar4,iVar4,iVar1,puVar6,0);
  param_1[0xb] = param_1[0xb] + (iVar4 - iVar1 >> 2) * -4;
  piVar2 = (int *)param_1[0xd];
  local_4._0_1_ = 3;
  iVar4 = (param_1[0xf] - (int)piVar2) / 0x18;
  if (iVar4 != 0) {
    uVar3 = iVar4 * 0x18;
    if (uVar3 < 0x81) {
      FUN_004017b8();
      *piVar2 = *(int *)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4);
      *(int **)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4) = piVar2;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar2);
    }
  }
  piVar2 = (int *)param_1[10];
  local_4._0_1_ = 2;
  iVar4 = param_1[0xc] - (int)piVar2 >> 2;
  if (iVar4 != 0) {
    uVar3 = iVar4 * 4;
    if (uVar3 < 0x81) {
      FUN_004017b8();
      *piVar2 = *(int *)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4);
      *(int **)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4) = piVar2;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar2);
    }
  }
  local_4._0_1_ = 1;
  iVar4 = (int)(param_1[9] - param_1[7]) >> 4;
  if (iVar4 != 0) {
    FUN_0040189d(param_1[7],iVar4 << 4);
  }
  piVar2 = (int *)param_1[4];
  local_4 = (uint)local_4._1_3_ << 8;
  iVar4 = param_1[6] - (int)piVar2 >> 3;
  if (iVar4 != 0) {
    uVar3 = iVar4 * 8;
    if (uVar3 < 0x81) {
      FUN_004017b8();
      *piVar2 = *(int *)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4);
      *(int **)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4) = piVar2;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar2);
    }
  }
  iVar4 = param_1[1];
  iVar1 = (param_1[3] - iVar4) / 0xc;
  local_4 = 0xffffffff;
  if (iVar1 != 0) {
    FUN_0040189d(iVar4,iVar1 * 0xc,puVar6,iVar4);
  }
  ExceptionList = local_c;
  return;
}

