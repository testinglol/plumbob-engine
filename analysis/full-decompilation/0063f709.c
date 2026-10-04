
undefined4 FUN_0063f709(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    uVar2 = FUN_0063e2e0();
    return uVar2;
  }
  if ((DAT_00703bb8 != (code *)0x0) && (iVar3 = FUN_0064693b(DAT_00703bb8), iVar3 != 0)) {
    uVar2 = (*DAT_00703bb8)(param_1);
    return uVar2;
  }
  return 0;
}

