
void __fastcall FUN_00525664(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar2 = (**(code **)(*param_1 + 0x184))();
  if (iVar2 == 0) {
    return;
  }
  iVar2 = (**(code **)(*param_1 + 0x184))();
  if (*(int *)(iVar2 + 0x5c) == 0) {
    return;
  }
  FUN_0052587a(&local_14);
  if (local_10 < 0) {
    return;
  }
  if (local_14 < 0) {
    return;
  }
  uVar3 = FUN_005259ab(param_1[0x38]);
  uVar3 = FUN_00525a55(uVar3);
  uVar3 = (**(code **)(*param_1 + 0x184))(&local_14,uVar3);
  FUN_004b32e9(uVar3);
  piVar4 = DAT_006f2aa4;
  piVar5 = param_1 + 0x3a;
  if (param_1[0x3b] == *piVar5) {
LAB_0052579f:
    if ((char)param_1[0x3e] == '\0') goto LAB_00525826;
  }
  else if ((char)param_1[0x3e] == '\0') {
    local_8 = -param_1[0x20];
    local_1c = (param_1[0x21] - param_1[0x1f]) + -5;
    local_24 = 5;
    local_20 = 0;
    local_18 = param_1[0x22] + local_8;
    local_c = DAT_006f2aa4;
    local_8 = (**(code **)(*DAT_006f2aa4 + 100))
                        (*piVar5,param_1[0x3b] - *piVar5,(param_1[0x21] - param_1[0x1f]) + -10);
    local_18 = local_18 + -5;
    iVar2 = (**(code **)(*piVar4 + 0x58))();
    local_20 = local_18 - iVar2 * local_8;
    iVar2 = *piVar4;
    uVar3 = (**(code **)(*param_1 + 0x184))(&local_24,*piVar5,param_1[0x3b] - *piVar5,0);
    (**(code **)(iVar2 + 0x80))(uVar3);
    goto LAB_0052579f;
  }
  piVar4 = (int *)(**(code **)(*param_1 + 0x184))();
  local_c = (int *)(**(code **)(*piVar4 + 0x94))();
  if (local_c != (int *)0x0) {
    uVar3 = FUN_004cfdf2();
    piVar4 = local_c;
    FUN_00410977(local_c,uVar3);
    FUN_004ed86c(piVar4,uVar3);
    if (param_1[0x3b] != *piVar5) {
      iVar2 = *piVar5;
      FUN_00410977(iVar2);
      FUN_004ed980(iVar2);
    }
  }
  FUN_00406466(0,DAT_00666580);
  *(undefined1 *)(param_1 + 0x3e) = 0;
LAB_00525826:
  piVar5 = (int *)(**(code **)(*param_1 + 0x184))();
  cVar1 = (**(code **)(*piVar5 + 0x20))(8);
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*param_1 + 0x184))();
    piVar5 = (int *)(**(code **)(*param_1 + 0x184))();
    (**(code **)(*piVar5 + 0x50))(iVar2 + 0x14,0,2);
    piVar5 = (int *)(**(code **)(*param_1 + 0x184))();
    (**(code **)(*piVar5 + 0x24))(8);
  }
  return;
}

