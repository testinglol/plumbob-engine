
void __thiscall FUN_005763bc(int param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  uVar1 = *param_3;
  uVar3 = uVar1 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2);
  iVar2 = *(int *)(param_1 + 4);
  for (puVar5 = *(undefined4 **)(iVar2 + uVar3 * 4); puVar5 != (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar5) {
    if (puVar5[1] == uVar1) {
      puVar6 = (undefined4 *)*puVar5;
      goto LAB_005763eb;
    }
  }
  uVar4 = 0;
  puVar5 = (undefined4 *)0x0;
  goto LAB_00576439;
LAB_005763eb:
  if (puVar6 == (undefined4 *)0x0) goto LAB_00576405;
  if (puVar6[1] != uVar1) {
    *param_2 = puVar5;
    param_2[1] = param_1;
    param_2[2] = puVar6;
    goto LAB_00576444;
  }
  puVar6 = (undefined4 *)*puVar6;
  goto LAB_005763eb;
LAB_00576405:
  uVar3 = uVar3 + 1;
  if (uVar3 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) {
    piVar7 = (int *)(iVar2 + uVar3 * 4);
    do {
      if (*piVar7 != 0) {
        uVar4 = *(undefined4 *)(iVar2 + uVar3 * 4);
        goto LAB_00576439;
      }
      uVar3 = uVar3 + 1;
      piVar7 = piVar7 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
  }
  uVar4 = 0;
LAB_00576439:
  *param_2 = puVar5;
  param_2[1] = param_1;
  param_2[2] = uVar4;
LAB_00576444:
  param_2[3] = param_1;
  return;
}

