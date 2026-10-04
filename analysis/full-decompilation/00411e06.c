
undefined4 * __thiscall FUN_00411e06(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_00411f3d(*(int *)(param_1 + 0x10) + 1);
  iVar2 = FUN_00411de1(param_2);
  puVar1 = *(undefined4 **)(iVar2 * 4 + *(int *)(param_1 + 4));
  for (puVar4 = puVar1; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    iVar3 = FUN_0046f973(param_2);
    if (iVar3 == 0) goto LAB_00411e62;
  }
  puVar4 = (undefined4 *)FUN_00411ec0(param_2);
  *puVar4 = puVar1;
  *(undefined4 **)(iVar2 * 4 + *(int *)(param_1 + 4)) = puVar4;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
LAB_00411e62:
  return puVar4 + 1;
}

