
undefined4 __thiscall FUN_005d99a9(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  DWORD DVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined1 local_c [4];
  int local_8;
  
  puVar7 = param_3;
  piVar2 = param_2;
  local_1c = *param_3;
  local_18 = param_3[1];
  local_14 = param_3[2];
  local_10 = (int *)param_3[3];
  if (param_2 == *(int **)(param_1 + 0x174)) {
    return 0;
  }
  param_3 = (undefined4 *)((uint)param_3 & 0xffffff);
  if (*(int **)(param_1 + 0x174) != (int *)0x0) {
    param_3 = (undefined4 *)0x0;
    param_2 = (int *)0x0;
    local_1c = 0x19;
    local_10 = piVar2;
    FUN_00436feb(&param_3,&param_2);
    local_18 = local_18 - (int)param_3;
    local_14 = local_14 - (int)param_2;
    (**(code **)**(undefined4 **)(param_1 + 0x174))(&local_1c);
    uVar3 = (**(code **)(**(int **)(param_1 + 0x174) + 0x8c))(0x400);
    param_3 = (undefined4 *)CONCAT13(uVar3,param_3._0_3_);
  }
  *(undefined1 *)(param_1 + 0x1a0) = 0;
  if (piVar2 != (int *)0x0) {
    local_1c = *puVar7;
    param_2 = (int *)0x0;
    local_18 = puVar7[1];
    local_14 = puVar7[2];
    local_10 = (int *)puVar7[3];
    local_8 = 0;
    FUN_00436feb(&param_2,&local_8);
    local_18 = local_18 - (int)param_2;
    local_14 = local_14 - local_8;
    local_10 = *(int **)(param_1 + 0x174);
    local_1c = 0x18;
    (**(code **)*piVar2)(&local_1c);
    cVar4 = (**(code **)(*piVar2 + 0x8c))(1);
    if (cVar4 != '\0') {
      uVar3 = (**(code **)(*piVar2 + 0x8c))(0x400);
      *(undefined1 *)(param_1 + 0x1a0) = uVar3;
    }
  }
  iVar1 = *(int *)(param_1 + 0x178);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x178) = 1;
LAB_005d9b34:
    if ((param_3._3_1_ == '\0') || (*(char *)(param_1 + 0x1a1) == '\0')) goto LAB_005d9b55;
  }
  else {
    if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0x178) = 3;
      DVar5 = timeGetTime();
      *(DWORD *)(param_1 + 0x17c) = DVar5;
      goto LAB_005d9b34;
    }
    if (iVar1 != 3) goto LAB_005d9b34;
    if (*(char *)(param_1 + 0x1a0) != '\0') {
      *(undefined4 *)(param_1 + 0x178) = 2;
      DVar5 = timeGetTime();
      *(DWORD *)(param_1 + 0x180) = DVar5;
      goto LAB_005d9b34;
    }
    DVar5 = timeGetTime();
    if ((piVar2 != (int *)0x0) && ((int)(DVar5 - *(int *)(param_1 + 0x17c)) <= piVar2[0x29]))
    goto LAB_005d9b34;
    *(undefined4 *)(param_1 + 0x178) = 1;
    DVar5 = timeGetTime();
    *(DWORD *)(param_1 + 0x17c) = DVar5;
  }
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x170))(param_1 + 0x1a4);
LAB_005d9b55:
  *(int **)(param_1 + 0x174) = piVar2;
  DVar5 = timeGetTime();
  *(DWORD *)(param_1 + 0x17c) = DVar5;
  cVar4 = FUN_005da398(*(undefined4 *)(param_1 + 0x18c));
  if (cVar4 == '\0') {
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x18c) + 0xc0))(*(int **)(param_1 + 0x18c) + 0x1f,0);
    (**(code **)(**(int **)(param_1 + 0x18c) + 8))();
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined1 *)(param_1 + 0x1a1) = 0;
  }
  if (*(char *)(param_1 + 0x1a0) != '\0') {
    uVar6 = (**(code **)(**(int **)(param_1 + 0x174) + 0xb8))();
    *(undefined1 *)(param_1 + 0x1a1) = 0;
    *(undefined4 *)(param_1 + 0x18c) = uVar6;
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    FUN_005ddfdc(1);
    puVar7 = (undefined4 *)
             (**(code **)(**(int **)(param_1 + 0x174) + 0xbc))
                       (local_c,*(undefined4 *)(param_1 + 0x18c),0);
    *(undefined4 *)(param_1 + 0x184) = *puVar7;
    *(undefined4 *)(param_1 + 0x188) = puVar7[1];
  }
  return 1;
}

