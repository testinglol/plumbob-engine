
void __thiscall FUN_004cfcfd(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_8;
  
  local_8 = DAT_006f0eb0;
  piVar3 = &local_8;
  if (DAT_006f0eb0 <= param_2) {
    piVar3 = &param_2;
  }
  param_2 = *piVar3;
  local_8 = DAT_006f0ea0;
  piVar4 = &local_8;
  if (*piVar3 <= DAT_006f0ea0) {
    piVar4 = &param_2;
  }
  iVar1 = *piVar4;
  param_2 = DAT_006f0eb4;
  piVar3 = &param_2;
  if (DAT_006f0eb4 <= param_3) {
    piVar3 = &param_3;
  }
  param_3 = *piVar3;
  param_2 = DAT_006f0ea4;
  piVar4 = &param_2;
  if (*piVar3 <= DAT_006f0ea4) {
    piVar4 = &param_3;
  }
  iVar2 = *piVar4;
  if ((iVar1 == DAT_006f0eb0) && (iVar2 == DAT_006f0eb4)) {
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  else if ((iVar1 == DAT_006f0ea8) && (iVar2 == DAT_006f0eac)) {
    *(undefined4 *)(param_1 + 0x220) = 1;
  }
  else if ((iVar1 == DAT_006f0ea0) && (iVar2 == DAT_006f0ea4)) {
    *(undefined4 *)(param_1 + 0x220) = 2;
  }
  else {
    *(undefined4 *)(param_1 + 0x220) = 3;
  }
  *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 0x20;
  *(int *)(param_1 + 0x228) = iVar1;
  *(int *)(param_1 + 0x22c) = iVar2;
  return;
}

