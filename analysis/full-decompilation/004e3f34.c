
undefined4 __thiscall FUN_004e3f34(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined **local_17c [3];
  undefined1 local_170 [256];
  undefined1 local_70 [4];
  undefined2 local_6c;
  undefined1 local_6a;
  undefined1 local_69;
  int local_64;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar4 = param_1 + 0x6c;
  cVar1 = (*(byte *)(param_1 + 0x73) >> 6 & 2) + (*(byte *)(param_1 + 0x73) & 1);
  local_1c = iVar4;
  local_18 = param_1;
  if (cVar1 == '\0') {
    uVar9 = 1;
LAB_004e3f6c:
    FUN_004e4153(uVar9);
  }
  else if (cVar1 == '\x02') {
    uVar9 = 3;
    goto LAB_004e3f6c;
  }
  local_10 = FUN_0043ac6a();
  local_14 = 0;
  local_8 = 0;
  piVar2 = local_c;
  if (0 < local_10) {
    do {
      piVar2 = (int *)FUN_0043ad1f(local_8);
      local_c = piVar2;
      if (*piVar2 != local_14) {
        local_14 = *piVar2;
        FUN_0046f824(local_170,0,0x100);
        local_17c[0] = &PTR_FUN_00666524;
        FUN_00457f7a(local_17c);
        iVar3 = FUN_0046f973(param_1 + 8);
        if (iVar3 == 0) break;
      }
      local_8 = local_8 + 1;
    } while (local_8 < local_10);
  }
  if (local_8 == local_10) {
    return 0;
  }
  if ((*(int *)(param_3 + 0x30) == 0) ||
     ((*(int *)(param_3 + 0x88) - *(int *)(param_3 + 0x84) & 0xfffffffcU) == 0)) {
    FUN_0044470e(piVar2,iVar4);
    return 1;
  }
  _memset(local_70,0,0x24);
  local_64 = piVar2[3];
  uVar9 = FUN_0045741b();
  iVar4 = FUN_00440914(uVar9);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_3 + 0x30);
    if (iVar4 != 0) {
      do {
        iVar3 = FUN_004573f9();
        iVar5 = FUN_004573f9();
        if (iVar3 == iVar5) break;
        iVar4 = *(int *)(iVar4 + 0xe0);
      } while (iVar4 != 0);
      if (iVar4 != 0) goto LAB_004e408f;
    }
    iVar4 = *(int *)(param_3 + 0x30);
  }
LAB_004e408f:
  local_6c = *(undefined2 *)(iVar4 + 0xf0);
  piVar2 = *(int **)(param_3 + 0x88);
  local_69 = 4;
  local_6a = 0x1c;
  piVar7 = piVar2;
  for (piVar8 = *(int **)(param_3 + 0x84); piVar8 != piVar2; piVar8 = piVar8 + 1) {
    if ((*(short *)(*piVar8 + 0x606) != 0) && (piVar7 = piVar8, *(short *)(*piVar8 + 0x5fc) != 0)) {
      if (piVar8 != piVar2) goto LAB_004e40df;
      break;
    }
  }
  piVar8 = piVar7;
  if (piVar7 == piVar2) {
    piVar8 = *(int **)(param_3 + 0x84);
  }
LAB_004e40df:
  sVar6 = _strlen(s__Neighbor_006c4044);
  iVar4 = FUN_004558e0(s__Neighbor_006c4044,0,sVar6);
  if (iVar4 == -1) {
    sVar6 = _strlen(s__Family_006c4060);
    iVar4 = FUN_004558e0(s__Family_006c4060,0,sVar6);
    if (iVar4 == -1) goto LAB_004e412f;
  }
  local_6c = *(undefined2 *)(*piVar8 + 0x5ca);
LAB_004e412f:
  FUN_004443eb(*piVar8,local_70,local_1c);
  return 1;
}

