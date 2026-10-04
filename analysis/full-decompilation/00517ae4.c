
void __thiscall FUN_00517ae4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int local_8;
  
  uVar2 = param_2;
  piVar5 = (int *)(param_1 + 0xf8);
  local_8 = 6;
  do {
    iVar3 = *piVar5;
    cVar4 = (char)param_2;
    if (iVar3 != 0) {
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar3 + 0x154) = 0;
      }
      else {
        *(int *)(iVar3 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar3 + 0x154) = (uint)(cVar4 != '\0');
      }
      *(undefined1 *)(iVar3 + 0x16c) = 0;
    }
    piVar5 = piVar5 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  piVar5 = (int *)(param_1 + 300);
  param_2 = 3;
  do {
    iVar3 = *piVar5;
    if (iVar3 != 0) {
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar3 + 0x154) = 0;
      }
      else {
        *(int *)(iVar3 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar3 + 0x154) = (uint)(cVar4 != '\0');
      }
      *(undefined1 *)(iVar3 + 0x16c) = 0;
    }
    piVar5 = piVar5 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  piVar5 = (int *)(param_1 + 0x144);
  iVar3 = 4;
  do {
    iVar1 = *piVar5;
    if (iVar1 != 0) {
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)(cVar4 != '\0');
      }
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  piVar5 = (int *)(param_1 + 0x168);
  iVar3 = 4;
  do {
    iVar1 = *piVar5;
    if (iVar1 != 0) {
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)(cVar4 != '\0');
      }
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    }
    iVar1 = DAT_006d74f0;
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(param_1 + 0x164);
  if (DAT_006d74f0 == 0) {
    *(undefined4 *)(iVar3 + 0x154) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x154) = 1;
    *(int *)(iVar3 + 0x158) = iVar1;
  }
  *(undefined1 *)(iVar3 + 0x16c) = 0;
  if (DAT_006f3adc != 0) {
    FUN_0051ef83(uVar2);
  }
  if (((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0x88) != 0)) &&
     (*(int *)(*(int *)(DAT_006f2a08 + 0x88) + 0xf4) != 0)) {
    FUN_005043ef(uVar2);
  }
  return;
}

