
int FUN_0052777c(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 < 1) || (2 < param_1)) {
    puVar3 = (undefined4 *)&DAT_006f3b30;
  }
  else {
    puVar3 = &DAT_006f3b24 + param_1 * 3;
  }
  piVar1 = (int *)FUN_005e7743();
  iVar2 = (**(code **)(*piVar1 + 0x24))(param_1,puVar3);
  if (iVar2 != 0) {
    FUN_005e4b90(1);
  }
  return iVar2;
}

