
void __thiscall
FUN_00422c62(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_18 = 0;
  local_14 = 0;
  iVar1 = param_2[1];
  iVar2 = *param_2;
  local_c = *(int *)(param_1 + 400);
  if (local_c == 0) {
    local_c = param_1;
  }
  local_5 = FUN_00422665(param_1 + 0xf4);
  piVar8 = (int *)FUN_00422055(*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1a4));
  iVar3 = *piVar8;
  iVar4 = piVar8[1];
  iVar5 = *(int *)(param_1 + 0x1a8);
  iVar9 = local_c;
  for (iVar6 = local_c; local_c = iVar9, iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x18c)) {
    local_18 = iVar2 - iVar3;
    local_14 = iVar1 - iVar4;
    piVar8 = (int *)FUN_00422055(*(undefined4 *)(iVar6 + 0x1a0),*(undefined4 *)(iVar6 + 0x1a4));
    local_14 = local_14 + piVar8[1];
    local_18 = local_18 + *piVar8;
    local_10 = *(int *)(iVar6 + 0x1a8) + (param_3 - iVar5);
    cVar7 = FUN_00422665(param_2);
    if (cVar7 == '\0') {
      FUN_004333ef(&local_18,local_10,param_4,param_5,param_6);
    }
    else {
      FUN_004331d4(param_6);
    }
    iVar9 = local_c;
  }
  for (; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x18c)) {
    FUN_00422d79(9,0,0);
  }
  if ((local_5 != '\0') && ((char)param_6 != '\0')) {
    FUN_0044756e(param_1);
  }
  return;
}

