
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a83dc(int param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _DAT_006e54a8 = _DAT_006e54a8 + 1;
  if (*(char *)(param_1 + 0x179) == '\0') {
    FUN_004aa1b9(&local_8,&local_c,&local_10,&local_14);
    piVar2 = &param_2;
    if (param_2 <= local_8) {
      piVar2 = &local_8;
    }
    param_2 = *piVar2;
    piVar2 = &param_2;
    if (local_c <= param_2) {
      piVar2 = &local_c;
    }
    uVar3 = *piVar2 + 1U & 0xfffffffc;
    piVar2 = &param_3;
    if (param_3 <= local_10) {
      piVar2 = &local_10;
    }
    param_3 = *piVar2;
    piVar2 = &param_3;
    if (local_14 <= param_3) {
      piVar2 = &local_14;
    }
    iVar1 = *piVar2;
    if (*(char *)(param_1 + 0x178) != '\0') {
      *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + (uVar3 - DAT_006f0080);
      *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + (iVar1 - DAT_006f0084);
      if (param_4 == '\0') {
        return;
      }
      if ((*(int *)(param_1 + 0x170) == 0) && (*(int *)(param_1 + 0x174) == 0)) {
        return;
      }
      DAT_006f0080 = DAT_006f0080 + *(int *)(param_1 + 0x170);
      DAT_006f0084 = DAT_006f0084 + *(int *)(param_1 + 0x174);
      *(undefined4 *)(param_1 + 0x170) = 0;
      *(undefined4 *)(param_1 + 0x174) = 0;
      uVar3 = DAT_006f0080;
      iVar1 = DAT_006f0084;
    }
    DAT_006f0084 = iVar1;
    DAT_006f0080 = uVar3;
    FUN_004a7d36();
  }
  return;
}

