
undefined4 * __thiscall
FUN_005d455a(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  param_1[0x18] = param_2;
  *param_1 = &PTR_FUN_00673644;
  puVar3 = param_1;
  for (iVar2 = 0x14; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
  }
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x23] = param_5;
  param_1[0x17] = 0;
  param_1[0x19] = 0;
  FUN_006358b0(param_1 + 0x1a,param_4);
  piVar1 = (int *)param_1[0x23];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return param_1;
}

