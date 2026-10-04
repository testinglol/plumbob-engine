
void __thiscall FUN_0051f264(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined1 local_2c [16];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  cVar2 = FUN_004cff80();
  if (cVar2 == '\0') {
    local_1c = DAT_006f3ab8;
    local_18 = DAT_006f3abc;
    local_14 = DAT_006f3ac0;
    local_10 = DAT_006f3ac4;
  }
  else {
    local_1c = DAT_006f3aa8;
    local_18 = DAT_006f3aac;
    local_14 = DAT_006f3ab0;
    local_10 = DAT_006f3ab4;
  }
  piVar3 = (int *)FUN_005caed9();
  if (*piVar3 == 0x400) {
    local_14 = local_14 + 0xe0;
  }
  iVar1 = *(int *)(param_1 + 0x158);
  if (((iVar1 == 0) || (*(char *)(iVar1 + 0xe0) == '\0')) ||
     (iVar1 = *(int *)(iVar1 + 0x10c), iVar1 == 0)) goto LAB_0051f45c;
  if (iVar1 == *(int *)(param_1 + 0x2f8)) {
    if (((DAT_006f3a10 <= param_2) && (DAT_006f3a14 <= param_3)) &&
       (iVar1 = DAT_006f3a1c, param_2 < DAT_006f3a18)) {
joined_r0x0051f44e:
      if (param_3 < iVar1) goto LAB_0051f45c;
    }
  }
  else if (*(int *)(iVar1 + 0x14) == 0) {
    if (iVar1 != *(int *)(param_1 + 0x1c8)) goto LAB_0051f45c;
    local_c = DAT_006f3a80;
    local_8 = 0;
    piVar3 = (int *)FUN_004e84f4(local_2c,&local_1c);
    if (((*piVar3 <= param_2) && (piVar3[1] <= param_3)) && (param_2 < piVar3[2])) {
      iVar1 = piVar3[3];
      goto joined_r0x0051f44e;
    }
  }
  else {
    for (piVar3 = *(int **)(param_1 + 0xf0); piVar3 != *(int **)(param_1 + 0xf4);
        piVar3 = piVar3 + 1) {
      if (*piVar3 == *(int *)(iVar1 + 0x14)) {
        if (piVar3 != *(int **)(param_1 + 0xf4)) {
          iVar1 = **(int **)(param_1 + 0xf0);
          if (((param_2 < *(int *)(iVar1 + 0x7c)) || (param_3 < *(int *)(iVar1 + 0x80))) ||
             ((*(int *)(iVar1 + 0x84) * 4 + *(int *)(iVar1 + 0x7c) * -3 <= param_2 ||
              (*(int *)(iVar1 + 0x88) * 2 - *(int *)(iVar1 + 0x80) <= param_3)))) goto LAB_0051f457;
          goto LAB_0051f45c;
        }
        break;
      }
    }
    cVar2 = FUN_004cff80();
    if (cVar2 == '\0') {
      local_c = DAT_006f3a80;
    }
    else {
      local_c = DAT_006f3a78;
    }
    local_8 = 0;
    piVar3 = (int *)FUN_004e84f4(local_2c,&local_1c);
    if ((((*piVar3 <= param_2) && (piVar3[1] <= param_3)) &&
        ((param_2 < piVar3[2] && (param_3 < piVar3[3])))) || (*(int *)(param_1 + 0x158) == 0))
    goto LAB_0051f45c;
  }
LAB_0051f457:
  FUN_0050fc0a(0);
LAB_0051f45c:
  FUN_005dd854(param_2,param_3,param_4);
  return;
}

