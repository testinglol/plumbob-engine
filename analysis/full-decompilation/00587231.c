
void FUN_00587231(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined *puVar8;
  int local_1c [2];
  int local_14 [2];
  undefined4 *local_c;
  int local_8;
  
  iVar1 = DAT_006e4f10;
  local_c = (undefined4 *)(DAT_006e4f10 + 0x18);
  for (piVar5 = *(int **)(DAT_006e4f10 + 0x18); piVar5 != *(int **)(iVar1 + 0x1c);
      piVar5 = piVar5 + 1) {
    if ((int *)*piVar5 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(*(int *)*piVar5 + 0x2c))();
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))();
    }
  }
  local_8 = 0;
  FUN_00580a92(local_14);
  while (iVar1 = local_14[0], local_14[0] != 0) {
    if (*(char *)(local_14[0] + 0x30) == '\0') {
      FUN_005a385a();
    }
    iVar1 = *(int *)(iVar1 + 0x34);
    iVar4 = FUN_005979cb();
    if (iVar4 != 0) {
      uVar7 = *(undefined4 *)(iVar1 + 4);
      local_8 = local_8 + 1;
      puVar8 = &DAT_006c08dc;
      pcVar6 = s_active_practice_s__on_skill_006d0660;
      FUN_005bc69b(iVar4);
      FUN_005bc69b(pcVar6);
      FUN_005bc69b(uVar7);
      FUN_005bc69b(puVar8);
    }
    FUN_0058757c();
  }
  FUN_00580a92(local_1c);
  while (iVar1 = local_1c[0], local_1c[0] != 0) {
    if (*(char *)(local_1c[0] + 0x30) == '\0') {
      FUN_005a3762();
    }
    iVar1 = *(int *)(iVar1 + 0x34);
    iVar4 = FUN_005955b1();
    if (iVar4 != 0) {
      uVar7 = *(undefined4 *)(iVar1 + 4);
      puVar8 = &DAT_006c08dc;
      pcVar6 = s_active_dressing_s__on_suit_006d0640;
      FUN_005bc69b(iVar4);
      FUN_005bc69b(pcVar6);
      FUN_005bc69b(uVar7);
      FUN_005bc69b(puVar8);
    }
    FUN_0040fe8a();
  }
  FUN_005a0377();
  FUN_005a0341();
  FUN_0059f6cf(DAT_006f6b70,0,0,0);
  FUN_005a009d(DAT_006f6b6c);
  puVar2 = local_c;
  for (piVar5 = (int *)*local_c; piVar5 != (int *)puVar2[1]; piVar5 = piVar5 + 1) {
    if ((int *)*piVar5 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(*(int *)*piVar5 + 0x2c))();
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))();
    }
  }
  return;
}

