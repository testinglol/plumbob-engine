
void __thiscall FUN_004a7a9c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  if (*(char *)(param_1 + 0x17a) == '\0') {
    iVar2 = *(int *)(param_1 + 0x170) + DAT_006f0080;
    local_c = *(int *)(param_1 + 0x174) + DAT_006f0084;
  }
  else {
    iVar2 = FUN_004c9cba();
    local_c = FUN_004c9cf3();
  }
  uVar1 = iVar2 + param_2;
  param_2 = local_c + param_3;
  local_8 = uVar1;
  FUN_004aa1b9(&local_10,&local_14,&local_18,&local_1c);
  puVar3 = &local_8;
  if ((int)uVar1 <= (int)local_10) {
    puVar3 = &local_10;
  }
  local_8 = *puVar3;
  puVar4 = &local_8;
  if ((int)local_14 <= (int)*puVar3) {
    puVar4 = &local_14;
  }
  local_8 = *puVar4 + 1 & 0xfffffffc;
  piVar5 = &param_2;
  if (param_2 <= local_18) {
    piVar5 = &local_18;
  }
  piVar6 = &param_2;
  if (local_1c <= *piVar5) {
    piVar6 = &local_1c;
  }
  param_2 = *piVar6;
  FUN_004924ae(1);
  uVar7 = __ftol();
  FUN_004c9d77(uVar7);
  FUN_004c9b93(iVar2,local_8,local_c,param_2,1);
  *(undefined1 *)(param_1 + 0x17a) = 1;
  FUN_004b050c();
  return;
}

